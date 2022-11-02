import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int b[] = new int [n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        int count[] = new int [101];
        for (int i = 0; i < n; i++) {
            count[b[i]]++;
        }
        int a = 0;
        int c  =0;
        for (int i = 0; i < 101; i++) {
            if (count[i] != 0) a++;
            if (count[i] > c) c = count[i];
        }
        c = (c + k - 1) / k;
        pw.println(c * a * k- b.length);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    public static int nextInt() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
    public static String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    public static long nextLong() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
    public static double nextDouble() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }
}