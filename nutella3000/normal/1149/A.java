import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        if (a[n - 1] == 1) {
            for(int i = 0;i < n;i++) pw.print(1 + " ");
        }else{
            pw.print(a[n - 1] + " ");
            if (n != 1) pw.print(a[0] + " ");
            for(int i = n - 2;i >= 1;i--) pw.print(a[i] + " ");
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}