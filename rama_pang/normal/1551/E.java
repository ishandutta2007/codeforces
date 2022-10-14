import java.io.*;
import java.util.*;
import java.lang.*;

public class E {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Solver solver = new Solver();
    solver.Main(in, out);
    out.close();
  }

  static class Solver {
    public void Main(InputReader in, PrintWriter out) {
      int T = in.nextInt();
      for (int t = 0; t < T; t++) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
          a[i] = in.nextInt();
          a[i] -= 1;
        }
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
          for (int j = 0; j <= n; j++) {
            dp[i][j] = (int) -1e9;
          }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            int add = 0;
            if (a[i] == j) add = 1;
            dp[i + 1][j] = Math.max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = Math.max(dp[i + 1][j + 1], dp[i][j] + add);
          }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
          if (dp[n][i] >= k) {
            ans = Math.max(ans, i);
          }
        }
        if (ans != -1) {
          ans = n - ans;
        }
        out.println(ans);
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