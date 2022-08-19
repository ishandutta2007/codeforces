import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String a = readPuzzle(in);
            String b = readPuzzle(in);
            if (a.equals(b)) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

        private String readPuzzle(InputReader in) {
            char[][] a = new char[2][];
            a[0] = in.next().toCharArray();
            a[1] = in.next().toCharArray();
            String t = "";
            if (a[0][0] != 'X') t += a[0][0];
            if (a[0][1] != 'X') t += a[0][1];
            if (a[1][1] != 'X') t += a[1][1];
            if (a[1][0] != 'X') t += a[1][0];
            String res = t;
            for (int i = 1; i < t.length(); ++i) {
                String cur = t.substring(i) + t.substring(0, i);
                if (cur.compareTo(res) < 0) res = cur;
            }
            return res;
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

    }
}