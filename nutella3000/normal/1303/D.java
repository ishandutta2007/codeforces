
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
            long n = sc.nextLong();
            int m = sc.nextInt();
            int cnt[] = new int [60];
            for(int i = 0;i < m;i++) {
                long a = sc.nextLong();
                int q = 0;
                while(a > 1) {
                    q++;
                    a >>= 1;
                }

                cnt[q]++;
            }

            long sum = 0;
            int ans = 0;
            for(int i = 0;i < 60;i++) {
                long q = (1L << i);
                sum += q * cnt[i];
                if ((n & q) == 0) continue;
                if (sum < q) {
                    for(int j = i + 1;j < 60;j++) {
                        if (cnt[j] == 0 && j == 59) ans = inf;
                        if (cnt[j] == 0) continue;
                        for(int w = i + 1;w < j;w++) cnt[w]++;
                        cnt[j]--;
                        ans += j - i;
                        break;
                    }
                    sum += q;
                }

                sum -= q;
            }
            if (ans >= inf) pw.println(-1);
            else pw.println(ans);
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