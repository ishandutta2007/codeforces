import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        Random random = new Random(751454315315L + System.currentTimeMillis());

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] t = new int[n];
            TaskE.Stone[] stones = new TaskE.Stone[n];
            for (int i = 0; i < n; ++i) {
                int pos = in.nextInt();
                stones[i] = new TaskE.Stone(pos, i + 1);
            }
            Arrays.sort(stones, new Comparator<TaskE.Stone>() {

                public int compare(TaskE.Stone o1, TaskE.Stone o2) {
                    return o1.where - o2.where;
                }
            });
            int[] s = new int[n];
            int[] sFrom = new int[n];
            for (int i = 0; i < n; ++i) {
                s[i] = stones[i].where;
                sFrom[i] = stones[i].index;
            }
            for (int i = 0; i < n; ++i) {
                t[i] = in.nextInt();
            }
            sortArray(t);

            int[] available = new int[n];
            int[] via = new int[n];
            int cnt = 0;

            int[] resI = new int[5 * n];
            int[] resJ = new int[5 * n];
            int[] resBy = new int[5 * n];
            int resPtr = 0;

            for (int i = 0; i < n; ++i) {
                int src = s[i];
                int dst = t[i];
                if (src < dst) {
                    available[cnt] = dst - src;
                    via[cnt] = i;
                    ++cnt;
                } else {
                    int need = src - dst;
                    while (need > 0 && cnt > 0) {
                        int by = Math.min(need, available[cnt - 1]);
                        resI[resPtr] = via[cnt - 1];
                        resJ[resPtr] = i;
                        resBy[resPtr] = by;
                        ++resPtr;
                        need -= by;
                        if (by == available[cnt - 1]) {
                            --cnt;
                        } else {
                            available[cnt - 1] -= by;
                        }
                    }
                    if (need > 0) {
                        out.println("NO");
                        return;
                    }
                }
            }

            if (cnt != 0) {
                out.println("NO");
                return;
            }
            out.println("YES");
            out.println(resPtr);
            for (int i = 0; i < resPtr; ++i) {
                out.println(sFrom[resI[i]] + " " + sFrom[resJ[i]] + " " + resBy[i]);
            }
        }

        private void sortArray(int[] s) {
            shuffle(s);
            Arrays.sort(s);
        }

        private void shuffle(int[] s) {
            for (int i = 0; i < s.length; ++i) {
                int j = random.nextInt(i + 1);
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }

        static class Stone {
            int where;
            int index;

            public Stone(int where, int index) {
                this.where = where;
                this.index = index;
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