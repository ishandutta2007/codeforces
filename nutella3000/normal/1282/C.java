import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int t = sc.nextInt();
            int a = sc.nextInt();
            int b = sc.nextInt();
            int cnt = 0;
            long time = 0;
            int ans = 0;
            pair req[] = new pair[n + 1];
            for(int i = 0;i < n;i++) {
                req[i] = new pair();
                req[i].id = sc.nextInt();
            }
            for(int i = 0;i < n;i++) {
                req[i].x = sc.nextInt();
                if (req[i].id == 0) cnt++;
            }
            req[n] = new pair(t + 1, 1);

            Arrays.sort(req, new pair());

            for(int i = 0;i <= n;i++) {
                if (time <= req[i].x - 1) {
                    int new_ans = i;
                    long v_time = req[i].x - 1 - time;
                    new_ans += Math.min(cnt, v_time / a);
                    v_time -= Math.min(cnt, v_time / a) * a;
                    new_ans += v_time / b;

                    if (new_ans > ans) ans = new_ans;
                }

                if (req[i].id == 0) {
                    cnt--;
                    time += a;
                }else time += b;
            }

            pw.println(Math.min(ans, n));


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

class matrix {
    long a[][];
    static long mod = (long) 1e18 + 7;
    int n;

    matrix(int n) {
        this.n = n;
        a = new long[n][n];
    }

    matrix(long b[][]) {
        n = b.length;
        a = new long [n][n];

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                a[i][j] = b[i][j];
            }
        }
    }

    matrix add(matrix b) {
        matrix c = new matrix(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                c.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return c;
    }

    matrix mul(matrix b) {
        matrix c = new matrix(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                for(int k = 0;k < n;k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
    }

    matrix pow(long pow) {
        matrix ans = new matrix(n);
        matrix temp = new matrix(a);
        for(int i = 0;i < n;i++) ans.a[i][i] = 1;

        while(pow != 0) {
            if ((pow & 1) == 1) ans = ans.mul(temp);
            temp = temp.mul(temp);

            pow >>= 1;
        }

        return ans;
    }


}

class pair implements Comparator<pair>{
    int x, id;
    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}