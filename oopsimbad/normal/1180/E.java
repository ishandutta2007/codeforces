import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;

public class template {
    public static void main(String[] args) throws Exception {
        new template().run();
    }

    public void run() throws Exception {
        FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt(), m = f.nextInt();
        sum = new int[4000015];
        suf = new int[4000015];
        int[] a1 = new int[n], a2 = new int[m];
        for (int i = 0; i < n; i++)
            add(a1[i] = f.nextInt(), 1);
        for (int i = 0; i < m; i++)
            add(a2[i] = f.nextInt(), -1);
        int q = f.nextInt();
        while (q-- > 0) {
            int qt = f.nextInt(), a = f.nextInt() - 1, b = f.nextInt();
            if (qt == 1) {
                add(a1[a], -1);
                add(a1[a] = b, 1);
            } else {
                add(a2[a], 1);
                add(a2[a] = b, -1);
            }
            out.println(ans());
        }
        out.flush();
    }

    int[] sum, suf;

    public void add(int i, int v) {
        add(0, 0, 1000005, i, v);
    }

    public int ans() {
        if (suf[0] <= 0)
            return -1;
        return query(0, 0, 1000005, 0);
    }

    public int query(int i, int l, int r, int rs) {
        if (l == r - 1) {
            return l;
        } else {
            int m = (l + r) / 2;
            if (suf[2 * i + 2] + rs > 0)
                return query(2 * i + 2, m, r, rs);
            else
                return query(2 * i + 1, l, m, rs + sum[2 * i + 2]);
        }
    }

    public void add(int i, int l, int r, int ii, int b) {
        sum[i] += b;
        if (l != r - 1) {
            int m = (l + r) / 2;
            if (ii < m)
                add(2 * i + 1, l, m, ii, b);
            else
                add(2 * i + 2, m, r, ii, b);
            suf[i] = Math.max(suf[2 * i + 1] + sum[2 * i + 2], suf[2 * i + 2]);
        } else
            suf[i] = sum[i];
    }

    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}