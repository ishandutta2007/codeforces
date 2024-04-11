import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static long n, p, d, w;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        n = sc.nextLong();
        p = sc.nextLong();
        d = sc.nextLong();
        w = sc.nextLong();
        if (p == 0) {
            System.out.println(0 + " " + 0 + " " + n);
            return;
        }
        for(int i = 0;i < Math.min(n, w);i++) {
            if ((p - i * d) >= 0 && (p - i * d) % w == 0) {
                long first = (p -(i * d)) / (d * w) * w + i;
                long second = ((p - i * d) % (w * d)) / w;
                if (first + second > n) continue;
                System.out.println(first + " " + second + " " + (n - first - second));
                return;
            }
        }
        pw.println(-1);
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

class pair {
    long a, b;
    pair(long a, long b) {
        this.a = a;
        this.b = b;
    }
}