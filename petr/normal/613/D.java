import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static final int INF = (int) 1e9;
        static int[] parent;
        static int next;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Town[] towns = new Town[n];
            for (int i = 0; i < n; ++i) towns[i] = new Town();
            for (int i = 0; i < n - 1; ++i) {
                Town a = towns[in.nextInt() - 1];
                Town b = towns[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            parent = new int[n];
            next = 0;
            towns[0].dfs(-1);
            for (Town t : towns) {
                Collections.sort(t.adj);
            }
            int numQueries = in.nextInt();
            int[] res = new int[numQueries];
            List<int[]> plans = new ArrayList<>();
            for (int queryId = 0; queryId < numQueries; ++queryId) {
                int cnt = in.nextInt();
                if (cnt == 1) {
                    in.nextInt();
                    continue;
                } else if (cnt == 2) {
                    Town a = towns[in.nextInt() - 1];
                    Town b = towns[in.nextInt() - 1];
                    if (Collections.binarySearch(a.adj, b) >= 0) {
                        res[queryId] = -1;
                    } else {
                        res[queryId] = 1;
                    }
                } else {
                    int[] plan = new int[cnt + 1];
                    plan[0] = queryId;
                    for (int i = 1; i <= cnt; ++i) {
                        plan[i] = towns[in.nextInt() - 1].id;
                    }
                    plans.add(plan);
                }
            }

            long[] mask = new long[n];
            long[] upto = new long[n];
            long[] must = new long[n];
            int[] ress = new int[64];

            for (int start = 0; start < plans.size(); start += 64) {
                int cnt = Math.min(64, plans.size() - start);
                Arrays.fill(mask, 0);
                Arrays.fill(upto, 0);
                Arrays.fill(must, 0);
                Arrays.fill(ress, 0);
                for (int i = 0; i < cnt; ++i) {
                    int[] cp = plans.get(start + i);
                    for (int j = 1; j < cp.length; ++j) {
                        mask[cp[j]] |= 1L << i;
                    }
                }
                for (int i = n - 1; i >= 0; --i) {
                    if ((upto[i] & mask[i]) != 0) throw new RuntimeException();
                    upto[i] |= mask[i];
                    int p = parent[i];
                    if (p >= 0) {
                        must[i] |= mask[p] & upto[i];
                    }
                    long inter = must[i] & mask[i];
                    while (inter != 0) {
                        int j = Long.numberOfTrailingZeros(inter);
                        ress[j] = -INF;
                        inter ^= 1L << j;
                    }
                    upto[i] &= ~must[i];
                    long extra = must[i] & (~mask[i]);
                    while (extra != 0) {
                        int j = Long.numberOfTrailingZeros(extra);
                        ++ress[j];
                        extra ^= 1L << j;
                    }
                    if (p >= 0) {
                        long newMust = upto[i] & upto[p];
                        must[p] |= newMust;
                        upto[p] |= upto[i];
                    }
                }
                for (int i = 0; i < cnt; ++i) {
                    int[] cp = plans.get(start + i);
                    res[cp[0]] = ress[i];
                }
            }

            for (int x : res) {
                if (x < 0) x = -1;
                out.println(x);
            }
        }

        static class Town implements Comparable<Town> {
            int id = -1;
            List<Town> adj = new ArrayList<>();

            public void dfs(int from) {
                id = next++;
                parent[id] = from;
                for (Town t : adj) if (t.id < 0) t.dfs(id);
            }


            public int compareTo(Town o) {
                return id - o.id;
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