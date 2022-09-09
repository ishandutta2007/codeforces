import java.io.*;
import java.util.*;

public class ELol {
    FastScanner in;
    PrintWriter out;

    boolean end() {
        return System.currentTimeMillis() - START > 800;
    }

    long START;

    void solve() {
        in.nextInt();
        int m = in.nextInt();
        if (m == 0) {
            out.println(0)
            ;
            return;
        }
        START = System.currentTimeMillis();
        int[][] rect = new int[m][4];
        Compress xx = new Compress();
        Compress yy = new Compress();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 4; j++) {
                rect[i][j] = in.nextInt();
            }
            xx.add(rect[i][0]);
            xx.add(rect[i][2] + 1);

            yy.add(rect[i][1]);
            yy.add(rect[i][3] + 1);
        }
        xx.prepare();
        yy.prepare();
        for (int i = 0; i < m; i++) {
            rect[i][0] = xx.hm.get(rect[i][0]);
            rect[i][1] = yy.hm.get(rect[i][1]);
            rect[i][2] = xx.hm.get(rect[i][2] + 1);
            rect[i][3] = yy.hm.get(rect[i][3] + 1);
        }
        int[] color = new int[m];
        Random rnd = new Random(123);
        int[][] delta = new int[2][];
        int[] deltaX = new int[xx.vals.size()];
        int[] deltaY = new int[yy.vals.size()];
        delta[0] = deltaX;
        delta[1] = deltaY;
        Compress[] cc = new Compress[]{xx, yy};
        int res = Integer.MAX_VALUE;
        while (!end()) {
            for (int i = 0; i < m; i++) {
                color[i] = rnd.nextInt(2);
            }
            Arrays.fill(deltaX, 0);
            Arrays.fill(deltaY, 0);
            for (int i = 0; i < m; i++) {
                delta[color[i]][rect[i][color[i]]]++;
                delta[color[i]][rect[i][color[i] + 2]]--;
            }
            int curCost = getCost(delta, cc);
            res = Math.min(res, curCost);
            while (!end()) {
                boolean changed = false;
                for (int i = 0; i < m; i++) {
                    delta[color[i]][rect[i][color[i]]]--;
                    delta[color[i]][rect[i][color[i] + 2]]++;
                    color[i] = 1 - color[i];
                    delta[color[i]][rect[i][color[i]]]++;
                    delta[color[i]][rect[i][color[i] + 2]]--;
                    int ncost = getCost(delta, cc);
                    if (ncost > curCost) {
                        delta[color[i]][rect[i][color[i]]]--;
                        delta[color[i]][rect[i][color[i] + 2]]++;
                        color[i] = 1 - color[i];
                        delta[color[i]][rect[i][color[i]]]++;
                        delta[color[i]][rect[i][color[i] + 2]]--;
                    } else if (ncost < curCost) {
                        curCost = ncost;
                        res = Math.min(res, curCost);
                        changed = true;
                    }
                }
                if (!changed) {
                    break;
                }
            }
        }
        out.println(res);
    }

    int getCost(int[][] delta, Compress[] cc) {
        int r = 0;
        for (int i = 0; i < delta.length; i++) {
            int s = 0;
            for (int j = 0; j < delta[i].length; j++) {
                s += delta[i][j];
                if (s > 0) {
                    r += cc[i].cost[j];
                }
            }
        }
        return r;
    }


    class Compress {
        TreeSet<Integer> all;
        List<Integer> vals = new ArrayList<>();
        int[] cost;

        Compress() {
            all = new TreeSet<>();
        }

        void add(int x) {
            all.add(x);
        }

        HashMap<Integer, Integer> hm = new HashMap<>();

        void prepare() {
            int it = 0;
            for (int x : all) {
                hm.put(x, it++);
                vals.add(x);
            }
            cost = new int[vals.size() - 1];
            for (int i = 0; i < cost.length; i++) {
                cost[i] = vals.get(i + 1) - vals.get(i);
            }
        }

    }

    void run() {
        try {
            in = new FastScanner(new File("ELol.in"));
            out = new PrintWriter(new File("ELol.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new ELol().runIO();
    }
}