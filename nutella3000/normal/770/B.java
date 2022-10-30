import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char a[] = next().toCharArray();
        boolean y = true;
        int sum = 0;
        for (int i = a.length - 1; i > 0; i--) sum += a[i] - '0';

        if (sum + 1 >= 9 * a.length - 9) {
            pw.println(a);
        } else {
            int id = 0;
            for(int i = 1;i < a.length;i++) {
                if (a[i] != '9') break;
                else id = i;
            }
            for(int i = 0;i < id;i++) pw.print(a[i]);
            if (a[id] != '1') pw.print(a[id] - '0' - 1);
            for(int i = id + 1;i < a.length;i++) pw.print(9);
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