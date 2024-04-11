import javax.smartcardio.ATR;
import java.io.*;
import java.util.*;

public class Main {
    public static boolean gl(char h) {
        if (h == 'a' || h == 'o' || h == 'u' || h == 'i' || h == 'e') {
        return true;
        }else{
        return false;
        }
    }
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        String s = next();
        char h[] = s.toCharArray();
        boolean y = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (!gl(h[i]) && h[i] != 'n' && !gl(h[i + 1])) {
                y = false;
            }
        }
        if ((!gl(h[s.length() - 1]) && h[s.length() - 1] != 'n')) {
            y = false;
        }
        if (y) {
            pw.println("YES");
        }else{
            pw.println("NO");
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

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}