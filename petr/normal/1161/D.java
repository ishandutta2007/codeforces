import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final long MODULO = 998244353;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            if (s.charAt(s.length() - 1) == '1') {
                out.println(0);
                return;
            }
            if (s.charAt(s.length() - 1) == '?') {
                s = s.substring(0, s.length() - 1) + "0";
            }
            long[] p2 = new long[2 * s.length() + 1];
            p2[0] = 1;
            for (int i = 1; i < p2.length; ++i) p2[i] = 2 * p2[i - 1] % MODULO;
            long res = 0;
            outer:
            for (int alen = 1; alen < s.length(); ++alen) {
                int[] parent = new int[s.length() + alen + 1];
                int zero = s.length() + alen;
                int[] inv = new int[parent.length];
                for (int i = 0; i < parent.length; ++i) {
                    parent[i] = i;
                }
                if (!merge(zero, 0, 1, parent, inv)) continue outer;
                if (!merge(zero, s.length(), 1, parent, inv)) continue outer;
                for (int i = 0; i < s.length(); ++i) {
                    if (s.charAt(s.length() - 1 - i) != '?') {
                        int a = i;
                        int b = (i < alen) ? s.length() + i : zero;
                        if (!merge(a, b, s.charAt(s.length() - 1 - i) - '0', parent, inv)) continue outer;
                    }
                }
                for (int i = 0; i < s.length() - 1 - i; ++i) {
                    if (!merge(i, s.length() - 1 - i, 0, parent, inv)) continue outer;
                }
                for (int i = 0; i < alen - 1 - i; ++i) {
                    if (!merge(s.length() + i, s.length() + alen - 1 - i, 0, parent, inv)) continue outer;
                }
                int degrees = -1;
                for (int i = 0; i < parent.length; ++i) if (parent[i] == i) ++degrees;
                res = (res + p2[degrees]) % MODULO;
            }
            out.println(res);
        }

        private boolean merge(int a, int b, int delta, int[] parent, int[] inv) {
            get(a, parent, inv);
            get(b, parent, inv);
            if (parent[a] == parent[b]) {
                if ((inv[a] ^ inv[b]) != delta) {
                    return false;
                }
            } else {
                inv[parent[a]] = inv[a] ^ inv[b] ^ delta;
                parent[parent[a]] = parent[b];
            }
            return true;
        }

        private void get(int a, int[] parent, int[] inv) {
            if (parent[a] == a) {
                if (inv[a] != 0) throw new RuntimeException();
                return;
            }
            int acc = 0;
            int res = a;
            while (res != parent[res]) {
                acc ^= inv[res];
                res = parent[res];
            }
            int cur = a;
            while (parent[cur] != res) {
                int nxt = parent[cur];
                int nxtacc = acc ^ inv[cur];
                parent[cur] = res;
                inv[cur] = acc;
                cur = nxt;
                acc = nxtacc;
            }
            if (inv[cur] != acc) throw new RuntimeException();
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

    }
}