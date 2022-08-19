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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            boolean[] isRed = new boolean[n];
            int[] red = new int[n];
            int[] blue = new int[n];
            int cntRed = 0;
            for (int i = 0; i < n; ++i) {
                isRed[i] = in.next().equals("R");
                if (isRed[i]) ++cntRed;
                red[i] = in.nextInt();
                blue[i] = in.nextInt();
            }
            if (cntRed > n / 2) {
                for (int i = 0; i < n; ++i) {
                    isRed[i] = !isRed[i];
                    int t = red[i];
                    red[i] = blue[i];
                    blue[i] = t;
                }
                cntRed = n - cntRed;
            }
            byte[][] minBlueWaste = new byte[1 << n][((n - 1) + (n - cntRed)) * cntRed / 2 + 1];
            for (byte[] x : minBlueWaste) Arrays.fill(x, Byte.MAX_VALUE);
            minBlueWaste[0][0] = 0;
            for (int set = 0; set < (1 << n); ++set) {
                byte[] old = minBlueWaste[set];
                int numRed = 0;
                int numBlue = 0;
                for (int nxt = 0; nxt < n; ++nxt)
                    if ((set & (1 << nxt)) != 0) {
                        if (isRed[nxt]) ++numRed;
                        else ++numBlue;
                    }
                int extraBlueWaste = 0;
                int extraRedWaste = 0;
                for (int nxt = 0; nxt < n; ++nxt)
                    if ((set & (1 << nxt)) == 0) {
                        if (red[nxt] <= numRed) {
                            ++extraRedWaste;
                        }
                        if (blue[nxt] <= numBlue) {
                            ++extraBlueWaste;
                        }
                    }
                for (int nxt = 0; nxt < n; ++nxt)
                    if ((set & (1 << nxt)) == 0) {
                        int gotBlueWaste = extraBlueWaste;
                        int gotRedWaste = extraRedWaste;
                        if (red[nxt] <= numRed) {
                            --gotRedWaste;
                        }
                        if (blue[nxt] <= numBlue) {
                            --gotBlueWaste;
                        }
                        byte[] dst = minBlueWaste[set | (1 << nxt)];
                        for (int ow = 0; ow < old.length; ++ow)
                            if (old[ow] < Byte.MAX_VALUE) {
                                if (isRed[nxt]) {
                                    dst[ow + gotRedWaste] = (byte) Math.min(dst[ow + gotRedWaste], old[ow] + (n - cntRed - numBlue));
                                } else {
                                    dst[ow + cntRed - numRed] = (byte) Math.min(dst[ow + cntRed - numRed], old[ow] + gotBlueWaste);
                                }
                            }
                    }
            }
            int totalRed = 0;
            int totalBlue = 0;
            for (int x : red) totalRed += x;
            for (int x : blue) totalBlue += x;
            byte[] fin = minBlueWaste[(1 << n) - 1];
            int res = Integer.MAX_VALUE;
            for (int ow = 0; ow < fin.length; ++ow)
                if (fin[ow] < Byte.MAX_VALUE) {
                    int gotRed = totalRed + ow - (n - 1 + n - cntRed) * cntRed / 2;
                    int gotBlue = totalBlue + fin[ow] - (n - 1 + cntRed) * (n - cntRed) / 2;
                    res = Math.min(res, Math.max(gotRed, gotBlue) + n);
                }
            out.println(res);
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