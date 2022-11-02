import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        if (m % n != 0) {
            pw.print(-1);
        }else{
            m /= n;
            int cnt = 0;
            while(m % 2 == 0) {
                m /= 2;
                cnt++;
            }
            while(m % 3 == 0) {
                m /= 3;
                cnt++;
            }
            if (m == 1) pw.print(cnt);
            else pw.print(-1);
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
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}