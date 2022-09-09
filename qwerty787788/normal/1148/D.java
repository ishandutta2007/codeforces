import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class O {
        int a, b, pos;

        public O(int a, int b, int pos) {
            this.a = a;
            this.b = b;
            this.pos = pos;
        }
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        List<O> up = new ArrayList<>();
        List<O> down = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            O o = new O(a[i], b[i], i);
            if (a[i] < b[i]) {
                up.add(o);
            } else {
                down.add(o);
            }
        }
        if (up.size() > down.size()) {
            Collections.sort(up, new Comparator<O>() {
                @Override
                public int compare(O o, O t1) {
                    return -Integer.compare(o.a, t1.a);
                }
            });
            out.println(up.size());
            for (O o : up) {
                out.print((o.pos + 1) + " ");
            }
        } else {
            Collections.sort(down, new Comparator<O>() {
                @Override
                public int compare(O o, O t1) {
                    return Integer.compare(o.a, t1.a);
                }
            });
            out.println(down.size());
            for (O o : down) {
                out.print((o.pos + 1) + " ");
            }
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