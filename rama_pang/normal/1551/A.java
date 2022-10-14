import java.io.*;
import java.util.*;
import java.lang.*;

public class A {
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
        int ans = (int) 1e9 + 100;
        int ansc1 = -1, ansc2 = -1;
        for (int c1 = (n / 3) - 2; c1 <= (n / 3) + 2; c1++) {
          if (c1 < 0 || c1 > n) continue;
          int c2 = n - c1;
          if (c2 % 2 != 0) continue;
          c2 /= 2;
          if (ans > Math.abs(c1 - c2)) {
            ans = Math.abs(c1 - c2);
            ansc1 = c1;
            ansc2 = c2;
          }
        }
        
        out.print(ansc1);
        out.print(' ');
        out.print(ansc2);
        out.print('\n');
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