import java.io.*;
import java.util.*;
public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        String s = next();
        char h[] = s.toCharArray();
        int count[] = new int [26];
        for (int i = 0; i < h.length; i++) {
            count[h[i] - 'a']++;
        }
        int c = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 1) {
                c++;
            }
        }
        if (c == 0 && n != 1) {
            pw.println("No");
        }else{
            pw.println("Yes");
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