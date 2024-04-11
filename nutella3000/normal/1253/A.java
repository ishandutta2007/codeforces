import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int a[] = new int [n];
            int b[] = new int [n];
            int last = -1;
            int num = -1;
            for(int i = 0;i < n;i++) {
                a[i] = sc.nextInt();
            }
            boolean bad = false;
            for(int i = 0;i < n;i++) {
                b[i] = sc.nextInt();
                if (a[i] != b[i]) {
                    if (b[i] < a[i]) bad = true;
                    if (last != -1 && last != i - 1) bad = true;
                    if (last != -1 && num != b[i] - a[i]) bad = true;
                    last = i;
                    num = b[i] - a[i];
                }
            }
            if (bad) pw.println("NO");
            else pw.println("YES");
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