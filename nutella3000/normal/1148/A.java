import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        long a = nextInt();
        long b = nextInt();
        long c = nextInt();
        long ans = 2 * c + Math.min(b, a) * 2;
        if (a != b) ans++;
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}