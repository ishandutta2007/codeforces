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
        if (n % 2 == 1) {
            pw.println("NO");
            pw.close();
            return;
        }

        int x[] = new int [n];
        int y[] = new int [n];
        for(int i = 0;i < n;i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        boolean bad = false;
        for(int i = 0;i < n;i++) {
            int to = (i + 1) % n;
            int v1 = (i + n / 2) % n;
            int to1 = (v1 + 1) % n;

            if (x[to] - x[i] != x[v1] - x[to1] || y[to] - y[i] != y[v1] - y[to1]) bad = true;
        }

        if (bad) pw.println("NO");
        else pw.println("YES");

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