import java.io.InputStreamReader;
import java.io.IOException;
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
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        String last = "00000000";
        int[] ans = new int[n];
        for (int currentNumber = 0; currentNumber < n; currentNumber++) {
            String s = in.next();
            if (s.startsWith("?")) s = "!" + s.substring(1);
            while (s.length() < 8) s = "0" + s;
            int found = -1;
            for (int len = 7; len >= 0; len--) {
                boolean canFirst = true;
                for (int i = 0; i < len; i++) {
                    if (s.charAt(i) == last.charAt(i)) continue;
                    if (s.charAt(i) == '!' && last.charAt(i) > '0') continue;
                    if (s.charAt(i) == '?') continue;
                    canFirst = false;
                    break;
                }
                if (!canFirst) continue;
                char[] c = s.toCharArray();
                if (last.charAt(len) == '9') continue;
                if (s.charAt(len) >= '0' && s.charAt(len) <= '9' && last.charAt(len) >= s.charAt(len)) continue;
                if (s.charAt(len) == '?' || s.charAt(len) == '!') c[len] = (char) (last.charAt(len) + 1);
                for (int i = 0; i < len; i++) {
                    if (c[i] == '?' || c[i] == '!') c[i] = last.charAt(i);
                }
                for (int i = len + 1; i < c.length; i++) if (c[i] == '?') c[i] = '0';
                s = new String(c);
                found = Integer.parseInt(s);
                break;
            }
            if (found < 0) {
                out.println("NO");
                return;
            }
            last = s;
            ans[currentNumber] = found;
        }
        out.println("YES");
        for (int i : ans) {
            out.println(i);
        }
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