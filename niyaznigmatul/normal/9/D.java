import java.io.*;
import java.math.*;
import java.util.*;

public class D {
  public static void main(String[] args) {
    new D().run();
  }

  class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    boolean eof;
    String buf;

    public FastScanner(String fileName) throws FileNotFoundException {
      br = new BufferedReader(new FileReader(fileName));
      nextToken();
    }

    public FastScanner(InputStream stream) {
      br = new BufferedReader(new InputStreamReader(stream));
      nextToken();
    }

    String nextToken() {
      while (st == null || !st.hasMoreTokens()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (Exception e) {
          eof = true;
          break;
        }
      }
      String ret = buf;
      buf = eof ? "-1" : st.nextToken();
      return ret;
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }

    void close() {
      try {
        br.close();
      } catch (Exception e) {

      }
    }

    boolean isEOF() {
      return eof;
    }
  }

  FastScanner sc;
  PrintWriter out;

  public void run() {
    Locale.setDefault(Locale.US);
    try {
      sc = new FastScanner(System.in);
      out = new PrintWriter(System.out);
      solve();
      sc.close();
      out.close();
    } catch (Throwable e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  long nextLong() {
    return sc.nextLong();
  }

  double nextDouble() {
    return sc.nextDouble();
  }

  int nextInt() {
    return sc.nextInt();
  }

  String nextToken() {
    return sc.nextToken();
  }

  void solve() {
    int n = nextInt();
    int h = nextInt();
    long[][] dp = new long[n + 1][n + 1];
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
        for (int n2 = 0; n2 < i; n2++) {
          for (int h2 = 0; h2 < j - 1; ++h2) {
            dp[i][j] += dp[n2][h2] * dp[i - n2 - 1][j - 1] + dp[n2][j - 1] * dp[i - n2 - 1][h2];
          }
          dp[i][j] += dp[n2][j - 1] * dp[i - n2 - 1][j - 1];
        }
      }
    }
    long ans = 0;
    for (int i = h; i <= n; i++) {
      ans += dp[n][i];
    }
    out.println(ans);
  }
}