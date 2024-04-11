import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long x = in.nextInt();
            long y = in.nextInt();
            City[] cities = new City[n];
            for (int i = 0; i < n; ++i) {
                cities[i] = new City(i);
            }
            for (int i = 0; i < n - 1; ++i) {
                City a = cities[in.nextInt() - 1];
                City b = cities[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            int e;
            if (x < y) {
                e = getMaxTreeEdges(cities);
            } else {
                e = getMinTreeEdges(cities);
            }
            out.println(e * x + (n - 1 - e) * y);
        }

        private int getMinTreeEdges(City[] cities) {
            if (cities.length <= 10) {
                int res = Integer.MAX_VALUE;
                boolean[][] e = new boolean[cities.length][cities.length];
                for (City x : cities)
                    for (City y : x.adj)
                        e[x.id][y.id] = true;
                boolean[] seen = new boolean[cities.length];
                for (int start = 0; start < cities.length; ++start) {
                    seen[start] = true;
                    res = Math.min(res, rec(start, seen, e));
                    seen[start] = false;
                }
                return res;
            } else {
                for (City x : cities)
                    if (x.adj.size() == cities.length - 1) {
                        return 1;
                    }
                return 0;
            }
        }

        private int rec(int start, boolean[] seen, boolean[][] e) {
            int res = Integer.MAX_VALUE;
            for (int i = 0; i < seen.length; ++i)
                if (!seen[i]) {
                    int extra = e[start][i] ? 1 : 0;
                    seen[i] = true;
                    res = Math.min(res, extra + rec(i, seen, e));
                    seen[i] = false;
                }
            if (res == Integer.MAX_VALUE) res = 0;
            return res;
        }

        private int getMaxTreeEdges(City[] cities) {
            cities[0].dfs(null);
            int paths = cities[0].answer;
            if (cities[0].alive) ++paths;
            return (cities.length - 1) - (paths - 1);
        }

        static class City {
            int id;
            List<City> adj = new ArrayList<>(1);
            int answer;
            boolean alive;

            public City(int id) {
                this.id = id;
            }

            public void dfs(City parent) {
                answer = 0;
                int children = 0;
                for (City c : adj) {
                    if (c == parent) continue;
                    c.dfs(this);
                    answer += c.answer;
                    if (c.alive) {
                        ++children;
                    }
                }
                alive = children <= 1;
                answer += Math.max(0, children - 1);
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