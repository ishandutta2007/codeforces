import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static int log(int k) {
        int ans = 0;
        int c = 1;
        while(c < k) {
            c *= 2;
            ans++;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int I = nextInt() * 8;
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        int k = 1;
        int r = 0;
        int ans = inf;
        for(int l = 0;l < n;l++) {
            while(r != n - 1 && (a[r] == a[r + 1] || log(k) == log(k + 1) || log(k + 1) * n <= I)) {
                r++;
                if (a[r] != a[r - 1]) k++;
            }
            ans = Math.min(ans, n - (r - l + 1));
            if (l != n - 1 && a[l] != a[l + 1]) k--;
        }
        pw.println(ans);
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