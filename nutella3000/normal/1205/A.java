import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        if (n % 2 == 0) pw.println("NO");
        else{
            pw.println("YES");
            int a[] = new int [2 * n];
            int num = 1;
            for(int i = 0;i < n;i++) {
                a[i] = num;
                if (i % 2 == 0) num += 3;
                else num++;
            }
            for(int i = 0;i < n;i++) {
                if (i % 2 == 0) a[i + n] = a[i] + 1;
                else a[i + n] = a[i] - 1;
            }
            for(int i = 0;i < 2 * n;i++) pw.print(a[i] + " ");
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