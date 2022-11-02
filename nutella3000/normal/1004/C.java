import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int b[] = new int [n];
        TreeSet<Integer> c = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        long ans = 0;
        TreeMap<Integer,Integer> d = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            if (d.containsKey(b[i])) {
                d.put(b[i],d.get(b[i]) + 1);
            }else{
                d.put(b[i],1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (d.get(b[i]) == 1) {
             d.remove(b[i]);
            }else{
                d.put(b[i],d.get(b[i]) - 1);
            }
            if (!c.contains(b[i])) {
                c.add(b[i]);
                ans += d.size();
            }
        }
        pw.print(ans);
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