import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        int bits = in.nextInt() * 8;
        int one_element = Math.min(30, bits / n);
        int different_vals = (1 << one_element) - 1;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int max = 0;
        int r = 0;
        for (int l = 0; l < n; l++) {
            if (l != 0) {
                Integer zz = tm.get(a[l - 1]);
                if (zz - 1 == 0) {
                    tm.remove(a[l - 1]);
                } else {
                    tm.put(a[l - 1], zz - 1);
                }
            }
            while (r != n && (tm.containsKey(a[r]) || tm.size() <= different_vals)) {
                Integer ff = tm.get(a[r]);
                tm.put(a[r], ff != null ? ff + 1 : 1);
                r++;
            }
            max = Math.max(max, r - l);
        }
        out.println(n - max);

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