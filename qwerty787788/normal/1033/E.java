import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class E {
    FastScanner in;
    PrintWriter out;

    int ask(int[] vals) {
        if (vals.length <= 1) {
            return 0;
        }
        out.print("? " + vals.length);
        for (int x : vals) {
            out.print(" " + x);
        }
        out.println();
        out.flush();
        return in.nextInt();
    }

    int[] toArr(List<Integer> z) {
        int[] res = new int[z.size()];
        int sz = 0;
        for (int v : z) {
            res[sz++] = v;
        }
        return res;
    }

    boolean hasEdge(int v, int[] to) {
        int cnt = ask(to);
        int[] to2 = Arrays.copyOf(to, to.length + 1);
        to2[to2.length - 1] = v;
        int cnt2 = ask(to2);
        return cnt != cnt2;
    }

    int findEdge(int v, List<Integer> all, boolean iKnow) {
//        System.err.println("find edge " +v + " " + all + " " + iKnow);
        if (all.size() == 0) {
            return -1;
        }
        if (!iKnow) {
            if (!hasEdge(v, toArr(all))) {
                return -1;
            }
        }
        if (all.size() == 1) {
            return all.get(0);
        }
        List<Integer> half = new ArrayList<>();
        List<Integer> anotherHalf = new ArrayList<>();
        for (int i = 0; i < all.size(); i++) {
            if (i * 2 < all.size()) {
                half.add(all.get(i));
            } else {
                anotherHalf.add(all.get(i));
            }
        }
        int r = findEdge(v, half, false);
        if (r != -1) {
            return r;
        }
        return findEdge(v, anotherHalf, true);
    }

    void solve() {
        int n = in.nextInt();
        List<List<Integer>> sets = new ArrayList<>();
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int v = 1; v <= n; v++) {
//            System.err.println("add " + v);
            boolean[] connected = new boolean[sets.size()];
            while (true) {
                List<Integer> check = new ArrayList<>();
                for (int i = 0; i < connected.length; i++) {
                    if (!connected[i]) {
                        for (int u : sets.get(i)) {
                            check.add(u);
                        }
                    }
                }
                if (check.size() == 0) {
                    break;
                }
                int to = findEdge(v, check, false);
                if (to == -1) {
                    break;
                }
                g[v - 1].add(to - 1);
                g[to - 1].add(v - 1);
                for (int i = 0; i < connected.length; i++) {
                    if (sets.get(i).contains(to)) {
                        connected[i] = true;
                        break;
                    }
                }
            }
            List<Integer> newSet = new ArrayList<>();
            newSet.add(v);
            List<List<Integer>> resSets = new ArrayList<>();
            for (int i = 0; i < connected.length; i++) {
                if (connected[i]) {
                    for (int u : sets.get(i)) {
                        newSet.add(u);
                    }
                } else {
                    resSets.add(sets.get(i));
                }
            }
            resSets.add(newSet);
            sets = resSets;
        }
//        System.err.println("done!");
        if (sets.size() != 1) {
            throw new AssertionError();
        }
        int[] color = new int[n];
        colorIt(0, 1, color, g);
        List<Integer> first = new ArrayList<>();
        List<Integer> second = new ArrayList<>();
        for (int v = 0; v < n; v++) {
            if (color[v] == 1) {
                first.add(v + 1);
            } else {
                second.add(v + 1);
            }
        }
        int c1 = ask(toArr(first));
        int c2 = ask(toArr(second));
        if (c1 == 0 && c2 == 0) {
            out.println("Y " + first.size());
            for (int z : first) {
                out.print(z + " ");
            }
            out.println();
        } else {
            if (c1 != 0) {
                findEdgeInside(first, g);
            } else {
                findEdgeInside(second, g);
            }
        }
    }

    void findEdgeInside(List<Integer> group, List<Integer>[] g) {
        int left = -1, right = group.size();
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            int[] tt = new int[mid];
            for (int i = 0; i < mid; i++) {
                tt[i] = group.get(i);
            }
            if (ask(tt) > 0) {
                right = mid;
            } else {
                left = mid;
            }
        }
        right--;
        List<Integer> before = new ArrayList<>();
        for (int i = 0; i < right; i++) {
            before.add(group.get(i));
        }
        int pathFrom = group.get(right);
        int to = findEdge(pathFrom, before, true);
        if (to < 0) {
            throw new AssertionError();
        }
        List<Integer> path = new ArrayList<>();
        findPath(pathFrom - 1, to - 1, g, path, -1);
        if (path.size() % 2 == 0) {
            throw new AssertionError();
        }
        out.println("N " + path.size());
        for (int z : path) {
            out.print((z + 1) + " ");
        }
    }

    boolean findPath(int v, int need, List<Integer>[] g, List<Integer> ans, int p) {
        if (v == need) {
            ans.add(v);
            return true;
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (findPath(to, need, g, ans, v)) {
                ans.add(v);
                return true;
            }
        }
        return false;
    }

    void colorIt(int v, int curColor, int[] color, List<Integer>[] g) {
        if (color[v] != 0) {
            return;
        }
        color[v] = curColor;
        for (int to : g[v]) {
            colorIt(to, 3 - curColor, color, g);
        }
    }


    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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
        new E().runIO();
    }
}