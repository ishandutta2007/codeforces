import java.io.*;
import java.util.*;

public class CF2 {
    FastScanner in;
    PrintWriter out;

    class T implements Comparable<T> {
        int type;
        int value;

        T(int type, int value) {
            this.type = type;
            this.value = value;
        }

        @Override
        public int compareTo(T o) {
            return Integer.compare(value, o.value);
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        T[] a = new T[n + m];
        for (int i = 0; i < n; i++)
            a[i] = new T(1, in.nextInt());
        for (int i = 0; i < m; i++)
            a[i + n] = new T(-1, in.nextInt());
        Arrays.sort(a);
        long[] up = new long[a.length];
        long[] down = new long[a.length];
        {
            int cnt = 0;
            for (int i = 0; i < a.length; i++) {
                if (i != 0) {
                    up[i] = up[i - 1] + cnt * 1L
                            * (a[i].value - a[i - 1].value);
                }
                if (a[i].type == 1)
                    cnt++;
            }
        }
        {
            int cnt = 0;
            for (int i = a.length - 1; i >= 0; i--) {
                if (i != a.length - 1) {
                    down[i] = down[i + 1] + cnt * 1L
                            * (-a[i].value + a[i + 1].value);
                }
                if (a[i].type == -1)
                    cnt++;
            }
        }
        long res = Long.MAX_VALUE;
        for (int i = 0; i < a.length; i++)
            res = Math.min(res, down[i] + up[i]);
        out.println(res);
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
        new CF2().runIO();
    }
}