import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter pw=  new PrintWriter(System.out);
       int n = nextInt();
       String b[] = new String [n];
        for (int i = 0; i < n; i++) {
            b[i] = next();
        }
        String c[] = new String [n];
        for (int i = 0; i < n; i++) {
            int min = 101;
            int loc = 0;
            for (int j = 0; j < n; j++) {
                if (b[j].length() < min) {
                    min = b[j].length();
                    loc = j;
                }
            }
            c[i] = b[loc];
            b[loc] = "asdjkladjdkal;dasjkjads" +
                    "l;jdkkjl;afjklafjkflajf;akljdalsjflakdjf;alkdjf;lkajsdfl;kjal;dkfj;a" +
                    "lkdjfl;kajf;lkjasl;dfkjla;jdf;flakjdl;fjald;kjf;lajdfl;ajd";
        }
        boolean y = true;
        for (int i = 1; i < n; i++) {
            boolean t = false;
            char h[] = c[i].toCharArray();
            for (int j = 0; j < c[i].length() - c[i - 1].length() + 1; j++) {
                String r = "";
                for (int k = j; k < c[i - 1].length() + j; k++) {
                    r += h[k];
                }
                if (r.equals(c[i  - 1])) {
                    t = true;
                }
            }
            if (!t) {
                y = false;
            }
        }
        if (!y) {
            pw.print("NO");
        }else{
            pw.println("YES");
            for (int i = 0; i < c.length; i++) {
                pw.println(c[i]);
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