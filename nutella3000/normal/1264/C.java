import java.io.*;
import java.util.*;


public class Main {
    static int mod = 998244353;
    static int log = 20;
    static pair s[][];

    static long pow(long a, long b) {
        long ans = 1;
        while(b > 0) {
            if (b % 2 == 1) ans = (ans * a) % mod;

            a = a * a % mod;

            b >>= 1;
        }
        return ans;
    }

    static long rev(long a) {
        return pow(a, mod - 2);
    }

    static long mul(long a, long b) {
        return a * b % mod;
    }

    static long plus(long a, long b) {
        long ans = a + b;
        if (ans >= mod) ans -= mod;
        return ans;
    }

    static long f(int l, int r) {
        r--;
        int k = log - 1;

        long ans = 0;

        while(l <= r) {
            while (l + (1 << k) - 1 > r) k--;

            ans = plus(mul(ans, s[k][l].a), s[k][l].b);

            l += (1 << k);
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int q = sc.nextInt();

        long p[] = new long [n];
        for(int i = 0;i < n;i++) p[i] = mul(sc.nextInt(),rev(100));

        s = new pair[log][n];

        for(int i = 0;i < n;i++) {
            s[0][i] = new pair(rev(p[i]), rev(p[i]));
        }

        for(int i = 1;i < log;i++) {
            for(int j = 0;j < n;j++) {
                if (j + (1 << i) - 1 >= n) continue;
                int sec = j + (1 << (i - 1));

                s[i][j] = new pair(mul(s[i - 1][j].a, s[i - 1][sec].a),
                        plus(mul(s[i - 1][j].b, s[i - 1][sec].a), s[i - 1][sec].b));
            }
        }

        long ans = 0;


        TreeSet<Integer> a = new TreeSet<>();
        a.add(0);
        a.add(n);

        ans += f(0, n);

        while(q-- > 0) {
            int v = sc.nextInt() - 1;
            if (a.contains(v)) {
                ans += f(a.lower(v), a.higher(v));
                ans -= f(a.lower(v), v) + f(v, a.higher(v));
                a.remove(v);

            }else{
                ans -= f(a.lower(v), a.higher(v));
                ans += f(a.lower(v), v) + f(v, a.higher(v));

                a.add(v);
            }

            ans = ((ans % mod) + mod) % mod;

            pw.println(ans);
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

class pair {
    long a, b;

    pair(long a, long b) {
        this.a = a;
        this.b = b;
    }

    pair() {}
}