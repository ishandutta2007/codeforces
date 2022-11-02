import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        pair a[] = new pair [n];
        for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), i);
        Arrays.sort(a, new pair());
        long ans[] = new long[n];
        long b[][] = new long[m][(n + m) / m];
        for(int i = 0;i < m;i++) {
            for(int j = 0;j * m + i < n;j++) {
                b[i][j] = a[i + j * m].a;
                if (j != 0) b[i][j] += b[i][j - 1];
            }
        }
        for(int i = 0;i < n;i++) {
            ans[i] = a[i].a;
            if (i != 0) ans[i] += ans[i - 1];
            if (i / m - 1 >= 0) {
                ans[i] += b[i % m][i / m - 1];
            }
        }

        for(long i : ans) pw.print(i + " ");

        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class pair implements Comparator<pair>{
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
    pair() {}

    @Override
    public int compare(pair o1, pair t1) {
        return Integer.compare(o1.a, t1.a);
    }
}