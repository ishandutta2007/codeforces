import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            City[] cities = new City[n];
            for (int i = 0; i < n; ++i) {
                cities[i] = new City(i);
            }
            for (int i = 0; i < m; ++i) {
                City a = cities[in.nextInt() - 1];
                City b = cities[in.nextInt() - 1];
                a.outgo.add(b);
            }
            int[][] dd = new int[n][n];
            City[] q = new City[n];
            for (int i = 0; i < n; ++i) {
                for (City x : cities) {
                    x.dist = -1;
                }
                cities[i].dist = 0;
                int qt = 0;
                int qh = 1;
                q[0] = cities[i];
                while (qt < qh) {
                    City cur = q[qt++];
                    for (City other : cur.outgo) {
                        if (other.dist < 0) {
                            other.dist = cur.dist + 1;
                            q[qh++] = other;
                        }
                    }
                }
                for (int j = 0; j < n; ++j) {
                    dd[i][j] = cities[j].dist;
                }
            }

            int[] first = new int[n];
            int[] next = new int[n];
            for (int i = 0; i < n; ++i) {
                Arrays.fill(first, -1);
                for (int j = 0; j < n; ++j) {
                    int cd = dd[i][j];
                    if (cd < 0) continue;
                    next[j] = first[cd];
                    first[cd] = j;
                }
                int ptr = 0;
                outer:
                for (int cd = n - 1; cd >= 1; --cd) {
                    int cur = first[cd];
                    while (cur >= 0) {
                        cities[i].closestOut[ptr] = cities[cur];
                        ++ptr;
                        if (ptr == 3) break outer;
                        cur = next[cur];
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                Arrays.fill(first, -1);
                for (int j = 0; j < n; ++j) {
                    int cd = dd[j][i];
                    if (cd < 0) continue;
                    next[j] = first[cd];
                    first[cd] = j;
                }
                int ptr = 0;
                outer:
                for (int cd = n - 1; cd >= 1; --cd) {
                    int cur = first[cd];
                    while (cur >= 0) {
                        cities[i].closestIn[ptr] = cities[cur];
                        ++ptr;
                        if (ptr == 3) break outer;
                        cur = next[cur];
                    }
                }
            }

            City ra = null;
            City rb = null;
            City rc = null;
            City rd = null;
            int res = 0;

            for (City b : cities) {
                b.mark = true;
                for (City c : cities)
                    if (!c.mark) {
                        int bc = dd[b.index][c.index];
                        if (bc < 0) continue;
                        c.mark = true;
                        for (City a : b.closestIn)
                            if (a != null && !a.mark) {
                                int ab = dd[a.index][b.index];
                                if (ab < 0) continue;
                                a.mark = true;
                                for (City d : c.closestOut)
                                    if (d != null && !d.mark) {
                                        int cd = dd[c.index][d.index];
                                        if (cd < 0) continue;
                                        d.mark = true;
                                        int cur = ab + bc + cd;
                                        if (cur > res) {
                                            res = cur;
                                            ra = a;
                                            rb = b;
                                            rc = c;
                                            rd = d;
                                        }
                                        d.mark = false;
                                    }
                                a.mark = false;
                            }
                        c.mark = false;
                    }
                b.mark = false;
            }

            out.println((ra.index + 1) + " " + (rb.index + 1) + " " + (rc.index + 1) + " " + (rd.index + 1));
        }

        static class City {
            int index;
            int dist;
            List<City> outgo = new ArrayList<>(1);
            boolean mark = false;
            City[] closestIn = new City[3];
            City[] closestOut = new City[3];

            public City(int index) {
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