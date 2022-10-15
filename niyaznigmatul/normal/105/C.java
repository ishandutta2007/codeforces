import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static class Item {
        int type;
        String name;
        int power;
        int size;

        Item(int type, String name, int power, int size) {
            this.type = type;
            this.name = name;
            this.power = power;
            this.size = size;
        }
    }

    static class Bonus {
        int type;
        int power;
        String name;
        boolean got;
        int where;

        Bonus(int type, int power, String name, int where) {
            this.type = type;
            this.power = power;
            this.name = name;
            this.where = where;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        Item[] a = new Item[n];
        final List<String> itemType = Arrays.asList("weapon", "armor", "orb");
        for (int i = 0; i < n; i++) {
            String name = in.next();
            String cl = in.next();
            int[] z = in.readIntArray(3);
            int size = in.nextInt();
            int type = itemType.indexOf(cl);
            a[i] = new Item(type, name, z[type], size);
        }
        int m = in.nextInt();
        List<Bonus>[] b = new List[3];
        for (int i = 0; i < 3; i++) {
            b[i] = new ArrayList<Bonus>();
        }
        int[] has = new int[n];
        final List<String> bonusType = Arrays.asList("gladiator", "sentry", "physician");
        for (int i = 0; i < m; i++) {
            String name = in.next();
            String cl = in.next();
            int type = bonusType.indexOf(cl);
            int bonus = in.nextInt();
            String where = in.next();
            int whereID = -1;
            for (int j = 0; j < n; j++) {
                if (a[j].name.equals(where)) {
                    has[j]++;
                    whereID = j;
                    break;
                }
            }
            b[type].add(new Bonus(type, bonus, name, whereID));
        }
        boolean canMove = false;
        for (int i = 0; i < n; i++) {
            if (has[i] < a[i].size) {
                canMove = true;
                break;
            }
        }
        for (List<Bonus> e : b) {
            Collections.sort(e, new Comparator<Bonus>() {
                public int compare(Bonus o1, Bonus o2) {
                    return o2.power - o1.power;
                }
            });
        }
        Item[] best = new Item[3];
        int[] bestCount = new int[3];
        Arrays.fill(bestCount, Integer.MIN_VALUE);
        List<Bonus>[] toPrint = new List[3];
        for (int i = 0; i < 3; i++) {
            toPrint[i] = new ArrayList<Bonus>();
        }
        if (!canMove) {
            int[] bestID = new int[3];
            for (int i = 0; i < n; i++) {
                Item e = a[i];
                int count = e.power;
                for (List<Bonus> f : b) {
                    for (Bonus z : f) {
                        if (z.where == i) {
                            count += z.type == e.type ? z.power : 0;
                        }
                    }
                }
                if (count > bestCount[e.type]) {
                    bestCount[e.type] = count;
                    best[e.type] = e;
                    bestID[e.type] = i;
                }
            }
            for (int i = 0; i < 3; i++) {
                for (List<Bonus> f : b) {
                    for (Bonus z : f) {
                        if (z.where == bestID[i]) {
                            toPrint[i].add(z);
                        }
                    }
                }
            }
        } else {
            for (Item e : a) {
                int count = e.power;
                for (int i = 0; i < b[e.type].size() && i < e.size; i++) {
                    count += b[e.type].get(i).power;
                }
                if (count > bestCount[e.type]) {
                    bestCount[e.type] = count;
                    best[e.type] = e;
                }
            }
            for (int i = 0; i < 3; i++) {
                Item e = best[i];
                for (int j = 0; j < b[i].size() && j < e.size; j++) {
                    b[i].get(j).got = true;
                    toPrint[i].add(b[i].get(j));
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; toPrint[i].size() < best[i].size && k < b[j].size(); k++) {
                        Bonus e = b[j].get(k);
                        if (e.got) {
                            continue;
                        }
                        toPrint[i].add(e);
                        e.got = true;
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            out.print(best[i].name + " " + toPrint[i].size());
            Collections.sort(toPrint[i], new Comparator<Bonus>() {
                public int compare(Bonus o1, Bonus o2) {
                    return o1.name.compareTo(o2.name);
                }
            });
            for (Bonus e : toPrint[i]) {
                out.print(" " + e.name);
            }
            out.println();
        }
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}