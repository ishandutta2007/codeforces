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
        int sum1 = 0;
        int sum2 = 0;
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            sum1 += a[i];
            if (i > 0 && a[0] >= a[i] * 2) {
                sum2+= a[i];
                ans.add(i + 1);
            }else if (i == 0) {
                ans.add(1);
                sum2 += a[0];
            }
        }
        if (sum2 * 2 > sum1) {
            pw.println(ans.size());
            for(int i : ans) pw.print(i +" ");
        }
        else pw.println(0);
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