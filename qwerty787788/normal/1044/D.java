import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    HashMap<Integer, Integer> ids = new HashMap<>();

    final int MAX_Q = (int) 2e5 + 10;
    int[] parent = new int[MAX_Q * 2];
    int[] xorToParent = new int[MAX_Q * 2];
    int sz = 0;

    int getId(int x) {
        Integer r = ids.get(x);
        if (r != null) {
            return r;
        }
        parent[sz] = sz;
        xorToParent[sz] = 0;
        ids.put(x, sz);
        sz++;
        return sz - 1;
    }

    int get(int x) {
        if (parent[x] == x) {
            return x;
        }
        int nparent = get(parent[x]);
        xorToParent[x] ^= xorToParent[parent[x]];
        parent[x] = nparent;
//        System.err.println("get(" + x + ") = " + parent[x] + ", with xor = " + xorToParent[x]);
        return parent[x];
    }

    int getXor(int from, int to) {
        int root1 = get(from), root2 = get(to);
        if (root1 != root2) {
            return -1;
        }
        int r = xorToParent[from] ^ xorToParent[to];
//        System.err.println("xor " + from + " " + to + " = " + r);
        return r;
    }

    void setXor(int from, int to, int xor) {
//        System.err.println("Set " + from + " " + to + " " + xor);
        int oldParentFrom = parent[from];
        parent[parent[from]] = parent[to];
        if (xorToParent[parent[from]] != 0) {
            throw new AssertionError();
        }
        xorToParent[oldParentFrom] = xor ^ xorToParent[from] ^ xorToParent[to];
    }

    void solve() {
        int q = in.nextInt();
        int last = 0;
        for (int i = 0; i < q; i++) {
            int type = in.nextInt();

            int l = in.nextInt() ^ last;
            int r = in.nextInt() ^ last;
            if (l > r) {
                int tmp = l;
                l = r;
                r = tmp;
            }
            r++;
//            System.err.println("! " + l + " " + r);
            l = getId(l);
            r = getId(r);
            int realXor = getXor(l, r);
            if (type == 1) {
                int x = in.nextInt() ^ last;
                if (realXor == -1) {
                    setXor(l, r, x);
                }
            } else {
                out.println(realXor);
                last = Math.abs(realXor);
            }
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