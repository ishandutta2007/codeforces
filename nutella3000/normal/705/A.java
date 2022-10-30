import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        boolean one = true;
        while(n-- > 1) {
            if (one) pw.print("I hate that ");
            else pw.print("I love that ");
            one = !one;
        }
        if (one) pw.println("I hate it");
        else pw.println("I love it");
        //if (n % 2 == 1) pw.println("I hate it");
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