import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            int n = nextInt();
            int last = nextInt() - 1;
            boolean one = true;
            boolean two = true;
            for(int i = 0;i < n - 1;i++) {
                int next = nextInt() - 1;
                if (next != (last + 1) % n) one = false;
                if (next != (last - 1 + n) % n) two = false;
                last = next;
            }
            if (!one && !two) pw.println("NO");
            else pw.println("YES");
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