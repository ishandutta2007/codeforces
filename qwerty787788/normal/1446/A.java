import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class Item implements Comparable<Item> {
        int id;
        long w;

        public Item(int id, long w) {
            this.id = id;
            this.w = w;
        }

        @Override
        public int compareTo(Item o) {
            return Long.compare(o.w, w);
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            long maxSum = in.nextLong();
            Item[] a = new Item[n];
            for (int i = 0; i < n; i++) {
                a[i] = new Item(i, in.nextLong());
            }
            Arrays.sort(a);
            long curW = 0;
            List<Item> use = new ArrayList<>();
            for (Item x : a) {
                if (curW + x.w <= maxSum) {
                    curW += x.w;
                    use.add(x);
                }
            }
            if (curW * 2 >= maxSum) {
                out.println(use.size());
                for (Item item : use) {
                    out.print(item.id + 1);
                    out.print(" ");
                }
                out.println();
            } else {
                out.println(-1);
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