import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class O implements Comparable<O> {
        int pos, value;

        public O(int pos, int value) {
            this.pos = pos;
            this.value = value;
        }

        @Override
        public int compareTo(O o) {
            return Integer.compare(o.value, value);
        }
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        O[] all = new O[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            all[i] = new O(i, a[i]);
        }
        Arrays.sort(all);
        boolean[] win = new boolean[n];
        boolean[] was = new boolean[n];
        for (O o : all) {
            int pos = o.pos;
            int delta = o.value;
            for (int x = pos % delta; x < n; x += delta) {
                if (!was[x]) {
                    continue;
                }
                win[pos] |= !win[x];
            }
            was[pos] = true;
        }
        for (boolean z : win) {
            out.print(z ? "A" : "B");
        }
        out.println();
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