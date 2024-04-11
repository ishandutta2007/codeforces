import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        private static final int MAX = 100;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            boolean[] prime = new boolean[MAX / 2 + 1];
            Arrays.fill(prime, true);
            for (int i = 2; i < prime.length; ++i)
                if (prime[i]) {
                    for (int j = i * 2; j < prime.length; j += i) prime[j] = false;
                }
            List<Integer> toCheck = new ArrayList<>();
            for (int i = 2; i < prime.length; ++i)
                if (prime[i]) {
                    out.println(i);
                    out.flush();
                    String ans = in.next();
                    if (ans.equals("yes")) {
                        toCheck.add(i);
                    }
                }
            if (toCheck.size() >= 2) {
                out.println("composite");
            } else if (toCheck.size() == 0) {
                out.println("prime");
            } else {
                int x = toCheck.get(0);
                x *= x;
                if (x <= MAX) {
                    out.println(x);
                    out.flush();
                    String ans = in.next();
                    if (ans.equals("yes")) {
                        out.println("composite");
                    } else {
                        out.println("prime");
                    }
                } else {
                    out.println("prime");
                }
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

    }
}