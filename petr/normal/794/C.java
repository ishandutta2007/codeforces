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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int len;

        int[] readWord(InputReader in) {
            int[] res = new int[26];
            String s = in.next();
            len = s.length();
            for (int i = 0; i < s.length(); ++i) {
                ++res[s.charAt(i) - 'a'];
            }
            return res;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] a = readWord(in);
            int[] b = readWord(in);
            char[] res = new char[len];
            int left = 0;
            int right = len - 1;
            for (int i = 0; i < len; ++i) {
                if (i % 2 == 0) {
                    int min = 0;
                    while (a[min] == 0) ++min;
                    int max = b.length - 1;
                    while (b[max] == 0) --max;
                    if (min < max) {
                        --a[min];
                        res[left++] = (char) ('a' + min);
                    } else {
                        int togo = (len - i - 1) / 2;
                        while (a[min] <= togo) {
                            togo -= a[min];
                            ++min;
                        }
                        res[right--] = (char) ('a' + min);
                    }
                } else {
                    int min = 0;
                    while (a[min] == 0) ++min;
                    int max = b.length - 1;
                    while (b[max] == 0) --max;
                    if (min < max) {
                        --b[max];
                        res[left++] = (char) ('a' + max);
                    } else {
                        int togo = (len - i - 1) / 2;
                        while (b[max] <= togo) {
                            togo -= b[max];
                            --max;
                        }
                        res[right--] = (char) ('a' + max);
                    }
                }
            }
            out.println(new String(res));
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