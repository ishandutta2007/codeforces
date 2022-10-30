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
            char o1[] = next().toCharArray();
            char o2[] = next().toCharArray();
            int cnt1[] = new int [26];
            int cnt2[] = new int [26];
            for(int i = 0;i < o1.length;i++) cnt1[o1[i] - 'a']++;
            for(int i = 0;i < o2.length;i++) cnt2[o2[i] - 'a']++;
            boolean good = false;
            for(int i = 0;i < 26;i++) if (cnt1[i] != 0 && cnt2[i] != 0) good = true;
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