import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        Arrays.sort(a);
        int id1 = 0;
        int id2 = n - 1;
        while(k > 0) {
            if (a[id1] == a[id2]) break;

            while(a[id1] == a[id1 + 1]) id1++;
            while(a[id2] == a[id2 - 1]) id2--;

            if (id1 + 1 < n - id2) {
                long num = Math.min(a[id1 + 1] - a[id1], k / (id1 + 1));
                k -= Math.min(k, (long) (a[id1 + 1] - a[id1]) * (id1 + 1));
                a[id1] += num;
            }else{
                long num = Math.min(a[id2] - a[id2 - 1], k / (n - id2));
                k -= Math.min(k, (long) (a[id2] - a[id2 - 1]) * (n - id2));
                a[id2] -= num;
            }
        }
        pw.println(a[id2] - a[id1]);
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