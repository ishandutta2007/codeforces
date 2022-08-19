import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            int[] first = new int[10];
            int[] last = new int[10];
            Arrays.fill(first, s.length());
            Arrays.fill(last, -1);
            for (int i = 0; i < s.length(); ++i) {
                int d = s.charAt(i) - '0';
                first[d] = Math.min(first[d], i);
                last[d] = Math.max(last[d], i);
            }
            outer:
            for (int mid = 0; mid < 10; ++mid) {
                int plast = -1;
                for (int i = 0; i < mid; ++i)
                    if (first[i] <= last[i]) {
                        if (first[i] < plast) {
                            continue outer;
                        }
                        plast = last[i];
                    }
                int pfirst = s.length();
                for (int i = 9; i > mid; --i)
                    if (first[i] <= last[i]) {
                        if (last[i] > pfirst) {
                            continue outer;
                        }
                        pfirst = first[i];
                    }
                for (int i = pfirst; i <= plast; ++i) {
                    if (s.charAt(i) == '0' + mid) {
                        continue outer;
                    }
                }
                char[] res = new char[s.length()];
                for (int i = 0; i < s.length(); ++i) {
                    if (s.charAt(i) < '0' + mid) {
                        res[i] = '1';
                    } else if (s.charAt(i) > '0' + mid) {
                        res[i] = '2';
                    } else if (i > plast) {
                        res[i] = '1';
                    } else if (i < pfirst) {
                        res[i] = '2';
                    } else {
                        throw new RuntimeException();
                    }
                }
                out.println(new String(res));
                return;
            }
            out.println("-");
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