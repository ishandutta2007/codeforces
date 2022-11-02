import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    static int pow(int a, int b) {
        int ans = 1;
        for(int i = 0;i < b;i++) ans *= a;
        return ans;
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int v1[] = new int [m], v2[] = new int [m];
        for(int i = 0;i < m;i++) {
            v1[i] = sc.nextInt() - 1;
            v2[i] = sc.nextInt() - 1;
        }

        int ans = 0;
        for(int mask = 0;mask < pow(6, n);mask++) {
            int num[] = new int [n];
            for(int i = 0;i < n;i++) {
                num[i] = mask / pow(6, i) % 6;
            }

            boolean used[][] = new boolean[6][6];
            int new_ans = 0;
            for(int i = 0;i < m;i++) {
                int q1 = num[v1[i]];
                int q2 = num[v2[i]];
                if (!used[q1][q2]) {
                    new_ans++;
                    used[q1][q2] = true;
                    used[q2][q1] = true;
                }
            }
            ans = Math.max(ans, new_ans);
        }

        pw.println(ans);

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