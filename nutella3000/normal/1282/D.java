import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);

        for(int i = 0;i < 300;i++) pw.print("a");
        pw.println();
        pw.flush();
        int one = 300 - sc.nextInt();

        if (one == 300) return;

        for(int i = 0;i < 300;i++) pw.print("b");
        pw.println();
        pw.flush();
        int two = 300 - sc.nextInt();

        if (two == 300) return;

        int n = one + two;

        char ans[] = new char[n];
        for(int i = 0;i < n;i++) ans[i] = 'a';

        int last = two;

        for(int i = 0;i < n - 1;i++) {
            ans[i] = 'b';
            pw.println(ans);
            pw.flush();
            int now = sc.nextInt();
            if (now > last) {
                one--;
                ans[i] = 'a';
            }else {
                last = now;
                two--;
            }
            if (now == 0) return;
        }

        if (one != 0) ans[n - 1] = 'a';
        else ans[n - 1] = 'b';

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