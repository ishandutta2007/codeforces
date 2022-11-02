import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n, a, b;
    static char h[];
    static int len, cnt;

    static boolean bad_line() {
        int cnt_bad = 0;
        int c = 0;
        char last = 0;
        for(int i = 0;i <= n;i++) {
            if (i == n || h[i] != last) {
                if (last == '.') {
                    if (c >= 2 * b) {
                        cnt_bad++;
                        len = Math.max(len, c);
                    }else if (c < a && b <= c) return true;
                    else if (c >= a) cnt++;
                }

                c = 0;
            }

            c++;
            if (i != n) last = h[i];
        }

        return cnt_bad >= 2;
    }

    static boolean big() {
        return 2 * (2 * b - 1) + a < len;
    }

    static boolean zero() {
        if (len == 0) return true;
        return (a <= len) && (len <= 2 * (b - 1) + a);
    }

    static boolean one() {
        if (len == 0) return false;
        return (2 * a <= len && len <= a + 3 * b - 2);
    }

    static boolean two() {
        if (len == 0) return false;
        return (3 * a <= len) && (len <= 2 * (2 * b - 1) + a);
    }

    static boolean f(int cnt) {
        return (cnt % 2 == 0);
    }

    static void scan() throws IOException {
        a = sc.nextInt();
        b = sc.nextInt();
        h = sc.next().toCharArray();
        n = h.length;
        len = 0;
        cnt = 0;
    }

    static boolean solve() throws IOException {
        scan();

        if (bad_line()) return false;
        if (big()) return false;
        if (len == 0) cnt++;
        if (zero() && f(cnt)) return true;
        if (one() && f(cnt + 1)) return true;
        if (two() && f(cnt + 2)) return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            boolean ans = solve();
            pw.println(ans ? "YES" : "NO");
        }
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}