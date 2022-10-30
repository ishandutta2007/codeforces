import java.io.*;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            int n = nextInt();
            int a[] = new int [2049];
            for(int i = 0;i < n;i++) {
                int next = nextInt();
                int v = next;
                while(v * 2 <= 2048 && a[v] != 0) {
                    a[v] = 0;
                    v *= 2;
                }
                if (v <= 2048) a[v]++;
            }
            if (a[2048] == 0) pw.println("NO");
            else pw.println("YES");
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