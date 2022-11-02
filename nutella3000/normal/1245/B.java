import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int a[] = new int [3];
            for(int i = 0;i < 3;i++) a[i] = sc.nextInt();
            char b[] = sc.next().toCharArray();
            int cnt = 0;
            char ans[] = new char[b.length];
            for(int u = 0;u < b.length;u++) {
                char i = b[u];
                if (i == 'R' && a[1] > 0) {
                    a[1]--;
                    cnt++;
                    ans[u] = 'P';
                }
                if (i == 'P' && a[2] > 0) {
                    a[2]--;
                    cnt++;
                    ans[u] = 'S';
                }
                if (i == 'S' && a[0] > 0) {
                    a[0]--;
                    cnt++;
                    ans[u] = 'R';
                }
            }
            for(int i = 0;i < n;i++) {
                if (ans[i] != 'P' && ans[i] != 'S' && ans[i] != 'R') {
                    if (a[1] > 0) {
                        a[1]--;
                        ans[i] = 'P';
                    }else
                    if (a[2] > 0) {
                        a[2]--;
                        ans[i] = 'S';
                    }else
                    if (a[0] > 0) {
                        a[0]--;
                        ans[i] = 'R';
                    }
                }

            }

            if (cnt >= (n + 1) / 2) {
                pw.println("YES");
                pw.println(ans);
            }else pw.println("NO");


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