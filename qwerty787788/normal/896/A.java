import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    private void solve() {
        String f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
        final int MAX = (int) 1e5 + 10;
        long[] size = new long[MAX];
        size[0] = f0.length();
        String add0 = "What are you doing while sending \"";
        String add1 = "\"? Are you busy? Will you send \"";
        String add2 = "\"?";
        long inf = (long) 1e18 + 100;
        int a0 = add0.length(), a1 = add1.length(), a2 = add2.length();
        for (int i = 1; i < MAX; i++) {
            size[i] = a0 + a1 + a2 + size[i - 1] * 2;
            size[i] = Math.min(size[i], inf);
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int n = in.nextInt();
            long k = in.nextLong() - 1;
            boolean f = false;
            while (n > 0) {
                if (k < a0) {
                    out.print(add0.charAt((int) k));
                    f = true;
                    break;
                }
                k -= a0;
                if (k < size[n - 1]) {
                    n--;
                    continue;
                }
                k -= size[n - 1];
                if (k < a1) {
                    out.print(add1.charAt((int) k));
                    f = true;
                    break;
                }
                k -= a1;
                if (k < size[n - 1]) {
                    n--;
                    continue;
                }
                k -= size[n - 1];
                if (k >= a2) {
                    out.print(".");
                    f = true;
                    break;
                }
                out.print(add2.charAt((int) k));
                f = true;
                break;
            }
            if (f) {
                continue;
            }
            if (n == 0) {
                out.print(k >= f0.length() ? "." : f0.charAt((int) k));
            }
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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