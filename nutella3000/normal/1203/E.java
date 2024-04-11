import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        Integer a[] = new Integer [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        int cnt = 0;
        int last = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] + 1 > last) {
                cnt++;
                last = Math.max(last + 1, a[i] - 1);
            }
        }
        pw.println(cnt);
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