import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int n;
        String[] s;
        int m;
        int[] a;
        int[] b;
        int[] length;
        byte[][][] endsWith;
        byte[][][] startsWith;
        byte[][][] contains;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            s = new String[n];
            length = new int[n];
            for (int i = 0; i < n; ++i) {
                s[i] = in.next();
                length[i] = s[i].length();
            }
            m = in.nextInt();
            length = Arrays.copyOf(length, n + m);
            a = new int[n + m];
            b = new int[n + m];
            Arrays.fill(a, -1);
            Arrays.fill(b, -1);
            endsWith = new byte[n + m][100][];
            startsWith = new byte[n + m][100][];
            contains = new byte[n + m][100][];
            for (int i = 0; i < m; ++i) {
                a[i + n] = in.nextInt() - 1;
                b[i + n] = in.nextInt() - 1;
                length[i + n] = Math.min(100, length[a[i + n]] + length[b[i + n]]);
                out.println(solveOne(i + n));
            }
        }

        private int solveOne(int last) {
            for (int len = 1; ; ++len) {
                for (int mask = 0; mask < (1 << len); ++mask) {
                    if (!checkContains(last, len, mask)) {
                        return len - 1;
                    }
                }
            }
        }

        private boolean checkContains(int at, int len, int mask) {
            if (len == 0) throw new RuntimeException();
            if (contains[at][len] == null) contains[at][len] = new byte[1 << len];
            if (contains[at][len][mask] == 0) {
                contains[at][len][mask] = -1;
                if (at < n) {
                    int last = 0;
                    l1:
                    for (int pos = 0; pos < s[at].length(); ++pos) {
                        last = last * 2 + (s[at].charAt(pos) - '0');
                        if (pos + 1 >= len) {
                            if (last == mask) {
                                contains[at][len][mask] = 1;
                                break l1;
                            }
                            last = last & ((1 << (len - 1)) - 1);
                        }
                    }
                } else {
                    if (checkContains(a[at], len, mask)) {
                        contains[at][len][mask] = 1;
                    } else if (checkContains(b[at], len, mask)) {
                        contains[at][len][mask] = 1;
                    } else {
                        for (int left = 1; left < len; ++left) {
                            if (checkEndsWith(a[at], left, mask >> (len - left)) && checkStartsWith(b[at], len - left, mask & ((1 << (len - left)) - 1))) {
                                contains[at][len][mask] = 1;
                            }
                        }
                    }
                }
            }
            return contains[at][len][mask] == 1;
        }

        private boolean checkStartsWith(int at, int len, int mask) {
            if (len == 0) throw new RuntimeException();
            if (startsWith[at][len] == null) startsWith[at][len] = new byte[1 << len];
            if (startsWith[at][len][mask] == 0) {
                startsWith[at][len][mask] = -1;
                if (at < n) {
                    if (len <= length[at]) {
                        int last = 0;
                        for (int pos = 0; pos < len; ++pos) {
                            last = last * 2 + (s[at].charAt(pos) - '0');
                        }
                        if (last == mask) {
                            startsWith[at][len][mask] = 1;
                        }
                    }
                } else {
                    if (length[a[at]] >= len) {
                        if (checkStartsWith(a[at], len, mask)) {
                            startsWith[at][len][mask] = 1;
                        }
                    } else {
                        if (checkEndsWith(a[at], length[a[at]], mask >> (len - length[a[at]])) && checkStartsWith(b[at], len - length[a[at]], mask & ((1 << (len - length[a[at]])) - 1))) {
                            startsWith[at][len][mask] = 1;
                        }
                    }
                }
            }
            return startsWith[at][len][mask] == 1;
        }

        private boolean checkEndsWith(int at, int len, int mask) {
            if (len == 0) throw new RuntimeException();
            if (endsWith[at][len] == null) endsWith[at][len] = new byte[1 << len];
            if (endsWith[at][len][mask] == 0) {
                endsWith[at][len][mask] = -1;
                if (at < n) {
                    if (len <= length[at]) {
                        int last = 0;
                        for (int pos = length[at] - len; pos < length[at]; ++pos) {
                            last = last * 2 + (s[at].charAt(pos) - '0');
                        }
                        if (last == mask) {
                            endsWith[at][len][mask] = 1;
                        }
                    }
                } else {
                    if (length[b[at]] >= len) {
                        if (checkEndsWith(b[at], len, mask)) {
                            endsWith[at][len][mask] = 1;
                        }
                    } else {
                        if (checkEndsWith(a[at], len - length[b[at]], mask >> (length[b[at]])) && checkStartsWith(b[at], length[b[at]], mask & ((1 << length[b[at]]) - 1))) {
                            endsWith[at][len][mask] = 1;
                        }
                    }
                }
            }
            return endsWith[at][len][mask] == 1;
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