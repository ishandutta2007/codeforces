import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char s[] = next().toCharArray();
        int k = nextInt();
        int ans = 0;
        for(int i = s.length - 1;i >= 0;i--) {
            if (s[i] != '0') ans++;
            else k--;
            if (k == 0) break;
        }

        if (k != 0) ans = s.length - 1;

        pw.println(ans);
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