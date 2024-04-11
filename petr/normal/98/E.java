import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Crocodile implements Runnable {
    private void solve() throws IOException {
        int m = nextInt();
        int n = nextInt();
        int mx = Math.max(n, m);
        double[][] ans = new double[mx + 1][mx + 1];
        for (int sum = 0; sum <= mx + mx; ++sum) {
            for (int a = 0; a <= mx; ++a) {
                int b = sum - a;
                if (b >= 0 && b <= mx) {
                    ans[a][b] = doit(a, b, ans);
                }
            }
        }
        writer.println(ans[m][n] + " " + (1.0 - ans[m][n]));
    }

    private double doit(int m, int n, double[][] ans) {
        double res = 1.0 / (n + 1);
        if (m == 0 || n == 0) return res;
        double borderP = 1 / (ans[n][m - 1] * (n + 1) + 1);
        res = Math.max(res, eval(m, n, ans, 0.0));
        res = Math.max(res, eval(m, n, ans, borderP));
        res = Math.max(res, eval(m, n, ans, 1.0));
        return res;
    }

    private double eval(int m, int n, double[][] ans, double p) {
        return (1 - p) * n / (n + 1.0) * (1 - ans[n - 1][m]) + (p + (1 - p) / (n + 1.0) - Math.max((1 - p) / (n + 1), p * ans[n][m - 1]));
    }

    public static void main(String[] args) {
        new Crocodile().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}