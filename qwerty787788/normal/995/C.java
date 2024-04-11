import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class Vector {
        int x, y;
        int id;
        int mul;
        Vector left, right;

        @Override
        public String toString() {
            return "Vector{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }

        Vector(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
            this.mul = 1;
        }

        void go(int[] res, int curMul) {
            curMul *= mul;
            if (id < 0) {
                left.go(res, curMul);
                right.go(res, curMul);
            } else {
                res[id] = curMul;
            }
        }

        Vector(Vector v1, Vector v2, int mul) {
            left = v1;
            right = v2;
            right.mul = mul;
            this.mul = 1;
            id = -1;
            x = v1.x + v2.x * mul;
            y = v1.y + v2.y * mul;
        }
    }

    final int MAX = (int) 1e6;

    boolean ok(Vector a, Vector b, int mul) {
        int nx = a.x + b.x * mul;
        int ny = a.y + b.y * mul;
        return nx * 1L * nx + ny * 1L * ny <= MAX * 1L * MAX;
    }

    void solve() {
        int n = in.nextInt();
        List<Vector> all = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Vector cur = new Vector(i, in.nextInt(), in.nextInt());
            all.add(cur);
            while (true) {
                boolean found = false;
                for (int x = 0; x < all.size(); x++) {
                    if (found) {
                        break;
                    }
                    for (int y = x + 1; y < all.size(); y++) {
                        if (found) {
                            break;
                        }
                        for (int m = -1; m <= 1; m += 2) {
                            if (found) {
                                break;
                            }
                            if (ok(all.get(x), all.get(y), m)) {
                                Vector newOne = new Vector(all.get(x), all.get(y), m);
                                all.remove(y);
                                all.remove(x);
                                all.add(newOne);
                                found = true;
                            }
                        }
                    }
                }
                if (!found) {
                    break;
                }
            }
        }
        for (int mask = 0; mask < 1 << all.size(); mask++) {
            int nx = 0, ny = 0;
            for (int i = 0; i < all.size(); i++) {
                Vector c = all.get(i);
                if (((1 << i) & mask) != 0) {
                    nx += c.x;
                    ny += c.y;
                    c.mul = 1;
                } else {
                    nx -= c.x;
                    ny -= c.y;
                    c.mul = -1;
                }
            }
            final int M2 = (int) (1.5 * MAX);
            if (nx * 1L * nx + ny * 1L * ny <= M2 * 1L * M2) {
                int[] res = new int[n];
                for (Vector v : all) {
                    v.go(res, 1);
                }
                for (int x : res) {
                    out.print(x + " ");
                }
                out.println();
                return;
            }
        }
        throw new AssertionError();
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