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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) p[i] = in.nextInt() - 1;
            int[] cycles = new int[n];
            int nCycles = 0;
            boolean[] mark = new boolean[n];
            for (int i = 0; i < n; ++i)
                if (!mark[i]) {
                    int j = i;
                    int len = 0;
                    do {
                        mark[j] = true;
                        j = p[j];
                        ++len;
                    } while (j != i);
                    cycles[nCycles++] = len;
                }
            cycles = Arrays.copyOf(cycles, nCycles);
            Arrays.sort(cycles);
            int doubles = 0;
            for (int x : cycles) doubles += x / 2;
            int maxKill;
            if (k <= doubles) {
                maxKill = 2 * k;
            } else {
                maxKill = Math.min(n, 2 * doubles + (k - doubles));
            }
            int minKill = canRepresent(cycles, Math.min(k, n - k)) ? k : (k + 1);
            out.println(minKill + " " + maxKill);
        }

        private boolean canRepresent(int[] a, int s) {
            int[] cnt = new int[s + 1];
            for (int x : a) {
                if (x <= s)
                    ++cnt[x];
            }
            boolean[] can = new boolean[s + 1];
            can[0] = true;
            for (int v = 1; v <= s; ++v) {
                int am = cnt[v];
                if (am == 0) continue;
                for (int from = 0; from < v; ++from) {
                    int counter = -1;
                    for (int got = from; got <= s; got += v) {
                        --counter;
                        if (can[got]) counter = am;
                        else if (counter >= 0) {
                            can[got] = true;
                        }
                    }
                }
            }
            return can[s];
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