import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
            String s = in.next();
            int slen = s.length();
            boolean[][] can = new boolean[4][slen + 1];
            can[2][slen - 2] = true;
            can[3][slen - 3] = true;
            for (int pos = slen - 4; pos >= 5; --pos) {
                for (int len = 2; len <= 3; ++len) {
                    for (int nlen = 2; nlen <= 3 && pos + len + nlen <= slen; ++nlen)
                        if (can[nlen][pos + len]) {
                            boolean ok = true;
                            if (len == nlen) {
                                ok = false;
                                for (int i = 0; i < len; ++i) {
                                    if (s.charAt(pos + i) != s.charAt(pos + len + i)) ok = true;
                                }
                            }
                            if (ok) {
                                can[len][pos] = true;
                            }
                        }
                }
            }
            List<String> res = new ArrayList<>();
            for (int pos = slen; pos >= 5; --pos) {
                for (int len = 2; len <= 3; ++len) {
                    if (can[len][pos]) {
                        res.add(s.substring(pos, pos + len));
                    }
                }
            }
            Collections.sort(res);
            int cnt = 0;
            for (int i = 0; i < res.size(); ++i) {
                if (i == 0 || !res.get(i).equals(res.get(i - 1))) {
                    ++cnt;
                }
            }
            out.println(cnt);
            for (int i = 0; i < res.size(); ++i) {
                if (i == 0 || !res.get(i).equals(res.get(i - 1))) {
                    out.println(res.get(i));
                }
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

    }
}