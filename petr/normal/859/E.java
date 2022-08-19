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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] next = new int[2 * n];
            Arrays.fill(next, -1);
            for (int i = 0; i < n; ++i) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                next[a] = b;
            }
            int[] component = new int[2 * n];
            int[] size = new int[2 * n + 1];
            boolean[] isTree = new boolean[2 * n + 1];
            boolean[] isLoop = new boolean[2 * n + 1];
            int numComponents = 0;
            for (int i = 0; i < 2 * n; ++i)
                if (next[i] >= 0 && component[i] == 0) {
                    ++numComponents;
                    int cur = i;
                    while (cur >= 0 && component[cur] == 0) {
                        component[cur] = numComponents;
                        ++size[numComponents];
                        cur = next[cur];
                    }
                    if (cur < 0) {
                        isTree[numComponents] = true;
                    } else if (component[cur] == numComponents) {
                        isTree[numComponents] = false;
                        if (next[cur] == cur) isLoop[numComponents] = true;
                    } else {
                        size[component[cur]] += size[numComponents];
                        int dest = component[cur];
                        cur = i;
                        while (component[cur] != dest) {
                            component[cur] = dest;
                            cur = next[cur];
                        }
                        size[numComponents] = 0;
                        --numComponents;
                    }
                }
            long res = 1;
            for (int i = 1; i <= numComponents; ++i)
                if (isTree[i])
                    res = res * size[i] % MODULO;
                else if (!isLoop[i])
                    res = res * 2 % MODULO;
            out.println(res);
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