import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        Blog[] a = new Blog[n];
        int[] themeId = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Blog(i, in.nextInt());
            themeId[i] = a[i].theme;
        }
        Arrays.sort(a);
        boolean[] exist = new boolean[n];
        for (Blog b : a) {
            Set<Integer> alr = new HashSet<>();
            for (int to : g[b.id]) {
                if (exist[to] && themeId[to] <= themeId[b.id]) {
                    alr.add(themeId[to]);
                }
            }
            if (alr.size() != b.theme - 1 || alr.contains(b.theme)) {
                out.println(-1);
                return;
            }
            exist[b.id] = true;
        }
        for (Blog b : a) {
            out.print((1 + b.id) + " ");
        }
        out.println();
    }

    class Blog implements Comparable<Blog> {
        int id;
        int theme;

        public Blog(int id, int theme) {
            this.id = id;
            this.theme = theme;
        }

        @Override
        public int compareTo(Blog o) {
            return Integer.compare(theme, o.theme);
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