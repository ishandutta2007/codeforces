import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int[] parent;
    int[] parentSameColor;
    int[] sizeWhite;
    int[] sizeBlack;
    boolean[] canChangeColor;
    int[] color;

    int res;

    int getRoot(int id) {
        if (parent[id] != id) {
            getColor(parent[id]);
            parentSameColor[id] ^= parentSameColor[parent[id]];
            parent[id] = parent[parent[id]];
        }
        return parent[id];
    }

    int getColor(int id) {
        if (parent[id] != id) {
            getColor(parent[id]);
            parentSameColor[id] ^= parentSameColor[parent[id]];
            parent[id] = parent[parent[id]];
        }
        return color[parent[id]] ^ parentSameColor[id];
    }

    void fixColor(int v) {
        v = getRoot(v);
        canChangeColor[v] = false;
    }

    void swapColor(int v) {
        v = getRoot(v);
        if (!canChangeColor[v]) {
            throw new AssertionError();
        }
        res -= sizeBlack[v];
        res += sizeWhite[v];
        int tmp = sizeBlack[v];
        sizeBlack[v] = sizeWhite[v];
        sizeWhite[v] = tmp;
        color[v] = 1 - color[v];
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        boolean[] on = new boolean[n];
        String s = in.next();
        for (int i = 0; i < n; i++) {
            on[i] = s.charAt(i) == '1';
        }
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < k; i++) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; j++) {
                g[in.nextInt() - 1].add(i);
            }
        }
        parent = new int[k];
        color =new int[k];
        for (int i = 0; i < k; i++) {
            parent[i] = i;
        }
        parentSameColor = new int[k];
        sizeBlack = new int[k];
        sizeWhite = new int[k];
        Arrays.fill(sizeWhite, 1);
        canChangeColor = new boolean[k];
        Arrays.fill(canChangeColor, true);
        for (int i = 0; i < n; i++) {
            int curColor = on[i] ? 1 : 0;
            if (g[i].isEmpty()) {
                if (curColor != 1) {
                    throw new AssertionError();
                }
            } else if (g[i].size() == 1) {
                int comp = g[i].get(0);
                curColor ^= getColor(comp);
                if (curColor != 1) {
                    swapColor(comp);
                }
                fixColor(comp);
            } else if (g[i].size() == 2) {
                int v1 = g[i].get(0), v2 = g[i].get(1);
                curColor ^= getColor(v1);
                curColor ^= getColor(v2);
                v1 = getRoot(v1);
                v2 = getRoot(v2);
                if (curColor != 1) {
                    if (v1 == v2) {
                        throw new AssertionError();
                    }
                    if (!canChangeColor[v1] && !canChangeColor[v2]) {
                        throw new AssertionError();
                    }
                    if (!canChangeColor[v1]) {
                        swapColor(v2);
                    } else if (!canChangeColor[v2]) {
                        swapColor(v1);
                    } else {
                        int v1SwapCost = sizeWhite[v1] - sizeBlack[v1];
                        int v2SwapCost = sizeWhite[v2] - sizeBlack[v2];
                        if (v1SwapCost < v2SwapCost) {
                            swapColor(v1);
                        } else {
                            swapColor(v2);
                        }
                    }
                }
                if (v1 != v2) {
                    parentSameColor[v1] = getColor(v1) ^ getColor(v2);
                    parent[v1] = v2;
//                    if (parentSameColor[v1] == 0) {
                        sizeBlack[v2] += sizeBlack[v1];
                        sizeWhite[v2] += sizeWhite[v1];
//                    } else {
//                        sizeBlack[v2] += sizeWhite[v1];
//                        sizeWhite[v2] += sizeBlack[v1];
//                    }
                    canChangeColor[v2] &= canChangeColor[v1];
                }
            } else {
                throw new AssertionError();
            }
            out.println(res);
//            System.err.println(i + " " +  res + " " + Arrays.toString(parent) + " " + Arrays.toString(sizeWhite) + " " + Arrays.toString(sizeBlack));
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
        new A().runIO();
    }
}