import java.io.*;
import java.util.*;
public class main {
    static long b[][];
    public static long NOD(long a,long b) {
        if (a == 0|| b == 0) {
            return a + b;
        }
        return NOD(b,a % b);
    }
    public static long NOK(long a,long b) {
        return (a * b) / NOD(a,b);
    }
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        b = new long [n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                b[i][j] = nextInt();
            }
        }
        long c[] = new long [n];
        for (int i = 0; i < n; i++) {
            c[i] = NOK(b[i][0],b[i][1]);
        }
        long ans = c[0];
        for (int i = 1; i < n; i++) {
            ans = NOD(Math.max(ans,c[i]),Math.min(ans,c[i]));
        }
        if (ans == 1) {
            pw.println(-1);
        }else{
            long g = 0;
            for (int i = 2; i <= Math.sqrt(b[0][0]); i++) {
                if (ans % i == 0 && b[0][0] % i == 0) {
                    g = i;
                    break;
                }
            }
            if (g == 0) {
                for (int i = 2; i <= Math.sqrt(b[0][1]); i++) {
                    if (ans % i == 0 && b[0][1] % i == 0) {
                        g = i;
                        break;
                    }
                }
            }
            if (g == 0) {
                for (int i = (int) Math.sqrt(b[0][0]); i >= 2; i--) {
                    if (ans % (b[0][0] / i) == 0 && b[0][0] % i == 0) {
                        g = (b[0][0] / i);
                        break;
                    }
                }
            }
            if (g == 0) {
                for (int i = (int) Math.sqrt(b[0][1]); i >= 2; i--) {
                    if (ans % (b[0][1] / i) == 0 && b[0][1] % i == 0) {
                        g = (b[0][1] / i);
                        break;
                    }
                }
            }
            if (g == 0) {
                if (ans % b[0][0] == 0) {
                    g = b[0][0];
                }else{
                    g = b[0][1];
                }
            }
            pw.println(g);
        }
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
}