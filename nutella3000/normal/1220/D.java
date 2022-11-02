import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        long a[] = new long [n];
        int num[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = sc.nextLong();
            long v = a[i];
            while(v % 2 == 0) {
                v /= 2;
                num[i]++;
            }
        }

        int cnt[] = new int [70];
        for(int i = 0;i < n;i++) cnt[num[i]]++;
        int id = 0;
        for(int i = 0;i < 70;i++) if (cnt[id] < cnt[i]) id = i;


        pw.println(n - cnt[id]);
        for(int i = 0;i < n;i++) {
            if (num[i] != id) pw.print(a[i] + " ");
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