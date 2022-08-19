import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            List<Integer> sign = new ArrayList<>();
            sign.add(1);
            if (!in.next().equals("?")) throw new RuntimeException();
            while (true) {
                String s = in.next();
                if (s.equals("+"))
                    sign.add(1);
                else if (s.equals("-"))
                    sign.add(-1);
                else if (s.equals("="))
                    break;
                else
                    throw new RuntimeException();
                if (!in.next().equals("?")) throw new RuntimeException();
            }
            int n = in.nextInt();
            int pluses = 0;
            int minuses = 0;
            for (int x : sign)
                if (x == 1) ++pluses;
                else ++minuses;
            int[] a = new int[sign.size()];
            int got = 0;
            for (int i = 0; i < a.length; ++i) {
                if (sign.get(i) == 1) {
                    a[i] = 1;
                    ++got;
                } else {
                    a[i] = n;
                    got -= n;
                }
            }
            int extra = n - got;
            if (extra < 0 || extra > a.length * (n - 1)) {
                out.println("Impossible");
                return;
            }
            out.println("Possible");
            for (int i = 0; i < a.length; ++i) {
                if (i > 0) {
                    if (sign.get(i) == 1) {
                        out.print(" + ");
                    } else {
                        out.print(" - ");
                    }
                }
                int by = Math.min(n - 1, extra);
                extra -= by;
                if (sign.get(i) == 1) {
                    a[i] += by;
                } else {
                    a[i] -= by;
                }
                out.print(a[i]);
            }
            out.println(" = " + n);
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