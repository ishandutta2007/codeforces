import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        for(int test = 0;test < q;test++) {
            long a = nextLong();
            long b = nextLong();
            long m = nextLong();
            int n = 0;
            if (a == b) {
                pw.println(1 + " " + a);
            }else {
                while (true) {
                    if ((1l << n) * (a + 1) <= b && b <= (1l << n) * (a + m)) break;
                    if (b < (1l << n) * (a + 1)) break;
                    n++;
                }
                if (b < (1l << n) * (a + 1)) pw.println(-1);
                else {
                    long r[] = new long[n + 1];
                    for (int i = 0; i <= n; i++) r[i] = 1;
                    b -= (1l << n) * (a + 1);
                    for (int i = 0; i <= n; i++) {
                        long cnt = b / (1l << (Math.max(n - i - 1, 0)));
                        if (cnt >= m) cnt-= cnt - m + 1;
                        r[i] += cnt;
                        b -= (1l << (Math.max(n - i - 1, 0))) * cnt;
                    }
                    long ans[] = new long[n + 2];
                    ans[0] = a;
                    pw.print(n + 2 + " " + a + " ");
                    for (int i = 1; i < n + 2; i++) {
                        for (int j = 0; j < i; j++) ans[i] += ans[j];
                        ans[i] += r[i - 1];
                        pw.print(ans[i] + " ");
                    }
                    pw.println();
                }
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}