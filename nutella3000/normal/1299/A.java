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
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        int cnt[] = new int [30];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 30;j++) {
                if ((a[i] & (1 << j)) != 0) cnt[j]++;
            }
        }

        int ind = -1;
        int max = -1;
        for(int i = 0;i < n;i++) {
            int s = 0;
            for(int j = 0;j < 30;j++) {
                if ((a[i] & (1 << j)) != 0 && cnt[j] == 1) s += (1 << j);
            }
            if (max < s) {
                max = s;
                ind = i;
            }
        }

        pw.print(a[ind] + " ");
        for(int i = 0;i < n;i++) {
            if (i != ind) pw.print(a[i] + " ");
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