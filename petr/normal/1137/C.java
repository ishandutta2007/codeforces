import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        City[] seq;
        int seqPtr;
        int globalGcd;

        private int gcd(int a, int b) {
            while (b > 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        private List<Scc> findScc(City[] cities) {
            List<Scc> sccs = new ArrayList<>();
            seq = new City[cities.length];
            seqPtr = 0;
            for (City x : cities) if (!x.mark) x.dfs1();
            if (seqPtr != cities.length) throw new RuntimeException();
            for (int i = seqPtr - 1; i >= 0; --i) {
                City x = seq[i];
                if (!x.mark2) {
                    Scc scc = new Scc();
                    x.dfs2(scc);
                    sccs.add(scc);
                }
            }
            return sccs;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int d = in.nextInt();
            City[] cities = new City[n];
            for (int i = 0; i < n; ++i) cities[i] = new City();
            for (int i = 0; i < m; ++i) {
                City a = cities[in.nextInt() - 1];
                City b = cities[in.nextInt() - 1];
                a.outgo.add(b);
                b.incom.add(a);
            }
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                cities[i].open = new boolean[d];
                for (int j = 0; j < d; ++j) cities[i].open[j] = s.charAt(j) == '1';
            }
            List<Scc> sccs = findScc(cities);
            Collections.reverse(sccs);
            for (Scc scc : sccs) {
                globalGcd = d;
                City root = scc.cities.get(0);
                root.updateGlobalGcd(0, scc);
                int[] best = new int[globalGcd];
                int reps = d / globalGcd;
                for (City city : scc.cities) {
                    for (int inRoot = 0; inRoot < globalGcd; ++inRoot) {
                        for (int extra = 0; extra < reps; ++extra) {
                            int here = (inRoot + globalGcd * extra + city.mark3) % d;
                            if (city.open[here]) {
                                ++best[inRoot];
                                break;
                            }
                        }
                    }
                }
                int[] nbest = best.clone();
                for (City city : scc.cities) {
                    for (int inRoot = 0; inRoot < globalGcd; ++inRoot) {
                        for (int extra = 0; extra < reps; ++extra) {
                            int here = (inRoot + globalGcd * extra + city.mark3 + 1) % d;
                            for (City next : city.outgo)
                                if (next.scc != scc) {
                                    nbest[inRoot] = Math.max(nbest[inRoot], best[inRoot] + next.res[here]);
                                }
                        }
                    }
                }
                for (City city : scc.cities) {
                    city.res = new int[d];
                    for (int inRoot = 0; inRoot < globalGcd; ++inRoot) {
                        for (int extra = 0; extra < reps; ++extra) {
                            int here = (inRoot + globalGcd * extra + city.mark3) % d;
                            city.res[here] = nbest[inRoot];
                        }
                    }
                }
            }
            out.println(cities[0].res[0]);
        }

        class City {
            List<City> outgo = new ArrayList<City>();
            List<City> incom = new ArrayList<City>();
            boolean mark = false;
            boolean mark2 = false;
            int mark3 = -1;
            Scc scc;
            int[] res;
            boolean[] open;

            public void dfs1() {
                if (mark) return;
                mark = true;
                for (City x : outgo) x.dfs1();
                seq[seqPtr++] = this;
            }

            public void dfs2(Scc scc) {
                if (mark2) return;
                mark2 = true;
                this.scc = scc;
                scc.cities.add(this);
                for (City x : incom) x.dfs2(scc);
            }

            public void updateGlobalGcd(int val, Scc scc) {
                if (this.mark3 >= 0) {
                    globalGcd = gcd(globalGcd, Math.abs(val - this.mark3));
                    return;
                }
                this.mark3 = val;
                for (City x : outgo)
                    if (x.scc == scc) {
                        x.updateGlobalGcd(val + 1, scc);
                    }
            }

        }

        class Scc {
            List<City> cities = new ArrayList<>();

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