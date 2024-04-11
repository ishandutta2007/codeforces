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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private int n;
        private int[] p;
        private int[] depth;
        private int[] maxDepth;
        private int[] firstChild;
        private int[] nextSibling;
        int[] seq;
        int nseq = 0;
        int[] start;
        int nstart = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            p = new int[n];
            p[0] = -1;
            for (int i = 1; i < n; ++i) p[i] = in.nextInt();
            depth = new int[n];
            for (int i = 1; i < n; ++i) depth[i] = 1 + depth[p[i]];
            maxDepth = depth.clone();
            for (int i = n - 1; i > 0; --i) maxDepth[p[i]] = Math.max(maxDepth[p[i]], maxDepth[i]);
            firstChild = new int[n];
            nextSibling = new int[n];
            Arrays.fill(firstChild, -1);
            for (int i = 1; i < n; ++i) {
                nextSibling[i] = firstChild[p[i]];
                firstChild[p[i]] = i;
            }
            seq = new int[(int) 1e6 + 1];
            start = new int[n];
            nstart = 0;
            process(0);
            if (nstart != n) throw new RuntimeException();
            for (int i = 0; i < n; ++i) out.print(start[i] + " ");
            out.println();
            out.println(nseq);
            for (int i = 0; i < nseq; ++i) out.print(seq[i] + " ");
            out.println();
        }

        private void process(int root) {
            start[nstart++] = root;
            int bc = -1;
            int c = firstChild[root];
            while (c >= 0) {
                if (bc < 0 || maxDepth[c] > maxDepth[bc]) bc = c;
                c = nextSibling[c];
            }
            if (bc < 0) return;
            c = firstChild[root];
            int prevDepth = 0;
            while (c >= 0) {
                if (c != bc) {
                    process(c);
                    for (int i = 0; i < prevDepth; ++i) {
                        seq[nseq++] = c;
                    }
                    prevDepth = maxDepth[c] - depth[c] + 1;
                }
                c = nextSibling[c];
            }
            process(bc);
            for (int i = 0; i < prevDepth; ++i) {
                seq[nseq++] = bc;
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