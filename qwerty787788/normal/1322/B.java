import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] pref = new int[(1 << 24) + 1];
        long res = 0;
        for (int bit = 0; bit < 25; bit++) {
            int needMask = (1 << (bit + 1)) - 1;
            Arrays.fill(pref, 0);
            for (int i = 0; i < n; i++) {
                int val = a[i] & needMask;
                pref[val + 1]++;
            }
            for (int i = 1; i < pref.length; i++) {
                pref[i] += pref[i - 1];
            }
            long cnt = 0;
            for (int i = 0; i < n; i++) {
                int val = a[i] & needMask;
                if ((val & (1 << bit)) != 0) {
                    int maxSum = 1 << (bit + 1);
                    int maxVal = maxSum - val;
                    cnt += pref[maxVal];
                    cnt += pref[pref.length - 1] - pref[3 * (1 << bit) - val];
                } else {
                    int minSum = (1 << bit) - val;
                    int maxSum = (1 << (bit + 1)) - val;
                    cnt += pref[Math.min(pref.length - 1, maxSum)] - pref[minSum];

                }
                if (((a[i] * 2) & (1 << bit)) != 0) {
                    cnt--;
                }
            }
            if (cnt % 2 != 0) {
                throw new AssertionError(bit + " " + cnt);
            }
            cnt /= 2;
            if ((cnt & 1) != 0) {
                res += 1 << bit;
            }
        }
        out.println(res);
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