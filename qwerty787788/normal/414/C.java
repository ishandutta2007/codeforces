import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long[] inv1, inv2;
    int[] tmp = new int[1 << 21];

    void go(int[] a, int l, int r, int h) {
        if (l == r) {
            return;
        } else {
            int m = (l + r) >> 1;
            m++;
            go(a, l, m - 1, h + 1);
            go(a, m, r, h + 1);
            {
                int it1 = l, it2 = m;
                int it = 0;
                while (it1 < m && it2 <= r) {
                    if (a[it1] <= a[it2]) {
                        tmp[it++] = a[it1++];
                        inv1[h] += (it2 - m);
                    } else {
                        tmp[it++] = a[it2++];
                    }
                }
                while (it1 < m) {
                    tmp[it++] = a[it1++];
                    inv1[h] += it2 - m;
                }
                while (it2 <= r) {
                    tmp[it++] = a[it2++];
                }
            }
            {
                int it1 = l, it2 = m;
                while (it1 < m && it2 <= r) {
                    if (a[it1] < a[it2]) {
                        it1++;
                    } else {
                        inv2[h] += (it1 - l);
                        it2++;
                    }
                }
                while (it2 <= r) {
                    inv2[h] += it1 - l;
                    it2++;
                }
            }
            for (int i = l; i <= r; i++) {
                a[i] = tmp[i - l];
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        inv1 = new long[n];
        inv2 = new long[n];
        int len = 1 << n;
        int[] a = new int[len];
        for (int i = 0; i < len; i++)
            a[i] = in.nextInt();
        go(a, 0, len - 1, 0);
        int m = in.nextInt();
        boolean[] now = new boolean[n];
        long nowInv = 0;
        for (int i = 0; i < n; i++)
            nowInv += inv1[i];
        for (int i = 0; i < m; i++) {
            int q = in.nextInt();
            for (int j = 0; j < q; j++) {
                now[n - 1 - j] = !now[n - 1 - j];
                if (now[n - 1 - j]) {
                    nowInv += inv2[n - 1 - j] - inv1[n - 1 - j];
                } else {
                    nowInv += inv1[n - 1 - j] - inv2[n - 1 - j];
                }
            }
            out.println(nowInv);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}