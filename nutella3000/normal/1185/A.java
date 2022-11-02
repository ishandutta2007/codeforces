import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int a[] = new int [3];
        int d;
        for(int i = 0;i < 3;i++) a[i] = nextInt();
        d = nextInt();
        Arrays.sort(a);
        int ans = Math.max(0, d - (a[1] - a[0])) + Math.max(0, d - (a[2] - a[1]));
        pw.print(ans);
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