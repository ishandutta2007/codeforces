import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        int max = -1;
        int id = -1;
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            if (a[i] == max) {
                id = -1;
            }
            if (a[i] > max) {
                max = a[i];
                id = i;
            }
        }
        boolean good = true;
        if (id == -1) good = false;
        for(int i = id + 2;i < n;i++) if (a[i] >= a[i - 1]) good = false;
        for(int i = id - 2;i >= 0;i--) if (a[i] >= a[i + 1]) good = false;
        if (good) pw.println("YES");
        else pw.println("NO");
        pw.close();
    }
    static BufferedReader br;

    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;
    /*static String next() throws IOException {
        int c = br.read();
        while (Character.isWhitespace(c)) c = br.read();
        StringBuilder sb = new StringBuilder();
        while (!Character.isWhitespace(c)) {
            sb.appendCodePoint(c);
            c = br.read();
        }
        return sb.toString();
    }*/

    static String next() throws IOException {
        if (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}