import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = sc.nextInt();
            int start = 0;
            while(start != n - 1) {
                int id = -1;
                int min = inf;
                for(int i = start;i < n;i++) {
                    if (a[i] < min) {
                        min = a[i];
                        id = i;
                    }
                }
                for(int i = id;i > start;i--)
                    a[i] = a[i - 1];

                a[start] = min;
                start = Math.max(id, start + 1);
            }
            for(int i = 0;i < n;i++) pw.print(a[i] + " ");
            pw.println();
        }

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