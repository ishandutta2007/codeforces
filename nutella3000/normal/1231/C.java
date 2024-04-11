import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) a[i][j] = sc.nextInt();
        }
        boolean bad = false;
        long sum = 0;
        for(int i = n - 1;i >= 0;i--) {
            int last = inf;
            for(int j = m - 1;j >= 0;j--) {
                if (a[i][j] != 0) {
                    if (a[i][j] >= last) bad = true;
                    last = a[i][j];
                }else{
                    int q = Math.min(a[i + 1][j], a[i][j + 1]) - 1;
                    if (q >= last) bad = true;
                    last = q;

                    a[i][j] = q;
                }
                sum += last;
            }
        }

        for(int j = 0;j < m;j++) {
            int last = -1;
            for(int i = 0;i < n;i++) {
                if (a[i][j] <= last) bad = true;
                last = a[i][j];
            }
        }

        if (bad) pw.println(-1);
        else pw.println(sum);

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