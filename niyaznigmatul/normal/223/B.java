import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
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
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        String t = in.next();
        int[][] next = new int[26][t.length()];
        for (int[] d : next) {
            Arrays.fill(d, Integer.MAX_VALUE);
        }
        next[t.charAt(t.length() - 1) - 'a'][t.length() - 1] = t.length() - 1;
        for (int i = t.length() - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                next[j][i] = next[j][i + 1];
            }
            next[t.charAt(i) - 'a'][i] = i;
        }
        int[] pref = new int[s.length() + 1];
        pref[0] = 0;
        for (int i = 1; i <= s.length(); i++) {
            int k = pref[i - 1];
            pref[i] = k;
            if (k < t.length() && t.charAt(k) == s.charAt(i - 1)) {
                pref[i]++;
            }
        }
        int[] suf = new int[s.length() + 1];
        suf[s.length()] = t.length();
        for (int i = s.length() - 1; i >= 0; i--) {
            int k = suf[i + 1];
            suf[i] = k;
            if (k > 0 && t.charAt(k - 1) == s.charAt(i)) {
                suf[i]--;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int left = suf[i + 1] - 1;
            int right = pref[i];
            left = Math.max(left, 0);
            if (next[s.charAt(i) - 'a'][left] > right) {
                out.println("No");
                return;
            }
        }
        out.println("Yes");
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}