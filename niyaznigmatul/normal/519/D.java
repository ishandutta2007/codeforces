import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.util.Map;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static class State {
        int letter;
        long sum;

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (letter != state.letter) return false;
            if (sum != state.sum) return false;

            return true;
        }

        public int hashCode() {
            int result = letter;
            result = 31 * result + (int) (sum ^ (sum >>> 32));
            return result;
        }

        public State(int letter, long sum) {

            this.letter = letter;
            this.sum = sum;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Map<State, Integer> map = new HashMap<>();
        int[] x = new int[26];
        for (int i = 0; i < 26; i++) {
            x[i] = in.nextInt();
        }
        long sum = 0;
        String s = in.next();
        long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            State cur = new State(c, sum);
            Integer got = map.get(cur);
            if (got == null) got = 0;
            ans += got;
            sum += x[c];
            cur = new State(c, sum);
            got = map.get(cur);
            if (got == null) got = 0;
            map.put(cur, got + 1);
        }
        out.println(ans);
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


}