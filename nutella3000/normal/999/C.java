import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter pw=  new PrintWriter(System.out);
       int n = nextInt();
       int k = nextInt();
       String s = next();
       char h[]=  s.toCharArray();
       int num = 97;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < s.length(); j++) {
                if (k > 0) {
                    if (h[j] == num + i) {
                        h[j] = '.';
                        k--;
                    }
                }
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (h[i] != '.') {
                pw.print(h[i]);
            }
        }
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