import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = 100;
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();

        for(int i = 1;i < 10;i += 2) {
            int b[] = new int [10];
            for(int j = 0;j < 10;j++) b[j] = a[i * 10 + j];
            for(int j = 0;j < 10;j++) a[i * 10 + 10 - j - 1] = b[j];
        }

        for(int i = 0;i < 10;i++) {
            for(int j = 0;j < 10;j++) {
                int v = i * 10 + j;
                if (a[v] == 0) continue;
                if (i % 2 == 0) {
                    if (a[v] % 2 == 0) {
                        a[v] = 10 * a[v];
                    }else {
                        a[v] = 2 * j + 1 + a[v] * 10 - 10;
                    }
                }else{
                    if (a[v] % 2 == 0) {
                        a[v] = 10 * a[v];
                    }else{
                        a[v] = 10 * a[v] - 10 + (j) * 2 + 1;
                    }
                }
            }
        }

        double ans[] = new double[n];
        double ans2[] = new double[n];
        ans[0] = 0;
        for(int i = 1;i <= 6;i++) ans[i] = 6;
        for(int i = 1;i <= 6;i++) ans2[i] = 6;

        for(int i = 7;i < 100;i++) {
            double sum = 0;
            for(int j = 1;j <= 6;j++) sum += ans[i - j];
            ans[i] = sum / 6 + 1;
            if (a[i] != 0) ans[i] = Math.min(ans2[i - a[i]], ans[i]);

            ans2[i] = sum / 6 + 1;
        }


        pw.println(ans[99]);
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


class city implements Comparator<city>{
    int x, y, c, k, id;

    city() {}

    @Override
    public int compare(city o1, city o2) {
        return Integer.compare(o1.c, o2.c);
    }
}