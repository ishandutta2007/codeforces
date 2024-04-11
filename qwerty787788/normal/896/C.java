import java.io.*;
import java.util.*;

public class C {
    private FastScanner in;
    private PrintWriter out;

    long seed;

    int vmax;

    long[] a;
    int n;

    final long mod = 1000000007;

    long rnd() {
        long ret = seed;
        seed = (seed * 7 + 13) % mod;
        return ret;
    }

    class Block implements Comparable<Block> {
        int from, to;
        long value;

        public Block(int from, int to, long value) {
            this.from = from;
            this.to = to;
            this.value = value;
        }

        @Override
        public int compareTo(Block o) {
            return Long.compare(value, o.value);
        }

        @Override
        public String toString() {
            return "{" +
                    "" + from +
                    ", " + to +
                    "=" + value +
                    '}';
        }
    }


    Block[] blocks;
    int blockSz;

    void splitBy(int r) {
//        System.err.println("split by " + r);
        for (int i = 0; i < blockSz; i++) {
            if (blocks[i].to > r && blocks[i].from <= r) {
                for (int j = blockSz; j > i; j--) {
                    blocks[j] = blocks[j - 1];
                }
                blockSz++;
                blocks[i + 1] = new Block(r + 1, blocks[i].to, blocks[i].value);
                blocks[i].to = r;
                break;
            }
        }
    }

    void op1(int l, int r, int x) {
        for (int i = 0; i < blockSz; i++) {
            if (blocks[i].from >= l && blocks[i].to <= r) {
                blocks[i].value += x;
            }
            if (blocks[i].from > r) {
                break;
            }
        }
    }

    void op2(int l, int r, int x) {
        for (int i = 0; i < blockSz; i++) {
            if (blocks[i].from == l) {
                blocks[i].to = r;
                blocks[i].value = x;
                int j = i + 1;
                while (j != blockSz && blocks[j].from <= r) {
                    j++;
                }
                int shift = j - (i + 1);
                for (int k = j; k < blockSz; k++) {
                    blocks[k - shift] = blocks[k];
                }
                blockSz -= shift;
                break;
            }
        }
    }

    long op3(int l, int r, int x) {
        int tmpSz = 0;
        for (int i = 0; i < blockSz; i++) {
            if (blocks[i].from >= l && blocks[i].to <= r) {
                tmp[tmpSz++] = blocks[i];
            }
        }
        Arrays.sort(tmp, 0, tmpSz);
        x--;
        for (int i = 0; i < tmpSz; i++) {
            int count = tmp[i].to - tmp[i].from + 1;
            if (x < count) {
                return tmp[i].value;
            } else {
                x -= count;
            }
        }
        throw new AssertionError();
    }

    long pow(long x, int y, long mod) {
        if (y == 0) {
            return 1 % mod;
        } else if (y == 1) {
            return x % mod;
        }
        long res = 1;
        long cur = x % mod;
        for (int it = 0; it < 30; it++) {
            if (((1 << it) & y) != 0) {
                res = res * cur % mod;
            }
            cur = cur * cur % mod;
        }
        return res;
    }

    long op4(int l, int r, int x, int y) {
        long res = 0;
        for (int i = 0; i < blockSz; i++) {
            if (blocks[i].from >= l && blocks[i].to <= r) {
                res += (blocks[i].to - blocks[i].from + 1) * pow(blocks[i].value % y, x, y);
            }
        }
        res %= y;
        return res;
    }

    Block[] tmp;

    private void solve() {
        n = in.nextInt();
//        long START = System.currentTimeMillis();
        int m = in.nextInt();
        seed = in.nextLong();
        vmax = in.nextInt();
        a = new long[n];
        tmp = new Block[n];
        for (int i = 0; i < n; i++) {
            a[i] = 1 + (rnd() % vmax);
        }
        blocks = new Block[n];
        for (int i = 0; i < n; i++) {
            blocks[i] = new Block(i, i, a[i]);
        }
        blockSz = n;
        for (int i = 0; i < m; i++) {
            long op = (rnd() % 4) + 1;
            int l = (int) (rnd() % n);
            int r = (int) (rnd() % n);
            if (l > r) {
                int tmp = l;
                l = r;
                r = tmp;
            }
            long x;
            if (op == 3) {
                x = 1 + (rnd() % (r - l + 1));
            } else {
                x = 1 + (rnd() % vmax);
            }
            long y = 0;
            if (op == 4) {
                y = (rnd() % vmax) + 1;
            }
            splitBy(l - 1);
            splitBy(r);
            if (op == 1) {
                op1(l, r, (int) x);
            } else if (op == 2) {
                op2(l, r, (int) x);
            } else if (op == 3) {
                long r1 = (op3(l, r, (int) x));
                out.println(r1);
            } else {
                long r2 = (op4(l, r, (int) x, (int) y));
                out.println(r2);
            }
        }
//        System.err.println(System.currentTimeMillis() - START);
    }

    private void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
        new C().runIO();
    }
}