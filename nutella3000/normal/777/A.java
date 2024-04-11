import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int x = nextInt();
        if (x == 1) {
            if (n % 2 == 1) x = 0;
            else x = 2;
            n--;
        }

        n %= 6;
        while(n != 0) {
            if (n % 2 == 1) {
                if (x != 2) x = 1 - x;
            }else{
                if (x != 0) x = 3 - x;
            }
            n--;
        }
        pw.println(x);
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