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
            int n = sc.nextInt();
            int s = sc.nextInt();
            int k = sc.nextInt();
            int ans = inf;
            TreeSet<Integer> used = new TreeSet<>();
            for(int i = 0;i < k;i++) {
                used.add(sc.nextInt());
            }
            for(int i = s + 1;i <= n;i++) {
                if (!used.contains(i)) {
                    ans = i - s;
                    break;
                }
            }
            for(int i = s;i >= 1;i--) {
                if (!used.contains(i)) {
                    ans = Math.min(ans, s - i);
                    break;
                }
            }
            pw.println(ans == inf ? 0 : ans);
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