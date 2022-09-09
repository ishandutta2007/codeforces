import java.io.*;
import java.util.*;

public class TestEuler {
    FastScanner in;
    PrintWriter out;

    class Road {
        int fr, to;
        boolean used;
        int id;
        char c;
        Road back;

        public Road(int fr, int to, boolean orientation, int id) {
            super();
            this.fr = fr;
            this.to = to;
            if (orientation)
                c = '+';
            else
                c = '-';
            this.id = id;
        }

    }

    ArrayList<Road>[] g;

    boolean[] was;

    void go(int v) {
        was[v] = true;
        for (Road r : g[v]) {
            if (!was[r.to])
                go(r.to);
        }
    }

    void solve() {
        int n = 7;
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt();
            int to = in.nextInt();
            Road r1 = new Road(fr, to, true, i + 1);
            Road r2 = new Road(to, fr, false, i + 1);
            r1.back = r2;
            r2.back = r1;
            g[fr].add(r1);
            g[to].add(r2);
        }
        was = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (g[i].size() != 0) {
                go(i);
                break;
            }
        }
        for (int i = 0; i < n; i++)
            if (g[i].size() != 0)
                if (!was[i]) {
                    out.println("No solution");
                    return;
                }
        int first = 0, times = 0;
        for (int i = 0; i < n; i++)
            if (g[i].size() != 0)
                first = i;
        for (int i = 0; i < n; i++) {
            if (g[i].size() % 2 != 0) {
                times++;
                first = i;
            }
        }
        if (times > 2 || times == 1) {
            out.println("No solution");
            return;
        }
        ArrayList<Integer> stack = new ArrayList<>();
        stack.add(first);
        ArrayList<Road> stackRoad = new ArrayList<>();
        while (stack.size() != 0) {
            int v = stack.get(stack.size() - 1);
            Road nextRoad = null;
            while (g[v].size() > 0) {
                nextRoad = g[v].remove(g[v].size() - 1);
                if (!nextRoad.used)
                    break;
            }
            if (nextRoad == null || nextRoad.used) {
                stack.remove(stack.size() - 1);
                if (stack.size() != 0) {
                    Road r = stackRoad.remove(stackRoad.size() - 1);
                    out.println(r.id + " " + r.back.c);
                }
            } else {
                nextRoad.used = true;
                nextRoad.back.used = true;
                stack.add(nextRoad.to);
                stackRoad.add(nextRoad);
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new TestEuler().runIO();
    }
}