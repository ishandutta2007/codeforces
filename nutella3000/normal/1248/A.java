
import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int p[] = new int[n];
            for (int i = 0; i < n; i++) p[i] = sc.nextInt();
            int m = sc.nextInt();
            int q[] = new int[m];
            for (int i = 0; i < m; i++) q[i] = sc.nextInt();
            long ans = 0;
            long a[] = new long [2];
            long b[] = new long[2];
            for(int i = 0;i < n;i++) a[p[i] % 2]++;
            for(int i = 0;i < m;i++) b[q[i] % 2]++;
            ans = a[0] * b[0] + a[1] * b[1];
            pw.println(ans);
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