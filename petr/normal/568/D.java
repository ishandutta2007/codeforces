import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        int[] resu;
        int[] resv;
        int resunused;
        Random random;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            random = new Random(543715351L + System.currentTimeMillis());
            int n = in.nextInt();
            int k = in.nextInt();
            TaskD.Line[] roads = new TaskD.Line[n];
            for (int i = 0; i < n; ++i) {
                roads[i] = new TaskD.Line();
                roads[i].index = i + 1;
                roads[i].a = in.nextInt();
                roads[i].b = in.nextInt();
                roads[i].c = in.nextInt();
            }
            resu = new int[k];
            resv = new int[k];
            resunused = -1;
            doit(roads, k);
            if (resunused < 0) {
                out.println("NO");
            } else {
                out.println("YES");
                out.println(k - resunused);
                for (int i = resunused; i < k; ++i) {
                    out.println(resu[i] + " " + resv[i]);
                }
            }
        }

        private void doit(TaskD.Line[] roads, int k) {
            if (roads.length > k * k) {
                if (k == 0) return;
                double pr = 1.0 - getPr(roads.length, k);
                int cnt = 0;
                double prod = 1;
                while (prod > 1e-10) {
                    prod *= pr;
                    ++cnt;
                }
                for (int step = 0; step < cnt; ++step) {
                    TaskD.Line p = roads[random.nextInt(roads.length)];
                    TaskD.Line q = roads[random.nextInt(roads.length)];
                    long denom = p.a * q.b - p.b * q.a;
                    if (denom == 0) continue;
                    long xnom = -(p.c * q.b - p.b * q.c);
                    long ynom = -(p.a * q.c - p.c * q.a);
                    int amt = 0;
                    for (TaskD.Line r : roads) {
                        if (r.a * xnom + r.b * ynom + r.c * denom == 0) {
                            ++amt;
                        }
                    }
                    if (amt > k) {
                        resu[k - 1] = p.index;
                        resv[k - 1] = q.index;
                        TaskD.Line[] remains = new TaskD.Line[roads.length - amt];
                        int ptr = 0;
                        for (TaskD.Line r : roads) {
                            if (r.a * xnom + r.b * ynom + r.c * denom != 0) {
                                remains[ptr++] = r;
                            }
                        }
                        doit(remains, k - 1);
                        return;
                    }
                }
            } else if (roads.length == 0) {
                resunused = k;
            } else {
                TaskD.Line p = roads[random.nextInt(roads.length)];
                boolean any = false;
                boolean[] mark = new boolean[roads.length];
                for (int qi = 0; qi < roads.length; ++qi)
                    if (!mark[qi]) {
                        TaskD.Line q = roads[qi];
                        long denom = p.a * q.b - p.b * q.a;
                        if (denom == 0) continue;
                        long xnom = -(p.c * q.b - p.b * q.c);
                        long ynom = -(p.a * q.c - p.c * q.a);
                        any = true;
                        int amt = 0;
                        for (int i = 0; i < roads.length; ++i) {
                            TaskD.Line r = roads[i];
                            if (r.a * xnom + r.b * ynom + r.c * denom == 0) {
                                ++amt;
                                mark[i] = true;
                            }
                        }
                        resu[k - 1] = p.index;
                        resv[k - 1] = q.index;
                        TaskD.Line[] remains = new TaskD.Line[roads.length - amt];
                        int ptr = 0;
                        for (TaskD.Line r : roads) {
                            if (r.a * xnom + r.b * ynom + r.c * denom != 0) {
                                remains[ptr++] = r;
                            }
                        }
                        doit(remains, k - 1);
                        if (resunused >= 0) return;
                    }
                if (!any) {
                    resu[k - 1] = p.index;
                    resv[k - 1] = -1;
                    TaskD.Line[] remains = new TaskD.Line[roads.length - 1];
                    int ptr = 0;
                    for (TaskD.Line r : roads) {
                        if (r != p) {
                            remains[ptr++] = r;
                        }
                    }
                    doit(remains, k - 1);
                }
            }
        }

        private double getPr(int n, int k) {
            long minPairs = Long.MAX_VALUE;
            for (int numSmall = 0; numSmall < k; ++numSmall) {
                int remains = n - k * numSmall;
                int numBig = k - numSmall;
                long numPairs = 0;
                for (int i = 0; i < numBig; ++i) {
                    long size = remains / numBig;
                    if (i < remains % numBig) ++size;
                    numPairs += size * (size - 1);
                }
                minPairs = Math.min(minPairs, numPairs);
            }
            return minPairs / (double) n / n;
        }

        static class Line {
            long a;
            long b;
            long c;
            int index;

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