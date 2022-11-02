import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    static long binpow(long a, long b, long m) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = res * a;
                if (res >= m) res %= m;
            }
            a = a * a;
            if (a >= m) a %= m;
            b >>= 1;
        }
        return res;
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        Arrays.sort(a);

        long res = 1;
        long cnt[] = new long[m];
        long cnt1[][] = new long[m][m];
        for (int i = 0; i < n; i++) {
            int temp = a[i] % m;
            for (int j = 0; j < m; j++) cnt1[temp][j] += cnt[j];
            cnt[temp]++;
        }

        // for(int i = 0;i < m;i++) cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int temp = i - j + m;
                if (temp >= m) temp -= m;
                res = res * binpow(temp, cnt1[i][j], m);
                if (res >= m) res %= m;
            }
        }
        pw.println(res);
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
    int a, t;

    pair(int a, int t) {
        this.a = a;
        this.t = t;
    }

    pair() {
    }

}