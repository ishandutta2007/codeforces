import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Element implements Comparable<Element> {
        int cost;
        int type;
        int id;

        Element(int cost, int type, int id) {
            this.cost = cost;
            this.type = type;
            this.id = id;
        }


        public int compareTo(Element o) {
            return cost < o.cost ? 1 : cost > o.cost ? -1 : 0;
        }
    }


    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        List<Element> chairs = new ArrayList<Element>();
        List<Element> pencils = new ArrayList<Element>();
        for (int i = 0; i < n; i++) {
            int cost = in.nextInt() * 2;
            int type = in.nextInt();
            Element e = new Element(cost, type, i);
            if (type == 1) {
                chairs.add(e);
            } else {
                pencils.add(e);
            }
        }
        Collections.sort(chairs);
        Collections.sort(pencils);
        List<Element>[] add = new ArrayList[k];
        for (int i = 0; i < k; i++) {
            add[i] = new ArrayList<Element>();
        }
        int current = 0;
        for (Element e : chairs) {
            if (current == k) {
                --current;
            }
            add[current++].add(e);
        }
        if (chairs.size() < k) {
            current = chairs.size();
            for (Element e : pencils) {
                if (current == k) {
                    --current;
                }
                add[current++].add(e);
            }
        } else {
            for (Element e : pencils) {
                add[k - 1].add(e);
            }
        }
        long answer = 0;
        long profit = 0;
        for (List<Element> z : add) {
            if (z.isEmpty()) {
                throw new AssertionError();
            }
            boolean has = false;
            for (Element e : z) {
                if (e.type == 1) {
                    has = true;
                }
                answer += e.cost;
            }
            if (has) {
                long minimal = Long.MAX_VALUE;
                for (Element e : z) {
                    minimal = Math.min(e.cost, minimal);
                }
                profit += minimal >> 1;
            }
        }
        answer -= profit;
        out.println(answer / 2 + "." + ((answer & 1) == 1 ? 5 : 0));
        for (List<Element> z : add) {
            out.print(z.size());
            for (Element e : z) {
                out.print(" " + (e.id + 1));
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}