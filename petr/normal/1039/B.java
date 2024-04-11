import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Random;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static final long BUBEN = 100;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long n = in.nextLong();
            long k = in.nextLong();
            long min = 1;
            long max = n;
            Random random = new Random(75416543153415L + System.currentTimeMillis());
            while (true) {
                if (max - min + 1 >= BUBEN) {
                    long mid = (min + max) / 2;
                    out.println(min + " " + mid);
                    out.flush();
                    String ans = in.next();
                    if (ans.equals("Yes")) {
                        max = mid;
                    } else if (ans.equals("No")) {
                        min = mid + 1;
                    } else throw new RuntimeException();
                } else {
                    long mid = min + random.nextInt((int) (max - min + 1));
                    out.println(mid + " " + mid);
                    out.flush();
                    String ans = in.next();
                    if (ans.equals("Yes")) {
                        return;
                    } else if (ans.equals("No")) {
                    } else throw new RuntimeException();
                }
                min = Math.max(1, min - k);
                max = Math.min(n, max + k);
            }
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}