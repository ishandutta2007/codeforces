import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int p = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        p = k - p;
        ArrayList<Integer>[] arr = new ArrayList[k];
        for (int i = 0; i < k; i++) {
            arr[i] = new ArrayList<>();
        }
        int it = k - 1;
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0) {
                arr[it--].add(i);
                if (it == -1)
                    it = 0;
            }
        it = 0;
        boolean x = false;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                arr[it].add(i);
                it++;
                if (it > p && !x) {
                    it--;
                    x = true;
                } else {
                    if (it == arr.length) {
                        it--;
                        x = false;
                    } else {
                        x = false;
                    }
                }
            }
        }
        boolean ok = true;
        for (int i = 0; i < k; i++)
            if (arr[i].size() == 0)
                ok = false;
        for (int i = 0; i < k; i++) {
            int c = 0;
            for (int t : arr[i])
                c = (c + a[t]) % 2;
            if (c == 0 && i < p) {
                ok = false;
            }
            if (c == 1 && i >= p)
                ok = false;
        }
        if (ok) {
            out.println("YES");
            for (int i = 0; i < k; i++) {
                out.print(arr[i].size() + " ");
                for (int t : arr[i]) {
                    out.print(a[t] + " ");
                }
                out.println();
            }
        } else {
            out.println("NO");
        }
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