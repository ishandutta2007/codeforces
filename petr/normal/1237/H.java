import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Random;
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
        TaskH solver = new TaskH();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskH {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String a = in.next();
            String b = in.next();
            int n = a.length();
            int half = n / 2;
            int[] akind = getKinds(a, half);
            int[] bkind = getKinds(b, half);
            int[] cnt = new int[4];
            for (int x : akind) ++cnt[x];
            for (int x : bkind) --cnt[x];
            if (cnt[0] != 0 || cnt[3] != 0) {
                out.println(-1);
                return;
            }
            Random random = new Random(7415353151L);
            failed:
            while (true) {
                akind = getKinds(a, half);
                bkind = getKinds(b, half);
                int[] res = new int[a.length() + 1];
                int resLen = 0;
                for (int i = half - 1; i >= 0; --i) {
                    int what = bkind[i];
                    if (akind[i] == bkind[i]) continue;
                    if (resLen >= res.length) continue failed;
                    int what2 = what;
                    if (what == 1 || what == 2) what2 ^= 3;
                    if (akind[0] == what2) {
                        res[resLen++] = i + 1;
                        reverse(akind, i + 1);
                        if (akind[i] != bkind[i]) throw new RuntimeException();
                        continue;
                    }
                    if (resLen + 1 >= res.length) continue failed;
                    int poolSize = 0;
                    int bj = -1;
                    for (int j = 0; j <= i; ++j)
                        if (akind[j] == what) {
                            ++poolSize;
                            if (random.nextInt(poolSize) == 0) bj = j;
                        }
                    if (bj >= 0) {
                        res[resLen++] = bj + 1;
                        reverse(akind, bj + 1);
                        res[resLen++] = i + 1;
                        reverse(akind, i + 1);
                        if (akind[i] != bkind[i]) throw new RuntimeException();
                        continue;
                    }
                    if (resLen + 2 >= res.length) continue failed;
                    bj = -1;
                    int lj = -1;
                    for (int j = 0; j <= i; ++j)
                        if (akind[j] == what2) {
                            ++poolSize;
                            if (random.nextInt(poolSize) == 0) bj = j;
                            lj = j;
                        }
                    if (bj >= 0) {
                        if (random.nextInt(4) == 0) bj = lj;
                        res[resLen++] = bj + 1;
                        reverse(akind, bj + 1);
                        res[resLen++] = 1;
                        reverse(akind, 1);
                        res[resLen++] = i + 1;
                        reverse(akind, i + 1);
                        if (akind[i] != bkind[i]) throw new RuntimeException();
                        continue;
                    } else {
                        throw new RuntimeException();
                    }
                }
                out.println(resLen);
                for (int i = 0; i < resLen; ++i) {
                    out.print(res[i] * 2 + " ");
                }
                out.println();
                break;
            }
        }

        private void reverse(int[] akind, int size) {
            for (int i = 0, j = size - 1; i < j; ++i, --j) {
                int t = akind[i];
                akind[i] = akind[j];
                akind[j] = t;
            }
            for (int i = 0; i < size; ++i) {
                if (akind[i] == 1 || akind[i] == 2) akind[i] ^= 3;
            }
        }

        private int[] getKinds(String a, int half) {
            int[] akind = new int[half];
            for (int i = 0; i < a.length(); i += 2) {
                int v = a.charAt(i) - '0';
                v *= 2;
                v += a.charAt(i + 1) - '0';
                akind[i / 2] = v;
            }
            return akind;
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