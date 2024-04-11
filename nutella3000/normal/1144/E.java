import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        char a[] = next().toCharArray();
        char b[] = next().toCharArray();
        int a1[] = new int[n];
        int b1[] = new int[n];
        int ans[] = new int[n];
        for (int i = 0; i < n; i++) {
            a1[i] = a[i] - 'a' + 1;
            b1[i] = b[i] - 'a' + 1;
            ans[i] = a1[i] + b1[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i] > 26 && i != 0) {
                ans[i] -= 26;
                ans[i - 1]++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (ans[i] % 2 == 0) ans[i] /= 2;
            else {
                ans[i] /= 2;
                ans[i + 1] += 13;
            }
        }
        for(int i = n - 1;i >= 1;i--) {
            if (ans[i] == 0) {
                ans[i]+= 26;
                ans[i - 1]--;
            }
        }
        for(int i = 0;i < n;i++) {
            pw.print((char) (ans[i] +(int) 'a' - 1));
        }
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
    int a, b, id;

    pair(int x, int y, int id) {
        a = x;
        b = y;
        this.id = id;
    }

    pair() {
    }

    @Override
    public int compare(pair o1, pair o2) {
        return -Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.id, o2.id);
    }
}