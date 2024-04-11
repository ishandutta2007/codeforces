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
        int y = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int ans = -1;
        for(int i = 0;i < n;i++) {
            boolean good = true;
            for(int j = 1;j <= x;j++) {
                if (i - j < 0) continue;
                if (a[i - j] < a[i]) good = false;
            }
            for(int j = 1;j <= y;j++) {
                if (i + j >= n) continue;
                if (a[i + j] < a[i]) good = false;
            }
            if (good) {
                ans = i;
                break;
            }
        }
        pw.println(ans + 1);
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

class pair {
    int x, y;

    pair(int a, int b) {
        x = a;
        y = b;
    }

    pair() {
    }
}