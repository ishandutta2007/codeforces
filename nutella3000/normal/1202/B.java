import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char temp[] = sc.next().toCharArray();
        int a[] = new int [temp.length];
        for(int i = 0;i < temp.length;i++) a[i] = temp[i] - '0';

        for(int x = 0;x < 10;x++) {
            for(int y = 0;y < 10;y++) {
                int cnt[][] = new int [10][10];
                for(int i = 0;i < 10;i++) for(int j = 0;j < 10;j++) cnt[i][j] = inf;

                for(int i = 0;i < 10;i++) {
                    cnt[i][(i + x) % 10] = 1;
                    cnt[i][(i + y) % 10] = 1;
                }

                for(int k = 0;k < 10;k++) {
                    for(int i = 0;i < 10;i++) {
                        for(int j = 0;j < 10;j++) {
                            cnt[i][j] = Math.min(cnt[i][j], cnt[i][k] + cnt[k][j]);
                        }
                    }
                }

                int last = 0;
                long ans = 0;
                for(int i = 1;i < a.length;i++) {
                    int v = a[i];
                    ans += cnt[last][v];
                    last = v;
                }

                if (ans >= inf) pw.print(-1 + " ");
                else pw.print((ans - a.length + 1) + " ");
            }
            pw.println();
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