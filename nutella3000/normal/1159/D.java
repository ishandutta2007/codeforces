import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int v = nextInt();
        int k = (n + 2 - v) / 2;
        if (v == 1) {
            pw.print(0);
            for(int i = 1;i < n;i++) pw.print(1);
            pw.close();
        }
        int ans[] = new int [k];
        for(int i = 1;i < k;i++) {
            ans[i] = 1;
        }
        for(int i = 0;i < n;i++) {
            pw.print(ans[i % k]);
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