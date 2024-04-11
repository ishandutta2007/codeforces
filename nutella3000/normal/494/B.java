import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, s;
    static boolean good[];

    static void scan() throws IOException {
        char first[] = sc.next().toCharArray();
        char second[] = sc.next().toCharArray();
        n = first.length;
        s = second.length;

        good = new boolean[n + 1];

        int p = 27;
        long hash = 0;
        for(int i = 0;i < second.length;i++) {
            hash = (hash * p + second[i] - 'a') % inf;
        }

        long pow[] = new long[n];
        pow[0] = 1;
        for(int i = 1;i < n;i++) pow[i] = pow[i - 1] * p % inf;

        long h[] = new long[n];

        for(int i = 0;i < n;i++) {
            if (i == 0) h[i] = first[i] - 'a';
            else h[i] = (h[i - 1] * p + first[i] - 'a') % inf;

            if (i == s - 1) {
                if (h[i] == hash) good[i + 1] = true;
            }else if (i >= s){
                long cal = (((h[i] - h[i - s] * pow[s]) % inf + inf) % inf);

                if (cal == hash) good[i + 1] = true;
            }
        }
    }

    static long solve1() {
        n++;
        long a[] = new long[n];
        long f1[] = new long[n];
        long f2[] = new long[n];
        f2[0] = 1;

        int last = -1;

        for(int i = 1;i < n;i++) {
            if (good[i]) last = i - s;

            if (last == -1) a[i] = 0;
            else{
                a[i] = f2[last];
            }

            f1[i] = f1[i - 1] + a[i];
            f2[i] = f2[i - 1] + f1[i] + 1;

            a[i] %= inf;
            f1[i] %= inf;
            f2[i] %= inf;
        }

        return f1[n - 1];
    }

    static void solve() throws IOException {
        scan();
        pw.println(solve1());
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
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