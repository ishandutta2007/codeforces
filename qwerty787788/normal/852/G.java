import java.io.*;
import java.util.*;

public class G {
    private FastScanner in;
    private PrintWriter out;

    final int MUL = 239;

    long[] a, pow;

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        a = new long[n];
        pow = new long[100];
        pow[0] = 1;
        for (int i = 1; i < pow.length; i++) {
            pow[i] = pow[i - 1] * MUL;
        }
        for (int i = 0; i < n; i++) {
            char[] s = in.next().toCharArray();
            long hash = 0;
            for (char c : s) {
                hash = hash * MUL + c;
            }
            a[i] = hash;
        }
        Arrays.sort(a);
        used = new int[n];
        for (int i = 0; i < m; i++) {
            globalIter++;
            char[] s = in.next().toCharArray();
            ArrayList<Part> parts = new ArrayList<>();
            for (int j = 0; j < s.length; j++) {
                if (s[j] == '?') {
                    parts.add(new Part(true));
                    continue;
                }
                long h = 0;
                int k;
                for (k = j; k < s.length && s[k] != '?'; k++) {
                    h = h * MUL + s[k];
                }
                parts.add(new Part(h, k - j));
                j = k - 1;
            }
            out.println(go(parts, 0, 0));

        }
    }

    int[] used;
    int globalIter = 0;

    int find(long hash) {
        int l = -1, r = a.length;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (a[mid] < hash) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (r != a.length && a[r] == hash) {
            if (used[r] == globalIter) {
                return 0;
            }
            used[r] = globalIter;
            int l1 = r, r1 = a.length;
            while (r1 - l1 > 1) {
                int m = (l1 + r1) >> 1;
                if (a[m] == hash) {
                    l1 = m;
                } else {
                    r1 = m;
                }
            }
            return r1 - r;
        } else {
            return 0;
        }
    }

    int go(ArrayList<Part> parts, long curHash, int it) {
        if (parts.size() == it) {
            return find(curHash);
        } else {
            Part cur = parts.get(it);
            if (cur.q) {
                int res = go(parts, curHash, it + 1);
                for (char c = 'a'; c <= 'e'; c++) {
                    res += go(parts, curHash * MUL + c, it + 1);
                }
                return res;
            } else {
                return go(parts, curHash * pow[cur.len] + cur.hash, it + 1);
            }
        }
    }

    class Part {
        long hash;
        int len;
        boolean q;

        public Part(boolean q) {
            this.q = q;
        }

        public Part(long hash, int len) {
            this.hash = hash;
            this.len = len;
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("G.in"));
            out = new PrintWriter(new File("G.out"));

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
        new G().runIO();
    }
}