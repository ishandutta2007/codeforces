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
            char o[][] = new char[2][];
            for(int i = 0;i < 2;i++) o[i] = next().toCharArray();
            boolean good = true;
            //if (o[0][0] > '2') good = false;
            int num = 0;

            for(int i = 0;i < n;i++) {
                if (o[num][i] <= '2') continue;
                if (o[1 - num][i] <= '2') good = false;
                num = 1 - num;
            }
            if (num != 1) good = false;
            if (good) pw.println("YES");
            else pw.println("NO");
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