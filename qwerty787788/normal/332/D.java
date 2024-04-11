import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

    void realSolve() throws IOException {
        // long st = System.currentTimeMillis();
        int MAX = 2010;
        BigInteger[] fact = new BigInteger[MAX + 1];
        fact[0] = fact[1] = BigInteger.ONE;
        for (int i = 2; i <= MAX; i++)
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                a[i][j] = a[j][i] = in.nextInt();
        for (int i = 0; i < n; i++)
            a[i][i] = -1;
        long[] ss = new long[n + 1];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            long r = 0;
            for (int j = 0; j < n; j++)
                if (a[i][j] >= 0) {
                    sum++;
                    r += a[i][j];
                }
            ss[sum] += r;
        }
        BigInteger result = BigInteger.ZERO;
        for (int cnt = k; cnt <= n; cnt++) {
            BigInteger add = BigInteger.valueOf(ss[cnt]);
            add = add.multiply(fact[cnt - 1]);
            add = add.divide(fact[cnt - k]);
            add = add.divide(fact[k - 1]);
            result = result.add(add);
        }
        BigInteger c_n_k = fact[n].divide(fact[n - k]).divide(fact[k]);
        result = result.divide(c_n_k);
        out.println(result.toString());
        // System.err.println(System.currentTimeMillis() - st);
    }

    private class InputReader {
        StringTokenizer st;
        BufferedReader br;

        public InputReader(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public InputReader(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                String s;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    return null;
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        boolean hasMoreElements() {
            while (st == null || !st.hasMoreElements()) {
                String s;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    return false;
                }
                st = new StringTokenizer(s);
            }
            return st.hasMoreElements();
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    InputReader in;
    PrintWriter out;

    void solveIO() throws IOException {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);

        realSolve();

        out.close();

    }

    public static void main(String[] args) throws IOException {
        new CF().solveIO();
    }
}