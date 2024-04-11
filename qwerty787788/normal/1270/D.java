import java.io.*;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new A().runIO();
    }

    int[] ask(int[] idx) {
        out.print("?");
        for (int x : idx) {
            out.print(" " + (x + 1));
        }
        out.println();
        out.flush();
        int pos = in.nextInt() - 1;
        int value = in.nextInt();
        return new int[]{pos, value};
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] firstK = new int[k];
        for (int i = 0; i < k; i++) {
            firstK[i] = i;
        }
        int[] start = ask(firstK);
        firstK[start[0]] = k;
        int[] afterChange = ask(firstK);
        firstK[start[0]] = start[0];
        boolean isBigger = afterChange[1] > start[1];
        int cntLess = 0;
        for (int i = 0; i < k; i++) {
            if (i == start[0]) {
                continue;
            }
            firstK[i] = k;
            int[] ans = ask(firstK);
            if (ans[1] == start[1]) {
                if (!isBigger) {
                    cntLess++;
                }
            } else {
                if (ans[1] > start[1]) {
                    cntLess++;
                }
            }
            firstK[i] = i;
        }
        out.println("! " + (cntLess + 1));
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
}