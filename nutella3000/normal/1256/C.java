
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int sz = sc.nextInt();
        int n = sc.nextInt();
        int d = sc.nextInt();
        int c[] = new int [n];
        for(int i = 0;i < n;i++) c[i] = sc.nextInt();
        int suf[] = new int [n];
        suf[n - 1] = c[n - 1];
        for(int i = n - 2;i >= 0;i--) suf[i] = suf[i + 1] + c[i];

        int ans[] = new int [sz + 1];
        for(int i = 0;i < sz + 1;i++) ans[i] = -1;

        int start = 0;
        for(int id = 0;id < n;id++) {

            int v = Math.min(start + d, sz - suf[id] + 1);

            for(int i = 0;i < c[id];i++) {
                ans[v++] = id;
            }
            start = v - 1;
        }

        if (start + d >= sz + 1) {
            pw.println("YES");
            for(int i = 1;i <= sz;i++) pw.print(ans[i] + 1 + " ");
        }else pw.println("NO");
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