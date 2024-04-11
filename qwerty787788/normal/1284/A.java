import java.io.*;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;
    int mod;

    public static void main(String[] args) {
        new A().runIO();
    }


    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];
        for (int i = 0; i < n; i++) {
            a[i] = in.next();
        }
        for (int i = 0; i < m; i++) {
            b[i] = in.next();
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int year = in.nextInt() - 1;
            out.println(a[year % a.length] + b[year % b.length]);
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

    class Seg implements Comparable<Seg> {
        int from, to;

        Seg(int from, int to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public int compareTo(Seg o) {
            return Integer.compare(to, o.to);
        }
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
}