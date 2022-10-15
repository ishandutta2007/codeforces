import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
 * @author Niyaz Nigmatullin
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer> attack = new ArrayList<>();
        List<Integer> defence = new ArrayList<>();
        int[] have = new int[m];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            if (s.equals("ATK")) {
                attack.add(in.nextInt());
            } else {
                defence.add(in.nextInt());
            }
        }
        Collections.sort(attack);
        Collections.sort(defence);
        for (int i = 0; i < m; i++) {
            have[i] = in.nextInt();
        }
        Arrays.sort(have);
        int ans = Math.max(all(attack, defence, have), 0);
        for (int i = 1; i <= attack.size() && i <= have.length; i++) {
            ans = Math.max(onlyAttack(attack, have, i), ans);
        }
        out.println(ans);
    }

    static int onlyAttack(List<Integer> attack, int[] have, int k) {
        if (k > attack.size() || k > have.length) return Integer.MIN_VALUE;
        int n = have.length;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (attack.get(i) > have[n - k + i]) {
                return Integer.MIN_VALUE;
            }
            ans += have[n - k + i] - attack.get(i);
        }
        return ans;
    }

    static int all(List<Integer> attack, List<Integer> defence, int[] have) {
        int n = have.length;
        boolean[] was = new boolean[n];
        int ans = 0;
        for (int i : defence) {
            int id = -1;
            for (int j = 0; j < n; j++) {
                if (was[j]) continue;
                if (have[j] > i) {
                    id = j;
                    break;
                }
            }
            if (id < 0) return Integer.MIN_VALUE;
            was[id] = true;
        }
        for (int i : attack) {
            int id = -1;
            for (int j = 0; j < n; j++) {
                if (was[j]) continue;
                if (have[j] >= i) {
                    id = j;
                    break;
                }
            }
            if (id < 0) return Integer.MIN_VALUE;
            was[id] = true;
            ans += have[id] - i;
        }
        for (int i = 0; i < n; i++) {
            if (!was[i]) {
                ans += have[i];
            }
        }
        return ans;
    }

}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
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
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
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