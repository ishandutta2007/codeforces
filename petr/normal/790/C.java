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
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            int nk = 0;
            int nv = 0;
            int no = 0;
            int[] kpos = new int[n];
            int[] vpos = new int[n];
            int[] opos = new int[n];
            int[] snk = new int[n + 1];
            int[] snv = new int[n + 1];
            int[] sno = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                char ch = s.charAt(i);
                if (ch == 'V') {
                    vpos[nv++] = i;
                } else if (ch == 'K') {
                    kpos[nk++] = i;
                } else {
                    opos[no++] = i;
                }
                snk[i + 1] = nk;
                snv[i + 1] = nv;
                sno[i + 1] = no;
            }
            int[][][][] best = new int[2][nk + 1][nv + 1][no + 1];
            for (int[][][] x : best) for (int[][] y : x) for (int[] z : y) Arrays.fill(z, INF);
            best[0][0][0][0] = 0;
            for (int k = 0; k <= nk; ++k) {
                for (int v = 0; v <= nv; ++v) {
                    for (int o = 0; o <= no; ++o) {
                        for (int hv = 0; hv < 2; ++hv) {
                            int cur = best[hv][k][v][o];
                            if (k < nk && hv == 0) {
                                best[0][k + 1][v][o] = Math.min(best[0][k + 1][v][o], cur + Math.abs(snv[kpos[k]] - v) + Math.abs(sno[kpos[k]] - o));
                            }
                            if (v < nv) {
                                best[1][k][v + 1][o] = Math.min(best[1][k][v + 1][o], cur + Math.abs(snk[vpos[v]] - k) + Math.abs(sno[vpos[v]] - o));
                            }
                            if (o < no) {
                                best[0][k][v][o + 1] = Math.min(best[0][k][v][o + 1], cur + Math.abs(snv[opos[o]] - v) + Math.abs(snk[opos[o]] - k));
                            }
                        }
                    }
                }
            }
            out.println(Math.min(best[0][nk][nv][no], best[1][nk][nv][no]) / 2);
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