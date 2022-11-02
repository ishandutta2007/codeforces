import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) a[i][j] = sc.nextInt();
        }

        int id[] = new int [(1 << m)];
        for(int mask = 0;mask < (1 << m);mask++) {
            int ans = -1;
            for(int i = 0;i < n;i++) {
                int min = inf;
                for(int j = 0;j < m;j++) {
                    if ((mask & (1 << j)) != 0) {
                        min = Math.min(min, a[i][j]);
                    }
                }
                if (ans < min) {
                    ans = min;
                    id[mask] = i;
                }
            }
        }

        int ans1 = 0, ans2 = 0, ans = -1;
        for(int mask = 0;mask < (1 << m);mask++) {
            int i1 = id[mask];
            int i2 = id[(1 << m) - mask - 1];
            int new_ans = inf;
            for(int i = 0;i < m;i++) {
                new_ans = Math.min(new_ans, Math.max(a[i1][i], a[i2][i]));
            }
            if (new_ans > ans) {
                ans1 = i1 + 1;
                ans2 = i2 + 1;
                ans = new_ans;
            }
        }

        pw.println(ans1 + " " + ans2);


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

class pair {
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    pair() {}
}