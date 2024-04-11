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
        long a[] = new long [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        long ans1 = 0;
        long ans2 = 0;
        for(int i = 0;i < n;i++) {
            if (i % 2 == 0) {
                ans1 += (a[i] + 1) / 2;
                ans2 += (a[i]) / 2;
            }else{
                ans1 += a[i] / 2;
                ans2 += (a[i] + 1) / 2;
            }
        }

        pw.println(Math.min(ans1, ans2));


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