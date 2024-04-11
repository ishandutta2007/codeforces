import java.io.*;
import java.util.*;


public class Main {
    static long inf = (long) (1e11);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int x = sc.nextInt();
            int a[] = new int [n];
            int max = 0;
            boolean good = false;
            for(int i = 0;i < n;i++) {
                a[i] = sc.nextInt();
                if (a[i] > x) good = true;
                else max = Math.max(max, a[i]);
            }
            int ans = (int) 1e9;

            if (max != 0) {
                ans = x / max;
                x %= max;
                if (x != 0) ans++;
            }
            if (good) ans = Math.min(ans, 2);
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