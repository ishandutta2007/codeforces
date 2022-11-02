import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int t = sc.nextInt();t > 0;t--) {
            int x = sc.nextInt();
            char h[] = sc.next().toCharArray();
            int n = h.length;
            long ans = n;
            int mod = inf;

            char r[] = new char[x + 1];

            for(int i = 0;i < Math.min(n, x);i++) {
                r[i] = h[i];
            }

            int sz = n;

            for(int id = 0;id < x;id++) {
                ans -= id + 1;
                ans *= r[id] - '0';
                ans += id + 1;
                ans %= mod;

                int prev_sz = sz;
                for(int q = 0;q < r[id] - '0' - 1;q++) {
                    for(int w = id + 1;w < prev_sz;w++) {
                        if (sz >= r.length) break;
                        r[sz++] = r[w];
                    }
                }
            }

            pw.println((ans + mod) % mod);


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