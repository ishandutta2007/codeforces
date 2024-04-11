import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for (int test = sc.nextInt(); test > 0; test--) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            char h[] = sc.next().toCharArray();
            int cnt = 0;
            int num = 0;
            for (int i = 0; i < n; i++) {
                if (h[i] == '1') cnt++;
                else {
                    if (cnt > k) break;

                    k -= cnt;
                    num++;
                }
            }

            char ans[] = new char[n];
            for(int i = 0;i < num;i++) ans[i] = '0';
            for(int i = num;i < num + cnt;i++) ans[i] = '1';
            for(int i = num + cnt;i < n;i++) ans[i] = h[i];

            if (num + cnt < n) {
                for (int i = num + cnt; i >= 0; i--) {
                    if (k == 0) break;
                    k--;
                    ans[i - 1] = '0';
                    ans[i] = '1';
                }
            }

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