import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static long fi(long n) {
        ArrayList<Long> p = new ArrayList<>();
        ArrayList<Integer> cnt = new ArrayList<>();
        long one = 1;
        for(long i = 2;i <= Math.sqrt(n);i++) {
            if (n % i == 0) {
                p.add(i);
                int v = 0;
                while(n % i == 0) {
                    v++;
                    n /= i;
                }
                cnt.add(v);
                one *= (i - 1);
            }
        }
        if (n != 1) {
            p.add(n);
            cnt.add(1);
            one *= (n - 1);
        }

        long two = 1;
        for(int i = 0;i < p.size();i++) {
            for(int j = 0;j < cnt.get(i) - 1;j++) two *= p.get(i);
        }

        return one * two;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        long n = nextLong();
        long k = nextLong();
        while(k > 0 && n > 1) {
            n = fi(n);
            k-= 2;
        }
        pw.println(n % inf);
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
}