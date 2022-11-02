import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        double b[] = new double [n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        double max= 0;
        double now = 0;
        for (int i = k - 1; i< n; i++) {
            now = 0;
            for (int j = 0; j <= i; j++) {
                now += b[j];
            }
            max = Math.max(max,now / (i + 1));
            for (int j = i + 1; j < n; j++) {
                now = now + b[j] - b[j - i - 1];
                max = Math.max(max,now / (i +1));
            }
        }
        pw.print(max);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st= new StringTokenizer("");
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
}