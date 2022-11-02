import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int one = 1;
        int two = n;
        while (two - one > 0) {
            int y = 1;
            int x = 0;
            while (true) {
                if (x == 0 && y == m + 1) break;
                if (x == 0) {
                    pw.println(one + " " + y);
                    y = m - y + 1;
                } else {
                    pw.println(two + " " + y);
                    y = m - y + 2;
                }
                x = 1 - x;
            }
            two--;
            one++;
        }
        if (one == two) {
            int y = 1;
            while (true) {
                pw.println(one + " " + y);
                if (y <= m / 2) y = m - y + 1;
                else {
                    if (y == m / 2 + 1) break;
                    y = m - y + 2;
                }
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        while (!st.hasMoreTokens() || st == null) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}