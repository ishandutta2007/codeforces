import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        private static final double INF = 1e100;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int numPools = in.nextInt();
            int totalBuy = in.nextInt();
            int numQueries = in.nextInt();
            Pool[] pools = new Pool[numPools];
            for (int i = 0; i < numPools; ++i) {
                pools[i] = new Pool(i);
            }
            for (Pool pool : pools) {
                pool.prize = in.nextInt();
            }
            for (Pool pool : pools) {
                pool.size = in.nextInt();
            }
            TreeSet<Pool> allByNext = new TreeSet<>(new Comparator<Pool>() {

                public int compare(Pool o1, Pool o2) {
                    int z = Double.compare(o1.nextBuyGives, o2.nextBuyGives);
                    if (z == 0) z = Integer.compare(o1.id, o2.id);
                    return z;
                }
            });
            TreeSet<Pool> allByLast = new TreeSet<>(new Comparator<Pool>() {

                public int compare(Pool o1, Pool o2) {
                    int z = Double.compare(o1.lastBuyGave, o2.lastBuyGave);
                    if (z == 0) z = Integer.compare(o1.id, o2.id);
                    return z;
                }
            });
            for (Pool pool : pools) {
                pool.update();
                allByNext.add(pool);
            }
            int totalBought = 0;
            for (int i = 0; i < totalBuy; ++i) {
                Pool p = allByNext.last();
                if (p.nextBuyGives == 0) break;
                allByNext.remove(p);
                ++totalBought;
                ++p.buying;
                p.update();
                allByNext.add(p);
            }
            double res = 0;
            for (Pool pool : pools) {
                res += pool.getGain();
                allByLast.add(pool);
            }
            for (int queryId = 0; queryId < numQueries; ++queryId) {
                int kind = in.nextInt();
                Pool which = pools[in.nextInt() - 1];
                allByNext.remove(which);
                allByLast.remove(which);
                res -= which.getGain();
                if (kind == 1) {
                    ++which.size;
                } else {
                    --which.size;
                }
                if (which.buying > which.size) {
                    --which.buying;
                    --totalBought;
                }
                which.update();
                outer:
                while (true) {
                    while (totalBought < totalBuy) {
                        if (allByNext.isEmpty() || which.nextBuyGives >= allByNext.last().nextBuyGives) {
                            if (which.nextBuyGives == 0) break outer;
                            ++which.buying;
                            ++totalBought;
                            which.update();
                        } else {
                            Pool p = allByNext.last();
                            allByNext.remove(p);
                            allByLast.remove(p);
                            res += p.nextBuyGives;
                            ++totalBought;
                            ++p.buying;
                            p.update();
                            allByNext.add(p);
                            allByLast.add(p);
                        }
                    }
                    if (!allByLast.isEmpty() && which.nextBuyGives > allByLast.first().lastBuyGave) {
                        Pool p = allByLast.first();
                        allByNext.remove(p);
                        allByLast.remove(p);
                        res -= p.lastBuyGave;
                        --totalBought;
                        --p.buying;
                        p.update();
                        allByNext.add(p);
                        allByLast.add(p);
                    } else if (!allByNext.isEmpty() && which.lastBuyGave < allByNext.last().nextBuyGives) {
                        --which.buying;
                        --totalBought;
                        which.update();
                    } else {
                        break;
                    }
                }
                res += which.getGain();
                allByNext.add(which);
                allByLast.add(which);
                out.println(String.format("%.15f", res));
            }
        }

        static class Pool {
            int id;
            int size;
            int prize;
            int buying;
            double nextBuyGives;
            double lastBuyGave;

            public Pool(int id) {
                this.id = id;
            }

            public void update() {
                if (buying == size) {
                    nextBuyGives = 0;
                } else {
                    nextBuyGives = (buying + 1) / (double) (buying + size + 1) - buying / (double) (buying + size);
                    nextBuyGives *= prize;
                }
                if (buying == 0) {
                    lastBuyGave = INF;
                } else {
                    lastBuyGave = -(buying - 1) / (double) (buying + size - 1) + buying / (double) (buying + size);
                    lastBuyGave *= prize;
                }
            }

            public double getGain() {
                return (buying) / (double) (buying + size) * prize;
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