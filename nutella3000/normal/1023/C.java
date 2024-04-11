import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        String s = next();
        char h[] = s.toCharArray();
        int countEnd = 0;
        int countStart = 0;
        for (int i = 0; i < h.length; i++) {
            if (h[i] == ')') {
                countEnd++;
            }
        }
        int now = 0;
        for (int i = 0; i < h.length; i++) {
            if (h[i] == '(' && countEnd >= countStart + 1 && now + countStart + 1 <= k) {
                countStart++;
                now++;
                pw.print("(");
            }
            if (h[i] == ')') {
                if (countStart > 0) {
                    countStart--;
                    countEnd--;
                    now++;
                    pw.print(")");
                }
            }
        }
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
}