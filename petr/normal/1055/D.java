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
        private static final String NO = "NO";
        private static final String YES = "YES";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String[] src = new String[n];
            String[] dst = new String[n];
            for (int i = 0; i < n; ++i) {
                src[i] = in.next();
            }
            for (int i = 0; i < n; ++i) {
                dst[i] = in.next();
            }
            String diffSrc = null;
            String diffDst = null;
            int[] diffStart = new int[n];
            Arrays.fill(diffStart, -1);
            int any = -1;
            for (int i = 0; i < n; ++i) {
                int last = -1;
                for (int j = 0; j < src[i].length(); ++j)
                    if (src[i].charAt(j) != dst[i].charAt(j)) {
                        any = i;
                        if (last < 0) {
                            diffStart[i] = j;
                        }
                        last = j;
                    }
                if (last >= 0) {
                    String ds = src[i].substring(diffStart[i], last + 1);
                    String dd = dst[i].substring(diffStart[i], last + 1);
                    if (diffSrc != null) {
                        if (!diffSrc.equals(ds) || !diffDst.equals(dd)) {
                            out.println(NO);
                            return;
                        }
                    } else {
                        diffSrc = ds;
                        diffDst = dd;
                    }
                }
            }
            int extraBefore = 0;
            int extraAfter = 0;
            outer:
            while (true) {
                char need = '?';
                for (int i = 0; i < n; ++i)
                    if (diffStart[i] >= 0) {
                        int pos = diffStart[i] - 1 - extraBefore;
                        if (pos < 0 || (need != '?' && need != src[i].charAt(pos))) {
                            break outer;
                        }
                        need = src[i].charAt(pos);
                    }
                ++extraBefore;
            }
            outer2:
            while (true) {
                char need = '?';
                for (int i = 0; i < n; ++i)
                    if (diffStart[i] >= 0) {
                        int pos = diffStart[i] + diffSrc.length() + extraAfter;
                        if (pos >= src[i].length() || (need != '?' && need != src[i].charAt(pos))) {
                            break outer2;
                        }
                        need = src[i].charAt(pos);
                    }
                ++extraAfter;
            }
            diffSrc = src[any].substring(diffStart[any] - extraBefore, diffStart[any] + diffSrc.length() + extraAfter);
            diffDst = dst[any].substring(diffStart[any] - extraBefore, diffStart[any] + diffDst.length() + extraAfter);
            int[] srcKmp = buildKmp(diffSrc);
            for (int i = 0; i < n; ++i) {
                int found = findFirst(src[i], diffSrc, srcKmp);
                if (diffStart[i] < 0) {
                    if (found >= 0) {
                        out.println(NO);
                        return;
                    }
                } else {
                    int expected = diffStart[i] - extraBefore;
                    if (found < 0 || found > expected) throw new RuntimeException();
                    if (found < expected) {
                        out.println(NO);
                        return;
                    }
                }
            }
            out.println(YES);
            out.println(diffSrc);
            out.println(diffDst);
        }

        private int findFirst(String big, String small, int[] smallKmp) {
            int j = 0;
            for (int i = 0; i < big.length(); ++i) {
                while (true) {
                    if (small.charAt(j) == big.charAt(i)) {
                        ++j;
                        break;
                    }
                    if (j == 0) break;
                    j = smallKmp[j];
                }
                if (j == small.length()) {
                    return i - small.length() + 1;
                }
            }
            return -1;
        }

        private int[] buildKmp(String small) {
            int[] kmp = new int[small.length() + 1];
            for (int i = 2; i <= small.length(); ++i) {
                int j = kmp[i - 1];
                while (true) {
                    if (small.charAt(j) == small.charAt(i - 1)) {
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}