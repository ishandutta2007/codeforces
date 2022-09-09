import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][2];
        int[][] b = new int[m][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = in.nextInt();
            a[i][1] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            b[i][0] = in.nextInt();
            b[i][1] = in.nextInt();
        }
        boolean[] can =new boolean[10];
        for (int i = 0; i < n; i++) {
            for (int j= 0; j < m; j++) {
                List<Integer> same = new ArrayList<>();
                for (int x =0 ; x < 2; x++) {
                    for (int y =0; y < 2; y++) {
                        if (a[i][x] == b[j][y]) {
                            same.add(a[i][x]);
                        }
                    }
                }
                if(same.size() == 1) {
                    can[same.get(0)] = true;
                }
            }
        }
        int cnt = 0;
        for (boolean z : can) {
            if (z) {
                cnt++;
            }
        }
        if (cnt == 1) {
            for (int i = 0; i < can.length; i++) {
                if (can[i]) {
                    out.println(i);
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            boolean[] c =new boolean[10];
            for (int j = 0; j < m; j++) {
                List<Integer> same = new ArrayList<>();
                for (int x =0 ; x < 2; x++) {
                    for (int y =0; y < 2; y++) {
                        if (a[i][x] == b[j][y]) {
                            same.add(a[i][x]);
                        }
                    }
                }
                if(same.size() == 1) {
                    c[same.get(0)] = true;
                }
            }
            int cc = 0;
            for (boolean t : c) {
                if (t) {
                    cc++;
                }
            }
            if (cc > 1) {
                out.println(-1);
                return;
            }
        }
        for (int j = 0; j < m; j++) {
            boolean[] c =new boolean[10];
            for (int i  = 0; i < n; i++) {
                List<Integer> same = new ArrayList<>();
                for (int x =0 ; x < 2; x++) {
                    for (int y =0; y < 2; y++) {
                        if (a[i][x] == b[j][y]) {
                            same.add(a[i][x]);
                        }
                    }
                }
                if(same.size() == 1) {
                    c[same.get(0)] = true;
                }
            }
            int cc = 0;
            for (boolean t : c) {
                if (t) {
                    cc++;
                }
            }
            if (cc > 1) {
                out.println(-1);
                return;
            }
        }
        out.println(0);
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