import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String s = next();
        char h[] = s.toCharArray();
        int pref = 1;
        int suf = 1;
        int max = 1;
        for (int i = 1; i < h.length; i++) {
            if (h[i] != h[i - 1]) {
                pref++;
            }else{
                break;
            }
        }
        for (int i = h.length - 2; i >= 0; i--) {
            if (h[i] != h[i + 1]) {
                suf++;
            }else{
                break;
            }
        }
        int m = 1;
        for (int i = 1; i < h.length; i++) {
            if (h[i] != h[i - 1]) {
                m++;
            }else{
                max = Math.max(max,m);
                m = 1;
            }
        }
        max = Math.max(max,m);
        if (h[0] != h[h.length - 1]) {
            max = Math.max(pref + suf,max);
        }
        pw.println(Math.min(h.length,max));
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