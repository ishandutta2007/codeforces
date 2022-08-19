import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        /*for (int m = 1; m <= 100; ++m) {
            int[] a = new int[m + 1];
            a[m] = 1;
            for (int i = 0; i < m; ++i) {
                int[] b = new int[m + 1];
                for (int j = 0; j <= m; ++j) {
                    if (j == 0)
                        b[j] = a[j + 1];
                    else if (j == m)
                        b[j] = a[j - 1];
                    else
                        b[j] = a[j - 1] ^ a[j + 1];
                }
                a = b;
            }
            int s = 0;
            for (int x : a) s += x;
            out.println(s);
        } */
        long n = in.nextLong();
        long t = in.nextLong();
        long res = 0;
        long pw;
        int cnt;
        for (pw = 1, cnt = 1; pw <= n + 1; pw *= 2, ++cnt)
            if (pw == t) {
                res = count(n + 1, cnt) - count(1, cnt);
            }
        out.println(res);
    }

    static class State {
        long upto;
        int cnt;

        State(long upto, int cnt) {
            this.upto = upto;
            this.cnt = cnt;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (cnt != state.cnt) return false;
            if (upto != state.upto) return false;

            return true;
        }

        public int hashCode() {
            int result = (int) (upto ^ (upto >>> 32));
            result = 31 * result + cnt;
            return result;
        }
    }

    Map<State, Long> cache = new HashMap<State, Long>();

    private long count(long upto, int cnt) {
        if (upto < 0) return 0;
        if (cnt == 0) return 1;
        if (upto < ((1L << cnt) - 1)) return 0;
        State state = new State(upto, cnt);
        Long cached = cache.get(state);
        if (cached != null) return cached;
        long res = count(upto / 2, cnt) + count((upto + 1) / 2 - 1, cnt - 1);
        cache.put(state, res);
        return res;
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    }