import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;
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
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        u = new int[n - 1];
        v = new int[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            u[i] = in.nextInt() - 1;
            v[i] = in.nextInt() - 1;
        }
        x = new int[n];
        y = new int[n];
        height = new double[n];
        double alpha = new Random(System.currentTimeMillis() + 5753).nextDouble() * 2 * Math.PI;
        double kx = Math.cos(alpha);
        double ky = Math.sin(alpha);
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            height[i] = kx * x[i] + ky * y[i];
        }
        /*if (n >= 100) {
            out.println("WA");
            return;
        }
        if (n < 100) {
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    for (int k = j + 1; k < n; ++k) {
                        long z = (x[j] - x[i]) * (long) (y[k] - y[i]) - (y[j] - y[i]) * (long) (x[k] - x[i]);
                        if (z == 0) while (true);
                     }
        }*/
        int mi = 0;
        for (int i = 1; i < n; ++i)
            if (height[i] > height[mi]) mi = i;
        res = new int[n];
        Integer[] ids = new Integer[n];
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }
        subtreeSize = new int[n];
        parseTree(0, -1);
        drawTree(0, -1, mi, ids);
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
	}
    
    int[] res;
    int[] u;
    int[] v;
    int[] x;
    int[] y;
    int[] subtreeSize;
    double[] height;
    

    private void parseTree(int root, int parent) {
        subtreeSize[root] = 1;
        for (int i = 0; i < u.length; ++i)
            if (u[i] == root || v[i] == root) {
                int other = u[i] + v[i] - root;
                if (other != parent) {
                    parseTree(other, root);
                    subtreeSize[root] += subtreeSize[other];
                }
            }
    }

    private void drawTree(int root, int parent, int rootTo, Integer[] ids) {
        /*for (int x : ids)
             if (height[x] > height[rootTo]) while (true);*/
        /*boolean seen = false;
        for (int x : ids) if (x == rootTo) seen = true;
        if (!seen) while (true);*/
        res[rootTo] = root + 1;
        Comparator<Integer> comp = new RelativeComparator(x[rootTo], y[rootTo], x, y);
        Arrays.sort(ids, comp);
        /*for (int i = 0; i + 1 < ids.length; ++i) {
            if (comp.compare(ids[i], ids[i + 1]) != -1)
                while (true);
        }*/
        int rootId = ids[0];
        if (rootId != rootTo) {
            //if ((x[rootTo] == x[ids[0]]) && (y[rootTo] == y[ids[0]])) while (true);
            throw new RuntimeException();
        }
        int ptr = 1;
        for (int i = 0; i < u.length; ++i)
            if (u[i] == root || v[i] == root) {
                int other = u[i] + v[i] - root;
                if (other != parent) {
                    int cnt = subtreeSize[other];
                    Integer[] nids = new Integer[cnt];
                    System.arraycopy(ids, ptr, nids, 0, cnt);
                    ptr += cnt;
                    int mi = nids[0];
                    for (int ii : nids) {
                        if (height[ii] > height[mi])
                            mi = ii;
                    }
                    drawTree(other, root, mi, nids);
                }
            }
        if (ptr != ids.length) throw new RuntimeException();
    }

    private static class RelativeComparator implements Comparator<Integer> {
        private int ox;
        private int oy;
        private int[] x;
        private int[] y;

        public RelativeComparator(int ox, int oy, int[] x, int[] y) {
            this.ox = ox;
            this.oy = oy;
            this.x = x;
            this.y = y;
        }

        public int compare(Integer a, Integer b) {
            long xa = x[a] - ox;
            long ya = y[a] - oy;
            long xb = x[b] - ox;
            long yb = y[b] - oy;
            long z = xa * (long) yb - xb * (long) ya;
            if (z == 0) {
                z = Math.abs(xa) + Math.abs(ya) - Math.abs(xb) - Math.abs(yb);
            }
            if (z > 0) 
                return 1;
            else if (z < 0)
                return -1;
            else
                return 0;
        }
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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