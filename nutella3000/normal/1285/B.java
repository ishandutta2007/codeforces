import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int q = sc.nextInt();q > 0;q--) {
            int n = sc.nextInt();
            boolean good = true;
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = sc.nextInt();
            long sum = 0;
            long pref = 0;
            for(int i = 0;i < n;i++) sum += a[i];
            for(int i = 0;i < n - 1;i++) {
                pref += a[i];
                if (pref <= 0) good = false;
            }
            pref = 0;
            for(int i = n - 1;i >= 1;i--) {
                pref += a[i];
                if (pref <= 0) good = false;
            }

            if (good) pw.println("YES");
            else pw.println("NO");



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

class edge {
    int to, cost, id;
    edge(int to, int cost, int id) {
        this.to = to;
        this.cost = cost;
        this.id = id;
    }

    edge() {}
}