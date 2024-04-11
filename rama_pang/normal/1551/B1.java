import java.io.*;
import java.util.*;
import java.lang.*;

public class B1 {
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
        String s = in.next();
        int n = s.length();
        int[] A = new int[26];
        for (int i = 0; i < n; i++) {
          char c = s.charAt(i);
          A[c - 'a'] += 1;
        }
        int one = 0;
        int two = 0;
        for (int i = 0; i< 26; i++) {
          if (A[i] == 1) {
            one += 1;
          } else if (A[i] > 1) {
            two += 1;
          }
        }
        out.println(two + (one / 2));
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