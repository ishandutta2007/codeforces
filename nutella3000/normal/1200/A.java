import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char a[] = next().toCharArray();
        boolean b[] = new boolean[10];
        for(int i = 0;i < n;i++) {
            if (a[i] == 'L') {
                for(int j = 0;j < 10;j++) {
                    if (!b[j]) {
                        b[j] = true;
                        break;
                    }
                }
            }else if (a[i] == 'R') {
                for(int j = 9;j >= 0;j--) {
                    if (!b[j]) {
                        b[j] = true;
                        break;
                    }
                }
            }else{
                int c = a[i] - '0';
                b[c] = false;
            }
        }
        for(int i = 0;i < 10;i++) {
            if (b[i]) pw.print(1);
            else pw.print(0);
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

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