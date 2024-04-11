import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static long inf = (long) 1e15 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            int n = nextInt();
            int sum = 0;
            for(int i = 0;i < n;i++) sum += nextInt();
            pw.println((sum + n - 1) / n);
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