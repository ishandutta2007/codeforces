import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int l = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int left = -1, right = l;
        int[] pref = new int[n];
        while (right - left > 1) {
            int mid = (left + right) >> 1;
//            mid = 1;
            Arrays.fill(pref, 0);
            for (int i =0 ; i <a.length; i++) {
                int x = a[i];
                addElement(i, x - mid, x + mid, b, pref, l);
            }
            boolean ok = false;
            int s = 0;
            for (int z : pref) {
                s += z;
                if (s > n) {
                    throw new AssertionError();
                }
                if (s == n) {
                    ok = true;
                }
            }
            if (ok) {
                right = mid;
            } else {
                left = mid;
            }
        }
        out.println(right);
    }

    void addPref(int[] pref, int from, int to) {
if (to - from == pref.length) {
  pref[0]++;
  return;
}
        if (from < 0) {
            from += pref.length;
        }
        if (from >= pref.length ) {
            from -= pref.length;
        }
        if (to < 0) {
            to += pref.length;
        }
        if (to >= pref.length) {
            to -= pref.length;
        }
        pref[from]++;
        pref[to]--;
        if (from > to) {
            pref[0]++;
        }
    }

    void addElement(int me, int from, int to, int[] vals, int[] pref, int l) {
        if (to - from + 1 >= l) {
            pref[0]++;
            return;
        }
        if (from < 0) {
            addElement(me, l + from, l - 1, vals, pref, l);
            addElement(me, 0, to, vals, pref, l);
            return;
        }
        if (to >= l) {
            addElement(me, from, l - 1, vals, pref, l);
            addElement(me, 0, to - l, vals, pref, l);
            return;
        }
        if (from > to) {
            throw new AssertionError(from + " " + to + " " + l);
        }
        int left = -1, right = vals.length;
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            if (vals[mid] >= from) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int startOk = right - me;
        left = -1;
        right = vals.length;
        while (right - left > 1) {
            int mid = (left + right) >> 1;
            if (vals[mid] <= to) {
                left = mid;
            } else {
                right = mid;
            }
        }
        addPref(pref, startOk, right - me);
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