import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        int max = 0;
        long sum = 0;
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            if (a[i] > max) max = a[i];
            sum += a[i];
        }
        sum -= max;
        if (sum < max || (sum + max) % 2 == 1) pw.println("NO");
        else pw.println("YES");
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