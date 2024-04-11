import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int M = 21;
    final int MAX = 1 << M;

    void update(int[][] res, int mask, int pos) {
        if (res[0][mask] > pos) {
            res[1][mask] = res[0][mask];
            res[0][mask] = pos;
        } else if (res[1][mask] > pos && res[0][mask] != pos) {
            res[1][mask] = pos;
        }
    }

    int[][] getFirst(int[] a) {
        int[][] res = new int[2][MAX];
        Arrays.fill(res[0], a.length);
        Arrays.fill(res[1], a.length);
        for (int i = 0; i < a.length; i++) {
            update(res, a[i], i);
        }
        for (int mask = MAX - 1; mask > 0; mask--) {
            for (int i = 0; i < M; i++) {
                if (((1 << i) & mask) != 0) {
                    update(res, mask ^ (1 << i), res[0][mask]);
                    update(res, mask ^ (1 << i), res[1][mask]);
                }
            }
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[][] first = getFirst(a);
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        int[][] last = getFirst(a);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < last[i].length; j++) {
                last[i][j] = a.length - last[i][j] - 1;
            }
        }
        int ans = 0;
        for (int bit = M - 1; bit >= 0; bit--) {
            int checkAns = ans | (1 << bit);
            boolean ok = false;
            for (int sub = checkAns; ; sub = (sub - 1) & checkAns) {
                int posLeft = first[0][sub];
                int needRight = checkAns ^ sub;
                int posRight = last[1][needRight];
                if (posLeft < posRight) {
                    ok = true;
                    break;
                }
                if (sub == 0) {
                    break;
                }
            }
            if (ok) {
                ans |= 1 << bit;
            }
        }
        out.println(ans);
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