import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
}

class TaskG {
    static class Cycle {
        List<Vertex> items = new ArrayList<Vertex>();

        public int[][] solve(int index) {
            int[][][] ways = new int[3][3][2];
            for (int[][] a : ways) for (int[] b : a) Arrays.fill(b, -1);
            ways[0][0][0] = 0;
            ways[1][1][1] = 0;
            ways[2][2][0] = 1;
            for (int i = 1; i < items.size(); ++i) {
                Vertex v = items.get((index + i) % items.size());
                int[][] child = v.solve(null, this);
                int[][][] nways = new int[3][3][ways[0][0].length + child[0].length - 1];
                for (int[][] a : nways) for (int[] b : a) Arrays.fill(b, -1);
                for (int first = 0; first < 3; ++first)
                    for (int us = 0; us < 3; ++us)
                        for (int him = 0; him < 3; ++him)
                            if (us * him != 2) {
                                for (int usOne = 0; usOne < ways[first][us].length; ++usOne) if (ways[first][us][usOne] >= 0)
                                    for (int himOne = 0; himOne < child[him].length; ++himOne) if (child[him][himOne] >= 0)
                                        nways[first][him][usOne + himOne] = Math.max(nways[first][him][usOne + himOne], ways[first][us][usOne] + child[him][himOne]);
                            }
                ways = nways;
            }
            int[][] res = new int[3][ways[0][0].length];
            for (int[] a : res) Arrays.fill(a, -1);
            for (int first = 0; first < 3; ++first)
                for (int us = 0; us < 3; ++us)
                    for (int usOne = 0; usOne < ways[first][us].length; ++usOne) if (ways[first][us][usOne] >= 0)
                        if (first * us != 2)
                            res[first][usOne] = Math.max(res[first][usOne], ways[first][us][usOne]);
            return res;
        }
    }

    static class VertexInCycle {
        Cycle cycle;
        int index;

        VertexInCycle(Cycle cycle, int index) {
            this.cycle = cycle;
            this.index = index;
        }
    }

    static class Vertex {
        int stackPos = -1;
        Set<Vertex> adj = new HashSet<Vertex>();
        List<VertexInCycle> cycles = new ArrayList<VertexInCycle>();

        void dfs(List<Vertex> stack) {
            stackPos = stack.size();
            stack.add(this);
            for (Vertex v : adj) {
                if (v.stackPos == -1) {
                    v.dfs(stack);
                } else if (v.stackPos >= 0 && v.stackPos != stack.size() - 2) {
                    Cycle cycle = new Cycle();
                    for (int i = v.stackPos; i < stack.size(); ++i) {
                        cycle.items.add(stack.get(i));
                    }
                    for (int i = 0; i < cycle.items.size(); ++i) {
                        cycle.items.get(i).cycles.add(new VertexInCycle(cycle, i));
                    }
                }
            }
            stack.remove(stack.size() - 1);
            stackPos = -2;
        }

        public int[][] solve(Vertex parent, Cycle parentCycle) {
            int[][] ways = new int[][]{
                    new int[]{0, -1},
                    new int[]{-1, 0},
                    new int[]{1, -1}
            };
            for (Vertex v : adj) {
                if (v == parent) continue;
                int[][] child = v.solve(this, null);
                int[][] nways = new int[3][ways[0].length + child[0].length - 1];
                for (int[] x : nways) Arrays.fill(x, -1);
                for (int us = 0; us < 3; ++us)
                    for (int him = 0; him < 3; ++him)
                        if (us * him != 2) {
                            for (int usOne = 0; usOne < ways[us].length; ++usOne) if (ways[us][usOne] >= 0)
                                for (int himOne = 0; himOne < child[him].length; ++himOne) if (child[him][himOne] >= 0)
                                    nways[us][usOne + himOne] = Math.max(nways[us][usOne + himOne], ways[us][usOne] + child[him][himOne]);
                        }
                ways = nways;
            }
            for (VertexInCycle cyc : cycles) {
                if (cyc.cycle == parentCycle) continue;
                int[][] child = cyc.cycle.solve(cyc.index);
                int[][] nways = new int[3][ways[0].length + child[0].length - 2];
                for (int[] x : nways) Arrays.fill(x, -1);
                for (int us = 0; us < 3; ++us)
                    for (int him = 0; him < 3; ++him)
                        if (us == him) {
                            for (int usOne = 0; usOne < ways[us].length; ++usOne) if (ways[us][usOne] >= 0)
                                for (int himOne = 0; himOne < child[him].length; ++himOne) if (child[him][himOne] >= 0)
                                    nways[us][usOne + himOne - (us == 1 ? 1 : 0)] = Math.max(nways[us][usOne + himOne - (us == 1 ? 1 : 0)], ways[us][usOne] + child[him][himOne] - (us == 2 ? 1 : 0));
                        }
                ways = nways;
            }
            return ways;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) v[i] = new Vertex();
        for (int i = 0; i < m; ++i) {
            Vertex a = v[in.nextInt() - 1];
            Vertex b = v[in.nextInt() - 1];
            a.adj.add(b);
            b.adj.add(a);
        }
        v[0].dfs(new ArrayList<Vertex>());
        for (Vertex vv : v) {
            for (VertexInCycle vic : vv.cycles) {
                Vertex a = vic.cycle.items.get((vic.index + 1) % vic.cycle.items.size());
                Vertex b = vic.cycle.items.get((vic.index + vic.cycle.items.size() - 1) % vic.cycle.items.size());
                vv.adj.remove(a);
                vv.adj.remove(b);
            }
        }
        Vertex sentinel = new Vertex();
        sentinel.adj.add(v[0]);
        v[0].adj.add(sentinel);
        int[][] res = sentinel.solve(null, null);
        for (int i = 0; i <= n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[0][i]);
        }
        out.println();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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