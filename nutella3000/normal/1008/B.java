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
        int n = nextInt();
        int a;
        int b;
        int prb = -1;
        boolean ans = true;
        for (int i = 0; i < n; i++) {
            a = nextInt();
            b = nextInt();
            if (prb == -1) {
                b = Math.max(a,b);
            }else{
                if (prb < Math.max(a,b)) {
                    if (prb < Math.min(a,b)) {
                        ans = false;
                    }else{
                        b = Math.min(a,b);
                    }
                }else{
                    b = Math.max(a,b);
                }
            }
            prb = b;
        }
        if (ans) {
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