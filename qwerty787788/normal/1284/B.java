import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new A().runIO();
    }

    void solve() {
        int n = in.nextInt();
        long ans = n * 1L * n;
        List<Seg> all = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int len = in.nextInt();
            int[] a = new int[len];
            for (int j = 0; j < len; j++) {
                a[j] = in.nextInt();
            }
            boolean ok = true;
            for (int j = 0; j + 1 < len; j++) {
                if (a[j + 1] > a[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                all.add(new Seg(a[len - 1], a[0]));
            }
        }
        Collections.sort(all);
        for (Seg s : all) {
            int left = -1, right = all.size();
            while (right - left > 1) {
                int mid = (left + right) >> 1;
                if (all.get(mid).to <= s.from) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            ans -= right;
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