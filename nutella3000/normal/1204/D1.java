import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static char a[];

    static void check(int num) {
        int cnt = 0;
        for(int i = num - 1;i >= 0;i--) {
            if (a[i] == '0') cnt++;
            else cnt--;
            if (cnt < 0) return;
        }
        cnt = 0;
        for(int i = num + 1;i < n;i++) {
            if (a[i] == '1') cnt++;
            else cnt--;
            if (cnt < 0) return;
        }
        a[num] = '0';
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        a = next().toCharArray();
        n = a.length;
        for(int i = 0;i < n;i++) {
            check(i);
        }
        for(int i = 0;i < n;i++) pw.print(a[i]);
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