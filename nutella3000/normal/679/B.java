import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static long pow_3[] = new long[100_001];

    static pair solve(long m) throws IOException {
        if (m < 8) {
            return new pair(m, m);
        }

        int l = 0;
        int r = (int) 1e5 + 1;
        while(r - l > 1) {
            int mid = ((l + r) >> 1);
            if (pow_3[mid] <= m) l = mid;
            else r = mid;
        }

        /*pair ans = solve1(Math.max(m - pow_3[l], pow_3[l] - 1 - pow_3[l - 1]));

        if (m - pow_3[l] >= ans.y) {
            ans = solve(m - pow_3[l]);
            ans.y += pow_3[l];
        }else {
            ans = solve(pow_3[l] - pow_3[l - 1] - 1);
            ans.y += pow_3[l - 1];
        }
        ans.x++;*/
        pair ans1 = solve(m - pow_3[l]);
        pair ans2 = solve(pow_3[l] - 1 - pow_3[l - 1]);
        pair ans = new pair();
        if (ans1.x >= ans2.x) {
            ans.x = ans1.x + 1;
            ans.y = ans1.y + pow_3[l];
        }else{
            ans.x = ans2.x + 1;
            ans.y = ans2.y + pow_3[l - 1];
        }

        return ans;
    }

    static pair solve1(long m) throws IOException {
        if (m < 8) {
            return new pair(m, m);
        }

        int l = 0;
        int r = (int) 1e5 + 1;
        while(r - l > 1) {
            int mid = ((l + r) >> 1);
            if (pow_3[mid] <= m) l = mid;
            else r = mid;
        }

        pair ans = solve1(Math.max(m - pow_3[l], pow_3[l] - 1 - pow_3[l - 1]));
        ans.x++;
        if (pow_3[l] - 1 - pow_3[l - 1] >= ans.y) {
            ans.y += pow_3[l - 1];
        }else ans.y += pow_3[l];

        return ans;
    }


    static void solve() throws IOException {
        for(int i = 0;i <= 100_000;i++) {
            pow_3[i] = (long) i * i * i;
        }

        long m = sc.nextLong();

        pair ans = solve(m);

        pw.println(ans.x + " " + ans.y);
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

class pair {
    long x, y;
    pair(long x, long y) {
        this.x = x;
        this.y = y;
    }

    pair() {}
}