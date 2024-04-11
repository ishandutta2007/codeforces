import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 1;i < n;i++) {
            if (h[i] == 'S' && h[i - 1] == 'F') cnt1++;
            else if (h[i] == 'F' && h[i - 1] == 'S') cnt2++;
        }
        if (cnt2 - cnt1 > 0) pw.println("YES");
        else pw.println("NO");
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

    /*static long nextLong() throws IOException {
        return Long.parseLong(next());
    }*/

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}