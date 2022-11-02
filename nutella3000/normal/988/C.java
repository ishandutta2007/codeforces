import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter pw=  new PrintWriter(System.out);
       int k = nextInt();
       TreeMap<Integer,W> b = new TreeMap<>();
        for (int i = 0; i < k; i++) {
            int n = nextInt();
            int sum = 0;
            int c[] = new int [n];
            for (int j = 0; j < n; j++) {
                c[j] = nextInt();
                sum += c[j];
            }
            boolean y = false;
            for (int j = 0; j < n; j++) {
                int an = sum - c[j];
                if (b.containsKey(an) && b.get(an).x != i + 1) {
                    pw.println("YES");
                    pw.println(b.get(an).x + " " + b.get(an).y);
                    pw.println(i + 1 + " " + (j + 1));
                    y = true;
                    b.clear();
                    break;
                }else{
                    b.put(an,new W(i + 1,j + 1));
                }
            }
            if (y) {
                break;
            }
        }
        if (!b.isEmpty()) {
            pw.println("NO");
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
class W{
    int x;
    int y;
    public W(int a,int b) {
        x = a;
        y = b;
    }
}