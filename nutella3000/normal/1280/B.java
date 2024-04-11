import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int t = sc.nextInt();t > 0;t--) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            char h[][] = new char[n][];
            for(int i = 0;i < n;i++) h[i] = sc.next().toCharArray();

            boolean all_bad = true;
            boolean middle = true;
            boolean not_cor = true;
            int cnt_good = 0;

            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    if (h[i][j] == 'P') continue;
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) middle = false;
                    all_bad = false;
                    if ((i == 0 && j == 0) || (i == 0 && j == m - 1) ||
                            (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                        not_cor = false;
                    }
                    cnt_good++;
                }
            }

            if (all_bad) {
                pw.println("MORTAL");
                continue;
            }

            if (middle) {
                pw.println(4);
                continue;
            }

            if (not_cor) {
                boolean good = false;
                int cnt;

                for(int i = 0;i < n;i++) {
                    cnt = 0;
                    for(int j = 0;j < m;j++) {
                        if (h[i][j] == 'A') cnt++;
                    }
                    if (cnt == m) good = true;
                }

                for(int j = 0;j < m;j++) {
                    cnt = 0;
                    for(int i = 0;i < n;i++) {
                        if (h[i][j] == 'A') cnt++;
                    }
                    if (cnt == n) good = true;
                }

                if (good) pw.println(2);
                else pw.println(3);
                continue;
            }

            if (cnt_good != n * m) {
                int x[] = new int []{0, n - 1};
                int y[] = new int []{0, m - 1};

                int cnt = 0;
                boolean good = false;
                for(int i : x) {
                    cnt = 0;
                    for(int j = 0;j < m;j++) {
                        if (h[i][j] == 'A') cnt++;
                    }
                    if (cnt == m) good = true;
                }

                for(int j : y) {
                    cnt = 0;
                    for(int i = 0;i < n;i++) {
                        if (h[i][j] == 'A') cnt++;
                    }
                    if (cnt == n) good = true;
                }

                if (good) pw.println(1);
                else pw.println(2);


            }else pw.println(0);



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