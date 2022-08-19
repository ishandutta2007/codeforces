import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final int INF = (int) 2e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            int[] writePos = new int[n];
            int[][] writeMask = new int[n][];
            int[] best = new int[n + 1];
            Arrays.fill(best, INF);
            best[0] = -1;
            int m = in.nextInt();
            int[] fillers = new int[m];
            for (int i = 0; i < m; ++i) fillers[i] = in.nextInt();
            Random random = new Random(5437154351L + System.currentTimeMillis());
            for (int i = 0; i < m; ++i) {
                int j = random.nextInt(m - i) + i;
                int t = fillers[i];
                fillers[i] = fillers[j];
                fillers[j] = t;
            }
            Arrays.sort(fillers);

            for (int i = 0; i < n; ++i) {
                if (a[i] >= 0) {
                    int left = 0;
                    int right = n + 1;
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        if (best[middle] < a[i]) {
                            left = middle;
                        } else {
                            right = middle;
                        }
                    }
                    writePos[i] = right;
                    best[right] = a[i];
                } else {
                    writeMask[i] = new int[(n + m + 100) >> 5];
                    int pBest = n;
                    int pFillers = fillers.length - 1;
                    int pMask = 0;
                    while (pFillers >= 0) {
                        int cur = fillers[pFillers];
                        while (best[pBest - 1] >= cur) {
                            --pBest;
                            ++pMask;
                        }
                        writeMask[i][pMask >> 5] |= (1 << (pMask & 31));
                        ++pMask;
                        best[pBest] = cur;
                        --pFillers;
                    }
                }
            }

            int len = n;
            while (best[len] >= INF) --len;

            boolean[] fillersUsed = new boolean[m];
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] >= 0) {
                    if (writePos[i] == len) {
                        --len;
                    }
                } else {
                    int pBest = n;
                    int pFillers = fillers.length - 1;
                    int pMask = 0;
                    int usedIndex = -1;
                    while (pFillers >= 0) {
                        while ((writeMask[i][pMask >> 5] & (1 << (pMask & 31))) == 0) {
                            --pBest;
                            ++pMask;
                        }
                        ++pMask;
                        if (pBest == len) {
                            usedIndex = pFillers;
                        }
                        --pFillers;
                    }
                    if (usedIndex >= 0) {
                        if (fillersUsed[usedIndex]) throw new RuntimeException();
                        fillersUsed[usedIndex] = true;
                        a[i] = fillers[usedIndex];
                        --len;
                    }
                }
            }

            int ptr = 0;
            for (int i = 0; i < n; ++i)
                if (a[i] < 0) {
                    while (fillersUsed[ptr]) ++ptr;
                    a[i] = fillers[ptr++];
                }

            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                out.print(a[i]);
            }
            out.println();
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