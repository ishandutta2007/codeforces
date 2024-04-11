import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static long pow(long a, long b) {
        long ans = 1;
        while(b != 0) {
            if ((b & 1) != 0) {
                ans = (ans * a) % inf;
            }
            a = (a * a) % inf;
            b /= 2;
        }

        return ans;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int x = nextInt();
        long n = nextLong();
        ArrayList<Integer> var = new ArrayList<>();
        for(int i = 2;i <= Math.sqrt(x);i++) {
            if (x % i == 0) {
                while(x % i == 0) x/= i;
                var.add(i);
            }
        }
        if (x != 1) var.add(x);
        long ans = 1;

        for(long d : var) {
            long v = n;
            long new_d = 1;
            long two = 1;
            while(v != 0) {
                long one = pow(new_d, v - v / d) % inf;
                two = (two * one) % inf;
                new_d = (new_d * d) % inf;
                v /= d;
            }
            ans = (ans * two) % inf;
        }
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}