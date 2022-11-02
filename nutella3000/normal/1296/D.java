import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int h[] = new int [n];
        int r[] = new int [n];
        for(int i = 0;i < n;i++) {
            h[i] = sc.nextInt();
            int last = h[i] % (a + b);
            if (last == 0) last += a + b;
            r[i] = (last + a - 1) / a - 1;
        }
        Arrays.sort(r);
        int ans = 0;
        for(int i = 0;i < n;i++) {
            if (r[i] <= k) {
                k -= r[i];
                ans++;
            }
        }

        pw.println(ans);
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
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}