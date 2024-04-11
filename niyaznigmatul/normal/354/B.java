import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static Map<State, Integer> map;

    static int go(State state) {
        if (state.move == n + n - 2) return 0;
        if (map.containsKey(state)) return map.get(state);
        int ret = Integer.MIN_VALUE;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            long mask = 0;
            for (int i = 0; i < n; i++) {
                int j = state.move - i;
                if (j < 0 || j >= n) continue;
                if (!state.get(i, j)) {
                    continue;
                }
                if (i + 1 < n && c[i + 1][j] == ch) {
                    mask |= 1L << (i + 1);
                }
                if (j + 1 < n && c[i][j + 1] == ch) {
                    mask |= 1L << i;
                }
            }
            if (mask == 0) continue;
            State newState = new State(mask, state.move + 1);
            int cost = ch == 'a' ? 1 : ch == 'b' ? -1 : 0;
            if ((state.move & 1) == 0) {
                cost = -cost;
            }
            ret = Math.max(ret, -go(newState) + cost);
        }
        map.put(state, ret);
        return ret;
    }

    static char[][] c;
    static int n;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        n = in.nextInt();
        c = in.readCharacterFieldTokens(n, n);
        map = new HashMap<>();
        int ans = go(new State(1, 0));
        if (c[0][0] == 'a') --ans;
        else if (c[0][0] == 'b') ++ans;
        out.println(ans < 0 ? "FIRST" : ans > 0 ? "SECOND" : "DRAW");
//        int[][] dp = new int[n][n];
//        for (int i = n - 1; i >= 0; i--) {
//            for (int j = n - 1; j >= 0; j--) {
//                int cost = c[i][j] == 'a' ? 1 : c[i][j] == 'b' ? -1 : 0;
//                if ((i + j & 1) == 0) {
//                    cost = -cost;
//                }
//                if (i + 1 == n && j + 1 == n) {
//                    dp[i][j] = cost;
//                } else if (i + 1 < n && j + 1 < n) {
//                    dp[i][j] = Math.max(-dp[i + 1][j], -dp[i][j + 1]) + cost;
//                } else if (i + 1 < n) {
//                    dp[i][j] = -dp[i + 1][j] + cost;
//                } else {
//                    dp[i][j] = -dp[i][j + 1] + cost;
//                }
////                System.out.println(i + " " + j + " " + dp[i][j] + " " + cost);
//            }
//        }
//        out.println(dp[0][0] < 0 ? "FIRST" : dp[0][0] > 0 ? "SECOND" : "DRAW");
    }

    static class State {
        long mask;
        int move;

        State(long mask, int move) {
            this.move = move;
            this.mask = mask;
        }

        boolean get(int i, int j) {
            if (i + j != move) throw new AssertionError();
            return ((mask >> i) & 1) == 1;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof State)) return false;

            State state = (State) o;

            if (mask != state.mask) return false;
            if (move != state.move) return false;

            return true;
        }

        public int hashCode() {
            int result = (int) (mask ^ (mask >>> 32));
            result = 31 * result + move;
            return result;
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
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