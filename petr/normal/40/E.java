import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Table {
    private void solve() {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int[] a = new int[k];
        int[] b = new int[k];
        int[] c = new int[k];
        for (int i = 0; i < k; ++i) {
            a[i] = nextInt();
            b[i] = nextInt();
            c[i] = nextInt();
        }
        int p = nextInt();
        if ((n + m) % 2 != 0) {
            writer.println(0);
            return;
        }
        if (n > m) {
            int t = n;
            n = m;
            m = t;
            int[] tt = a;
            a = b;
            b = tt;
        }
        int p2 = 0;
        for (int u = 0; u < m; ++u) {
            int prod = 1;
            int left = n;
            for (int i = 0; i < k; ++i)
                if (b[i] == u + 1) {
                    prod *= c[i];
                    --left;
                }
            if (left == 0 && prod == 1) {
                writer.println(0);
                return;
            }
            if (left > 0)
                p2 += left - 1;
        }
        p2 -= n - 1;
        writer.println(BigInteger.valueOf(2).modPow(BigInteger.valueOf(p2), BigInteger.valueOf(p)));
    }


    public static void main(String[] args) {
        new Table().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    private void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            tokenizer = null;
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
}