import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String s = next();
        char h[] = s.toCharArray();
        if (h.length == 1) {
            System.out.println(1 + " " + 1);
            System.out.println(s);
        }else {
            for (int i = 20; i >= 1; i--) {
                if (h.length - i >= 0 && (h.length - i) % (i - 1) <= (h.length - i) / (i - 1)) {
                    System.out.println((h.length - i) / (i - 1) + 1 + " " + i);
                    int ind = 0;
                    for (int j = 0; j < i; j++) {
                        System.out.print(h[ind]);
                        ind++;
                    }
                    System.out.println();
                    for (int j = 1; j <= (h.length - i) / (i - 1); j++) {
                        if ((h.length - i) % (i - 1) >= j) {
                            for (int k = 0; k < i; k++) {
                                System.out.print(h[ind]);
                                ind++;
                            }
                            System.out.println();
                        }
                    }
                    for (int k = 0; k < ((h.length - i) / (i - 1) - (h.length - i) % (i - 1)); k++) {
                        for (int j = 0; j < i - 1; j++) {
                            System.out.print(h[ind]);
                            ind++;
                        }
                        System.out.println("*");
                    }
                    break;
                }
            }
        }
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