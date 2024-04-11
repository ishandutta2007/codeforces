import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int mul(int x, int y) {
        return (int) ((x * 1L * y % mod));
    }

    int pow(int x, int y) {
        if (y == 0) {
            return 1;
        }
        int f = pow(x, y / 2);
        f = mul(f, f);
        if (y % 2 == 1) {
            f = mul(f, x);
        }
        return f;
    }

    int solve(int n, int p, int[] ks) {
        if (p == 1) {
            return n % 2;
        }
        Arrays.sort(ks);
        int curPower = ks[n - 1];
        long curValue = 1;
        int curMod = pow(p, curPower);
        for (int i = n - 2; i >= 0; i--) {
            while (curPower != ks[i] && curValue < Integer.MAX_VALUE && curValue != 0) {
                curPower--;
                curValue *= p;
            }
            if (curValue == 0) {
                curValue = 1;
                curMod = pow(p, ks[i]);
            } else {
                curValue -= 1;
                curMod = curMod - pow(p, ks[i]);
                if (curMod < 0) {
                    curMod += mod;
                }
            }
            curPower = ks[i];
        }
        return curMod;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int p = in.nextInt();
            int[] ks = new int[n];
            for (int i = 0; i < n; i++) {
                ks[i] = in.nextInt();
            }
            out.println(solve(n, p, ks));
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