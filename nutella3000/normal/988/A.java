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
       int b[] = new int [n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        ArrayList<Integer> c = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            boolean t = true;
            for (int j = 0; j < c.size(); j++) {
                if (b[i] == b[c.get(j)]) {
                    t = false;
                }
            }
            if (t) {
                c.add(i);
            }
        }
        if (c.size() < k) {
            pw.print("NO");
        }else{
            pw.println("YES");
            for (int i = 0; i < k; i++) {
                pw.print(c.get(i)  + 1+ " ");
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