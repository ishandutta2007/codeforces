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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int INF = (int) 1.01e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int len = in.nextInt();
            int n1 = in.nextInt();
            int n2 = in.nextInt();
            int t = in.nextInt();
            int[] x1 = new int[n1 + 1];
            for (int i = 0; i < n1; ++i) x1[i] = in.nextInt();
            x1[n1] = len + 2;
            int[] x2 = new int[n2 + 1];
            for (int i = 0; i < n2; ++i) x2[i] = in.nextInt();
            x2[n2] = len + 2;
            int[][] x = new int[][]{x1, x2};
            int best1 = -t;
            int best2 = -t;
            int[] ats = new int[10 + 2 * (n1 + n2)];
            boolean[] best1Jump = new boolean[ats.length];
            boolean[] best2Jump = new boolean[ats.length];
            best2Jump[0] = true;
            int[] best1History = new int[ats.length];
            int[] best2History = new int[ats.length];
            int at = 0;
            int nats = 0;
            n1 = 0;
            n2 = 0;
            while (at <= len) {
                ats[nats] = at;
                best1History[nats] = best1;
                best2History[nats] = best2;
                boolean ob1 = false;
                if (x1[n1] == at) {
                    ob1 = true;
                    if (best1 >= 1) {
                        best1 -= t;
                    } else {
                        best1 = -INF;
                    }
                    ++n1;
                }
                boolean ob2 = false;
                if (x2[n2] == at) {
                    ob2 = true;
                    if (best2 >= 1) {
                        best2 -= t;
                    } else {
                        best2 = -INF;
                    }
                    ++n2;
                }
                int nxt;
                if (ob1 || ob2) {
                    nxt = at + 1;
                } else {
                    nxt = Math.min(len + 1, Math.min(x1[n1], x2[n2]));
                }
                int travel = nxt - at;
                if (!ob2 && best1 > -INF && Math.min(0, best1) > best2) {
                    best2 = Math.min(0, best1);
                    best2Jump[nats] = true;
                }
                if (!ob1 && best2 > -INF && Math.min(0, best2) > best1) {
                    best1 = Math.min(0, best2);
                    best1Jump[nats] = true;
                }
                if (best1 > -INF) best1 += travel;
                if (best2 > -INF) best2 += travel;
                at += travel;
                ++nats;
            }
            ats[nats] = at;
            if (best1 > -INF || best2 > -INF) {
                out.println("Yes");
                int row = (best1 > -INF) ? 1 : 2;
                int[] jumps = new int[ats.length];
                int njumps = 0;
                int[] shotsX = new int[ats.length];
                int[] shotsY = new int[ats.length];
                int nshots = 0;
                while (at > 0) {
                    --nats;
                    at = ats[nats];
                    if (row == 1) {
                        if (best1Jump[nats]) {
                            jumps[njumps++] = at;
                            row = 2;
                        }
                    } else {
                        if (best2Jump[nats]) {
                            jumps[njumps++] = at;
                            row = 1;
                        }
                    }
                    if (n1 > 0 && x1[n1 - 1] == at) {
                        if (row == 1) {
                            shotsX[nshots] = at - best1History[nats];
                            shotsY[nshots++] = 1;
                        }
                        --n1;
                    }
                    if (n2 > 0 && x2[n2 - 1] == at) {
                        if (row == 2) {
                            shotsX[nshots] = at - best2History[nats];
                            shotsY[nshots++] = 2;
                        }
                        --n2;
                    }
                }
                if (n1 != 0 || n2 != 0) throw new RuntimeException();
                out.println(njumps);
                for (int i = 0; i < njumps; ++i) {
                    out.print(jumps[njumps - 1 - i] + " ");
                }
                out.println();
                out.println(nshots);
                for (int i = 0; i < nshots; ++i) {
                    out.println(shotsX[nshots - 1 - i] + " " + shotsY[nshots - 1 - i]);
                }
            } else {
                out.println("No");
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