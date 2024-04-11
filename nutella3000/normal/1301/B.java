import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int t = sc.nextInt();t > 0;t--) {
            int n = sc.nextInt();
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = sc.nextInt();
            int ans1 = 0;
            int min = inf, max = -inf;
            for(int i = 1;i < n;i++) {
                if (a[i] == -1 && a[i - 1] == -1) continue;
                if (a[i] != -1 && a[i - 1] != -1) ans1 = Math.max(ans1, Math.abs(a[i] - a[i - 1]));
                else {
                    int q = a[i - 1];
                    if (q == -1) q = a[i];
                    min = Math.min(q, min);
                    max = Math.max(q, max);
                }
            }

            ans1 = Math.max(ans1, (max - min + 1) / 2);

            pw.println(ans1 + " " + ((max - min + 1) / 2 + min));
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