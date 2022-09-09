import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    String[] si;
    int res = 0;
    int MAX = 4 * 100000 + 10;
    int[] prefix = new int[MAX];
    char[] s = new char[MAX];
    int curLen = 0;
    String t;
    
    void recalc(int fr, int to) {
        if (fr == 0)
            fr++;
        for (int i = fr; i <= to; ++i) {
            int j = prefix[i - 1];
            while (j > 0 && s[i] != s[j])
                j = prefix[j - 1];
            if (s[i] == s[j])
                ++j;
            prefix[i] = j;
        }
    }

    void go(int v) {
        for (int i = 0; i < si[v].length(); i++) {
            s[curLen + i] = si[v].charAt(i);
        }
        recalc(curLen, curLen + si[v].length() - 1);
        for (int i = 0; i < si[v].length(); i++) {
            if (prefix[curLen + i] == t.length()) {
                res++;
            }
        }
        curLen += si[v].length();
        for (int i = 0; i < g[v].size(); i++) {
            go(g[v].get(i));
        }
        curLen -= si[v].length();
    }

    void solve() throws IOException {
        int n = in.nextInt();
        g = new ArrayList[n];
        si = new String[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int pi = in.nextInt() - 1;
            g[pi].add(i + 1);
            si[i + 1] = in.next();
        }
        t = in.next();
        si[0] = t + "#";
        go(0);
        out.println(res);
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