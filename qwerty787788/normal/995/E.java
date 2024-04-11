import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int mod;

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int pw(int x, int y) {
        if (y == 0) {
            return 1;
        }
        int z = pw(x, y / 2);
        z = mul(z, z);
        if (y % 2 == 1) {
            z = mul(z, x);
        }
        return z;
    }

    boolean go(int x, int moreMoves) {
        System.err.println("!! " + x + " " + moreMoves);
        if (moreMoves < 0) {
            return false;
        }
        if (x <= moreMoves) {
            return true;
        }
        if (moreMoves == 0) {
            return false;
        }
        int bestSub = 0;
        double bestF = 1;
        for (int sub = 0; sub <= 10; sub++) {
            if (x - sub <= 0) {
                break;
            }
            int inv = pw(x - sub, mod - 2);
            double f = x / (double) inv / (sub + 1);
            if (f > bestF) {
                bestF = f;
                bestSub = sub;
            }
        }
        return go(pw(x - bestSub, mod - 2), moreMoves - bestSub - 1);
    }

    class O {
        int value;
        O prev;
        int f;
        int len;

        public O(int value, O prev, int f, int len) {
            this.value = value;
            this.prev = prev;
            this.f = f;
            this.len = len;
        }
    }

    final int MAX = (int) 3e5;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod): x;
    }

    HashMap<Integer, O> bfs(int from){
        HashMap<Integer, O> hm = new HashMap<>();
        List<O> l = new ArrayList<>();
        O o = new O(from, null, -1, 0);
        hm.put(from, o);
        l.add(o);
        for (int it = 0; it < l.size() && l.size() < MAX; it++) {
            O cur = l.get(it);
//            System.err.println("len = "+  cur.len);
            for (int f = 0; f < 3; f++) {
                int nvalue = cur.value;
                if (f == 0) {
                    nvalue = add(nvalue, 1);
                } else if (f == 1) {
                    nvalue = sub(nvalue, 1);
                } else {
                    nvalue = pw(nvalue, mod - 2);
                }
                if (!hm.containsKey(nvalue)) {
                    O nO = new O(nvalue, cur, f + 1, cur.len + 1);
                    l.add(nO);
                    hm.put(nvalue, nO);
                }
            }
        }
        return hm;
    }

    List<Integer> getList(O o) {
        List<Integer> result = new ArrayList<>();
        while (o.prev != null) {
            result.add(o.f);
            o = o.prev;
        }
        Collections.reverse(result);
        return result;
    }

    void solve() {
        int x =in.nextInt();
        int y = in.nextInt();
        mod = in.nextInt();
        HashMap<Integer, O> hmF = bfs(x);
        HashMap<Integer, O> hmS = bfs(y);
        for (Map.Entry<Integer, O> entry : hmS.entrySet()) {
            if (hmF.containsKey(entry.getKey())) {
                List<Integer> first = getList(hmF.get(entry.getKey()));
                List<Integer> second = getList(entry.getValue());
                Collections.reverse(second);
                for (int xx : second) {
                    int yy = xx;
                    if (yy < 3) {
                        yy = 3 - yy;
                    }
                    first.add(yy);
                }
                out.println(first.size());
                for (int xx : first) {
                    out.print(xx + " ");
                }
                return;
            }
        }
        throw new AssertionError();
    }

    void solve123() {
        Random rnd = new Random(123);
        for (int it =0 ; it < 100; it++) {
            System.err.println("!it = " + it);
            mod = (int) 1e9 + 7;
            int x = rnd.nextInt(mod);
            int y = rnd.nextInt(mod);
            HashMap<Integer, O> hmF = bfs(x);
            HashMap<Integer, O> hmS = bfs(y);
            boolean ok = false;
            for (Map.Entry<Integer, O> entry : hmS.entrySet()) {
                if (hmF.containsKey(entry.getKey())) {
                    ok = true;
                }
            }
            if (!ok)
            throw new AssertionError();
        }
    }

    class Move {
        int carId;
        int x, y;

        public Move(int carId, int x, int y) {
            this.carId = carId;
            this.x = x;
            this.y = y;
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