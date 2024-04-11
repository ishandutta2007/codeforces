import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int ans1(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] + a[i + 1] < -a[i] -a[i + 1]) {
                a[i] = -a[i];
                a[i + 1] = -a[i + 1];
            }
        }
        int res = 0;
        for (int i = 0; i < a.length; i++)
            res += a[i];        
        return res;
    }

    int ans2(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] <= 0 && a[i + 1] <= 0) {
                a[i] = -a[i];
                a[i + 1] = -a[i + 1];
            }
        }
        int res = 0;
        for (int i = 0; i < a.length; i++)
            res += a[i];        
        return res;
    }
    
    void solve() throws IOException {
        int n = in.nextInt();
        int[] a = new int[2 * n - 1];
        for (int i = 0; i < 2 * n -1 ; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int[] b = new int[a.length];
        for (int i = 0; i < 2 * n - 1; i++)
            b[i] = a[i];
        for (int i = 0; i < n; i++)
            b[i] = -b[i];
        out.println(Math.max(ans2(b), ans1(a)));
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
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
    }

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}