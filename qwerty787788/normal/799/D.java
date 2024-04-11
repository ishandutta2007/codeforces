import java.io.*;
import java.util.*;

public class D {
    private FastScanner in;
    private PrintWriter out;

    int get(int a, int b, int w, int h, int[] arr) {
        int maxW = Math.max(a, w);
        int maxH = Math.max(b, h);
        int[] res = new int[maxW + 1];
        Arrays.fill(res, 0);
        res[w] = h;
        int[] res2 = new int[maxW + 1];
        for (int i = 0; i < arr.length; i++) {
            for (int j = a; j < res.length; j++) {
                if (res[j] >= b) {
                    return i;
                }
            }
            Arrays.fill(res2, 0);
            for (int j = 0; j < res.length; j++) {
                if (res[j] != 0) {
                    int nj = (int) Math.min(j * 1L * arr[i], maxW);
                    res2[nj] = Math.max(res2[nj], res[j]);
                    int ni = (int) Math.min(res[j] * 1L * arr[i], maxH);
                    res2[j] = Math.max(res2[j], ni);
                }
            }
            int[] tmp = res;
            res = res2;
            res2 = tmp;
        }
        for (int j = a; j < res.length; j++) {
            if (res[j] >= b) {
                return arr.length;
            }
        }
        return Integer.MAX_VALUE;
    }

    private void solve() {
        int a = in.nextInt();
        int b = in.nextInt();
        int w = in.nextInt();
        int h = in.nextInt();
        int n = in.nextInt();
        int[] mul = new int[n];
        for (int i = 0; i < n; i++) {
            mul[i] = in.nextInt();
        }
        Arrays.sort(mul);
        int use = Math.min(40, mul.length);
        int[] nmul = new int[use];
        for (int i = 0; i < use; i++) {
            nmul[i] = mul[n - 1 - i];
        }
        int res = Math.min(get(a, b, w, h, nmul), get(b, a, w, h, nmul));
        out.println(res == Integer.MAX_VALUE ? -1 : res);
    }

    private void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}