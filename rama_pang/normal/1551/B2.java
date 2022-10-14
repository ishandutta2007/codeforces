import java.io.*;
import java.util.*;
import java.lang.*;

public class B2 {
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

        Vector<Vector<Integer>> A = new Vector<Vector<Integer>>();
        for (int i = 0; i < n; i++) {
          A.add(new Vector<Integer>());
        }
        for (int i = 0; i < n; i++) {
          int x = in.nextInt();
          A.elementAt(x - 1).addElement(i);
        }

        int ans = 0;
        int[] ls = new int[n];

        for (int i = 0; i < n; i++) {
          for (int j = 0; j < k && j < A.elementAt(i).size(); j++) {
            int id = A.elementAt(i).elementAt(j);
            ls[ans] = id;
            ans += 1;
          }
        }
        ans /= k;
        ans *= k;
        int[] trace = new int[n];
        for (int i = 0; i < ans; i++) {
          trace[ls[i]] = (i % k) + 1;
        }
        for (int i = 0; i < n; i++) {
          out.print(trace[i]);
          out.print(' ');
        }
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