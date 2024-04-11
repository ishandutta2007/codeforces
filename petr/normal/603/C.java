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
        int g1(int n) {
            if (n == 2 || n == 0) return 0;
            if (n == 1 || n == 3) return 1;
            if (n % 2 != 0) return 0;
            int p2 = 0;
            while (n % 2 == 0) {
                n /= 2;
                ++p2;
            }
            if (n == 2 || n == 3) ++p2;
            if (p2 % 2 == 0) return 2;
            else return 1;
        }

        int g2(int n) {
            if (n == 2) return 2;
            if (n == 1) return 1;
            if (n == 0) return 0;
            if (n % 2 == 0) return 1;
            return 0;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
        /*int[] g1 = new int[100000];
        for (int i = 1; i < g1.length; ++i) {
            Set<Integer> seen = new HashSet<>();
            seen.add(g1[i - 1]);
            if (i % 2 == 0)
                seen.add(g1[i / 2]);
            for (int j = 0;; ++j) if (!seen.contains(j)) {
                g1[i] = j;
                break;
            }
            if (g1[i] != g1(i)) throw new RuntimeException();
        }

        int[] g2 = new int[100000];
        for (int i = 1; i < g2.length; ++i) {
            Set<Integer> seen = new HashSet<>();
            seen.add(g2[i - 1]);
            if (i % 2 == 0)
                seen.add(g2[0]);
            for (int j = 0;; ++j) if (!seen.contains(j)) {
                g2[i] = j;
                break;
            }
            if (g2[i] != g2(i)) throw new RuntimeException();
        }*/

            int n = in.nextInt();
            int k = in.nextInt();
            int state = 0;
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt();
                if (k % 2 == 0) {
                    state ^= g2(a);
                } else {
                    state ^= g1(a);
                }
            }
            if (state == 0) out.println("Nicky");
            else out.println("Kevin");
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