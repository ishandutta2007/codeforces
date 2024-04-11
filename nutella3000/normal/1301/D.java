import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int k;
    static ArrayList<Integer> ans1 = new ArrayList<>();
    static ArrayList<String> ans2 = new ArrayList<>();
    static void f(int s, String q) {
        if (s == 0) return;
        if (k == 0) return;
        ans1.add(Math.min(s, k));
        ans2.add(q);
        k -= Math.min(s, k);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        k = sc.nextInt();
        if (4 * n * m - 2 * n - 2 * m < k) {
            pw.println("NO");
            pw.close();
            return;
        }

        pw.println("YES");

        if (n != 1)
        f(1, "D");

        for(int i = 0;i < n - 1;i++) {
            f(m - 1, "R");
            f(m - 1, "L");
            if (i != n - 2) f(1, "D");
        }
        f(n - 1, "U");
        f(m - 1, "R");
        for(int i = 0;i < m - 1;i++) {
            f(n - 1, "D");
            f(n - 1, "U");
            f(1, "L");
        }
        pw.println(ans1.size());
        for(int i = 0;i < ans1.size();i++) {
            pw.println(ans1.get(i) + " " + ans2.get(i));
        }
        //pw.println(k);
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