import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int)1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int l = 0;
        int r = 0;
        int log_n = 1;
        int n1 = 1;
        while(n1 < n) {
            log_n++;
            n1 *= 2;
        }
        for(int i = 0;i < log_n;i++) {
            for(int j = 0;j < n - (1 << i) + 1;j+= (1 << i)) {
                int b = -1;
                for(int k = j;k <j +  (1 << i);k++) {
                    if (b <= a[k]) b = a[k];
                    else b = 101;
                }
                if (b != 101) {
                    l = j + 1;
                    r = j + 1 + (1 << i) - 1;
                }
            }
        }
        pw.print(r - l + 1);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
class pair implements Comparator<pair> {
    int a,  b, id;

    pair(int x, int y, int id) {
        a = x;
        b = y;
        this.id = id;
    }

    pair() {
    }

    @Override
    public int compare(pair o1, pair o2) {
        return - Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.id, o2.id);
    }
}