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
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int HASH_BITS = 22;
        static final int HASH_MAX = 1 << HASH_BITS;
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long HASH_BY = 972165471654137651L + 2 * System.currentTimeMillis();
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            long[] c = new long[n];
            for (int i = 0; i < n; ++i) c[i] = in.nextLong();
            long[] xor = new long[m];
            int[] hash = new int[m];
            int[] nextSameHash = new int[m];
            int[] nextSameXor = new int[m];
            int[] lastSameXor = new int[m];
            int[] hashFirst = new int[HASH_MAX];
            int[] us = new int[m];
            int[] vs = new int[m];
            Arrays.fill(hashFirst, -1);
            outer:
            for (int i = 0; i < m; ++i) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                us[i] = u;
                vs[i] = v;

                xor[i] = c[u] ^ c[v];
                hash[i] = (int) ((xor[i] * HASH_BY) >>> (64 - HASH_BITS));
                int ptr = hashFirst[hash[i]];
                while (ptr >= 0) {
                    if (xor[i] == xor[ptr]) {
                        nextSameXor[lastSameXor[ptr]] = i;
                        lastSameXor[ptr] = i;
                        nextSameXor[i] = -1;
                        continue outer;
                    }
                    ptr = nextSameHash[ptr];
                }
                nextSameHash[i] = hashFirst[hash[i]];
                hashFirst[hash[i]] = i;
                lastSameXor[i] = i;
                nextSameXor[i] = -1;
            }

            int[] parent = new int[n];
            Arrays.fill(parent, -1);

            long free = 1L << k;
            long[] p2 = new long[n + 1];
            p2[0] = 1;
            for (int i = 1; i <= n; ++i) {
                p2[i] = p2[i - 1] * 2;
                if (p2[i] >= MODULO) p2[i] -= MODULO;
            }

            long res = 0;

            for (int h = 0; h < hashFirst.length; ++h) {
                int ptr = hashFirst[h];
                while (ptr >= 0) {
                    --free;
                    int comps = n;
                    int ptr2 = ptr;
                    while (ptr2 >= 0) {
                        int u = us[ptr2];
                        int v = vs[ptr2];
                        u = get(parent, u);
                        v = get(parent, v);
                        if (u != v) {
                            --comps;
                            parent[u] = v;
                        }
                        ptr2 = nextSameXor[ptr2];
                    }

                    res += p2[comps];
                    if (res >= MODULO) res -= MODULO;

                    ptr2 = ptr;
                    while (ptr2 >= 0) {
                        int u = us[ptr2];
                        int v = vs[ptr2];
                        parent[u] = -1;
                        parent[v] = -1;
                        ptr2 = nextSameXor[ptr2];
                    }
                    ptr = nextSameHash[ptr];
                }
            }

            res = (res + free % MODULO * p2[n]) % MODULO;
            out.println(res);
        }

        private int get(int[] parent, int u) {
            int v = u;
            while (parent[v] >= 0) v = parent[v];
            int t = u;
            while (t != v) {
                int s = parent[t];
                parent[t] = v;
                t = s;
            }
            return v;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}