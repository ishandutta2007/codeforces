import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int a[][] = new int [n][];
        for(int i = 0;i < n;i++) {
            int l = sc.nextInt();
            a[i] = new int [l];
            for(int j = 0;j < l;j++) a[i][j] = sc.nextInt();
        }

        long ans = (long) n * (n - 1);

        boolean b[] = new boolean[n];

        ArrayList<Integer> max = new ArrayList<>();

        for(int i = 0;i < n;i++) {
            int last = inf;
            b[i] = true;
            for(int j = 0;j < a[i].length;j++) {
                if (last < a[i][j]) b[i] = false;
                last = a[i][j];
            }
            if (b[i]) max.add(a[i][0]);
        }

        Collections.sort(max);

        for(int i = 0;i < n;i++) {
            if (!b[i]) continue;
            int min = a[i][a[i].length - 1];
            int l = -1;
            int r = max.size();
            while(r - l > 1) {
                int mid = ((l + r) >> 1);
                if (max.get(mid) > min) r = mid;
                else l = mid;
            }
            ans -= l + 1;
        }

        pw.println(ans + n);


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