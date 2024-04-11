import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Fenwick {
        int n;
        int[] sum;

        Fenwick(int n) {
            this.n = n;
            sum = new int[n];
        }

        int get(int r) {
            int res = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                res += sum[r];
            return res;
        }

        void add(int r) {
            for (; r < n; r = r | (r + 1))
                sum[r]++;
        }
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        HashMap<Integer, Integer> cnt = new HashMap<>();
        int[] left = new int[n];
        int[] right = new int[n];
        for (int i = 0; i < n; i++) {
            Integer cur = cnt.get(a[i]);
            if (cur == null)
                cur = 0;
            left[i] = cur++;
            cnt.put(a[i], cur);
        }
        cnt.clear();
        for (int i = n - 1; i >= 0; i--) {
            Integer cur = cnt.get(a[i]);
            if (cur == null)
                cur = 0;
            right[i] = cur++;
            cnt.put(a[i], cur);
        }
        long answer = 0;
        Fenwick f = new Fenwick(n + 5);
        for (int i = n - 1; i >= 0; i--) {
            answer += f.get(left[i] - 1);
            f.add(right[i]);
        }
        out.println(answer);
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