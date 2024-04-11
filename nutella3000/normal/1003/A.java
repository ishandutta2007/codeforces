import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        TreeMap<Integer,Integer> b = new TreeMap<>();
        int max = 0;
        for (int i = 0; i < n; i++) {
            int a = nextInt();
            if (b.containsKey(a)) {
                b.put(a,b.get(a) + 1);
            }else{
                b.put(a,1);
            }
            max = Math.max(max,b.get(a));
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