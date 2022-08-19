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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[] res;
        int nres;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            String t = in.next();
            String cur = s;
            int left = t.length() / 2;
            int right = left;
            int got = 0;
            res = new int[6101];
            nres = 0;
            for (int step = 0; step < (t.length() + 1) / 2; ++step) {
                char ch = t.charAt(right);
                ++right;
                int pos = cur.indexOf(ch);
                if (pos < 0 || pos >= cur.length() - got) {
                    out.println(-1);
                    return;
                }
                cur = applyOp(cur, n - (pos + 1));
                cur = applyOp(cur, n - got);
                cur = applyOp(cur, got);
                ++got;
                if (left > 0) {
                    --left;
                    ch = t.charAt(left);
                    pos = cur.indexOf(ch, got);
                    if (pos < 0) {
                        out.println(-1);
                        return;
                    }
                    cur = applyOp(cur, n - pos);
                    cur = applyOp(cur, pos - got);
                    ++got;
                }
            }
            if (left != 0 || right != t.length() || !cur.equals(t)) throw new RuntimeException();
            out.println(nres);
            for (int i = 0; i < nres; ++i) {
                if (i > 0) out.print(" ");
                out.print(res[i]);
            }
            out.println();
        }

        private String applyOp(String cur, int w) {
            res[nres++] = w;
            StringBuilder b = new StringBuilder(cur.substring(cur.length() - w));
            b.reverse();
            b.append(cur.substring(0, cur.length() - w));
            return b.toString();
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}