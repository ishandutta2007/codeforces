import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
public class Main {
    static int inf = (int) 1e9 + 7;

    static char[] add_zero(char a[], int size) {
        char ans[] = new char[size];
        for(int i = 0;i < size - a.length;i++) ans[i] = '0';
        for(int i = size - a.length;i < size;i++) ans[i] = a[i - size + a.length];
        return ans;
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            char l[] = add_zero(Integer.toBinaryString(sc.nextInt()).toCharArray(), 32);
            char r[] = add_zero(Integer.toBinaryString(sc.nextInt()).toCharArray(), 32);

            long dp[][] = new long[33][16];
            for(int i = 0;i < 16;i++) dp[32][i] = 1;

            for(int i = 31;i >= 0;i--) {
                for(int j = 0;j < 16;j++) {
                    for(int o1 = 0;o1 <= 1;o1++) {
                        for(int o2 = 0;o2 <= 1;o2++) {

                            int l1 = (j & 1);
                            int r1 = (j & 2);
                            int l2 = (j & 4);
                            int r2 = (j & 8);

                            if (o1 == 1 && o2 == 1) continue;
                            if (l1 == 0 && l[i] == '1' && o1 == 0) continue;
                            if (r1 == 0 && r[i] == '0' && o1 == 1) continue;
                            if (l2 == 0 && l[i] == '1' && o2 == 0) continue;
                            if (r2 == 0 && r[i] == '0' && o2 == 1) continue;

                            if (l[i] == '0' && o1 == 1) l1 = 1;
                            if (r[i] == '1' && o1 == 0) r1 = 2;
                            if (l[i] == '0' && o2 == 1) l2 = 4;
                            if (r[i] == '1' && o2 == 0) r2 = 8;
                            dp[i][j] += dp[i + 1][l1 + r1 + l2 + r2];
                        }
                    }
                }
            }

            pw.println(dp[0][0]);
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