import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        int k;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            k = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            vs[0].solve(null);
            out.println(vs[0].answer);
        }

        class Vertex {
            List<Vertex> adj = new ArrayList<>();
            long answer = 0;
            int[] count = new int[k];
            long[] sumWhole = new long[k];

            public void solve(Vertex parent) {
                ++count[0];
                for (Vertex v : adj) {
                    if (v == parent) continue;
                    v.solve(this);
                    answer += v.answer;
                    for (int oldrem = 0; oldrem < k; ++oldrem) {
                        for (int newrem = 0; newrem < k; ++newrem) {
                            answer += sumWhole[oldrem] * v.count[newrem] + count[oldrem] * v.sumWhole[newrem];
                            int rem = oldrem + newrem + 1;
                            answer += count[oldrem] * (long) v.count[newrem] * ((rem + k - 1) / k);
                        }
                    }
                    for (int newrem = 0; newrem < k; ++newrem) {
                        int rem = newrem + 1;
                        count[rem % k] += v.count[newrem];
                        sumWhole[rem % k] += v.sumWhole[newrem];
                        if (rem >= k) {
                            sumWhole[rem % k] += v.count[newrem];
                        }
                    }
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}