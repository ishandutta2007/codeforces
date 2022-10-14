import java.io.*;
import java.util.*;
import java.lang.*;

public class C {
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
        String[] A = new String[n];
        for (int i = 0; i < n; i++) {
          A[i] = in.next();
        }
        int ans = 0;
        for (char c = 'a'; c <= 'e'; c++) {
          int[] ls = new int[n];
          for (int i = 0; i < n; i++) {
            int delta = 0;
            for (int j = 0; j < A[i].length(); j++) {
              if (A[i].charAt(j) == c) {
                delta += 1;
              } else {
                delta -= 1;
              }
            }
            ls[i] = delta;
          }
          Arrays.sort(ls, 0, n);
          int cur = 0;
          int score = 0;
          for (int i = n - 1; i >= 0; i--) {
            if (cur + ls[i] >= 1) {
              cur += ls[i];
              score += 1;
            }
          }
          ans = Math.max(ans, score);
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