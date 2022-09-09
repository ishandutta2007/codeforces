import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        boolean[] used = new boolean[n];
        out.print("1 ");
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                out.println(a[i]);
                used[i] = true;
                break;
            }
        }

        boolean ok = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                out.print("1 ");
                out.println(a[i]);
                used[i] = true;
                ok = true;
                break;
            }
        }

        if (ok) {
            out.print((n - 2) + " ");
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    out.print(a[i] + " ");
                }
            }
        } else {
            out.print("2 ");
            int ss = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < 0 && !used[i]) {
                    out.print(a[i] + " ");
                    used[i] = true;
                    ss++;
                    if (ss == 2)
                        break;
                }
            }
            out.println();
            out.print((n - 3) + " ");
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    out.print(a[i] + " ");
                }
            }
        }
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