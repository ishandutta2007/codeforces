import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        char[][] s = new char[n][];
        char[][] t = new char[n][];
        for (int i = 0; i < n; i++) {
            s[i] = in.next().toCharArray();
        }
        for (int i = 0; i < n; i++) {
            t[i] = in.next().toCharArray();
        }
        solve12(s, t);
    }

    void solve123() {
        Random rnd = new Random(123);
        final int MAX = 5;
        for (int it = 0; it < 123123; it++) {
            System.err.println("it = " + it);
            int n = 1 + rnd.nextInt(MAX);
            char[][] s = new char[n][];
            char[][] t = new char[n][];
            for (int i = 0; i < n; i++) {
                int len = 1 + rnd.nextInt(MAX);
                s[i] = new char[len];
                t[i] = new char[len];
                for (int j = 0; j < len; j++) {
                    s[i][j] = (char) ('a' + rnd.nextInt(2));
                    t[i][j] = (char) ('a' + rnd.nextInt(2));
                }
            }
            solve12(s, t);
        }
    }

    void solve12(char[][] s, char[][] t) {
        int n = s.length;
//        char[][] s = new char[n][];
//        char[][] t = new char[n][];
//        for (int i = 0; i < n; i++) {
//            s[i] = in.next().toCharArray();
//        }
//        for (int i = 0; i < n; i++) {
//            t[i] = in.next().toCharArray();
//        }
        int[] from = new int[n];
        int[] to = new int[n];
        int changed = -1;
        for (int i = 0; i < n; i++) {
            from[i] = Integer.MAX_VALUE;
            to[i] = -1;
            for (int j = 0; j < s[i].length; j++) {
                if (s[i][j] != t[i][j]) {
                    from[i] = Math.min(from[i], j);
                    to[i] = j;
                    changed = i;
                }
            }
        }
//        System.err.println(Arrays.toString(to));
        for (int i = 0; i < n; i++) {
            if (to[i] == -1) {
                continue;
            }
            if (to[i] - from[i] != to[changed] - from[changed]) {
                out.println("NO");
                return;
            }
            for (int j = 0; j <= to[i] - from[i]; j++) {
                if (s[i][from[i] + j] != s[changed][from[changed] + j] ||
                        t[i][from[i] + j] != t[changed][from[changed] + j]) {
                    out.println("NO");
                    return;
                }
            }
        }
        while (true) {
            char nextChar = 0;
            char nextChar2 = 0;
            for (int i = 0; i < n; i++) {
                if (to[i] == -1) {
                    continue;
                }
                if (from[i] == 0) {
                    nextChar = 0;
                    break;
                }
                if (s[i][from[i] - 1] != nextChar || t[i][from[i] - 1] != nextChar2) {
                    if (nextChar == 0) {
                        nextChar = s[i][from[i] - 1];
                        nextChar2 = t[i][from[i] - 1];
                    } else {
                        nextChar = 0;
                        break;
                    }
                }
            }
            if (nextChar == 0) {
                break;
            }
            for (int i = 0; i < n; i++) {
                if (to[i] != -1) {
                    from[i]--;
                }
            }
        }
        while (true) {
            char nextChar = 0;
            char nextChar2 = 0;
            for (int i = 0; i < n; i++) {
                if (to[i] == -1) {
                    continue;
                }
                if (to[i] + 1 == s[i].length) {
                    nextChar = 0;
                    break;
                }
                if (s[i][to[i] + 1] != nextChar || t[i][to[i] + 1] != nextChar2) {
                    if (nextChar == 0) {
                        nextChar = s[i][to[i] + 1];
                        nextChar2 = t[i][to[i] + 1];
                    } else {
                        nextChar = 0;
                        break;
                    }
                }
            }
            if (nextChar == 0) {
                break;
            }
            for (int i = 0; i < n; i++) {
                if (to[i] != -1) {
                    to[i]++;
                }
            }
        }
        if (changed == -1) {
            return;
        }
        int len = to[changed] - from[changed] + 1;
        char[] what = new char[len];
        char[] changeTo = new char[len];
        for (int i = 0; i < len; i++) {
            what[i] = s[changed][from[changed] + i];
            changeTo[i] = t[changed][from[changed] + i];
        }
//        System.err.println("!" +  Arrays.toString(what));
        for (int i = 0; i < n; i++) {
            char[] check = new char[len + 1 + s[i].length];
            for (int j = 0; j < len; j++) {
                check[j] = what[j];
            }
            check[len] = '#';
            for (int j = 0; j < s[i].length; j++) {
                check[len + 1 + j] = s[i][j];
            }
            int[] pref = prefFunction(check);
            for (int j = 0; j < s[i].length; j++) {
                int val = pref[len + 1 + j];
                if (val == len) {
                    if (to[i] != j) {
                        out.println("NO");
                        return;
                    }
                    break;
                }
            }
        }
        out.println("YES");
        out.println(new String(what));
        out.println(new String(changeTo));
    }

    int[] prefFunction(char[] s) {
        int n = s.length;
        int[] pi = new int[n];
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
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