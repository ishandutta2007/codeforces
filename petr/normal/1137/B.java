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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            String t = in.next();
            int[] kmp = buildKMP(t);
            int s0 = 0;
            int s1 = 0;
            for (int i = 0; i < s.length(); ++i)
                if (s.charAt(i) == '1') ++s1;
                else ++s0;
            int t0 = 0;
            int t1 = 0;
            for (int i = 0; i < t.length(); ++i)
                if (t.charAt(i) == '1') ++t1;
                else ++t0;
            int repeat = kmp[t.length()];
            int e0 = 0;
            int e1 = 0;
            for (int i = repeat; i < t.length(); ++i)
                if (t.charAt(i) == '1') ++e1;
                else ++e0;
            char[] res = new char[s.length()];
            int pos;
            for (pos = 0; pos < s.length(); ) {
                int f0;
                int f1;
                if (pos == 0) {
                    f0 = t0;
                    f1 = t1;
                } else {
                    f0 = e0;
                    f1 = e1;
                }
                if (s0 >= f0 && s1 >= f1) {
                    s0 -= f0;
                    s1 -= f1;
                    if (pos == 0) {
                        for (int i = 0; i < t.length(); ++i) res[pos++] = t.charAt(i);
                    } else {
                        for (int i = repeat; i < t.length(); ++i) res[pos++] = t.charAt(i);
                    }
                } else {
                    for (int i = 0; i < s0; ++i) res[pos++] = '0';
                    for (int i = 0; i < s1; ++i) res[pos++] = '1';
                }
            }
            if (pos != s.length()) throw new RuntimeException();
            out.println(new String(res));
        }

        private int[] buildKMP(String p) {
            int[] kmp = new int[p.length() + 1];
            for (int i = 2; i <= p.length(); ++i) {
                int j = kmp[i - 1];
                while (true) {
                    if (p.charAt(j) == p.charAt(i - 1)) {
                        ++j;
                        break;
                    }
                    if (j == 0) break;
                    j = kmp[j];
                }
                kmp[i] = j;
            }
            return kmp;
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