import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter pw=  new PrintWriter(System.out);
       int n = nextInt();
       String s = next();
       ArrayList<Integer> d = new ArrayList<>();
        for (int i = 1; i < Math.sqrt(n); i++) {
            if (n % i == 0) {
                d.add(i);
                d.add(n / i);
            }
        }
        if ((int)Math.sqrt(n) * (int)Math.sqrt(n) == n) {
            d.add((int) Math.sqrt(n));
        }
        Collections.sort(d);
        char h[] = s.toCharArray();
        for (int i = 0; i < d.size(); i++) {
            char g[] = new char[d.get(i)];
            for (int j = 0; j < d.get(i); j++) {
                g[d.get(i) - j - 1] = h[j];
            }
            for (int j = 0; j < d.get(i); j++) {
                h[j] = g[j];
            }
        }
        for (int i = 0; i < h.length; i++) {
            pw.print(h[i]);
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