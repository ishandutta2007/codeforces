import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), sc.nextInt());

        Arrays.sort(a, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                return Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.b, o2.b);
            }
        });

        int last = -1;
        int ans = -1;
        for(int i = 0;i < n;i++) {
            if (last > a[i].b) {
                last = a[i].a;
                ans = a[i].a;
            }
            else {
                last = a[i].b;
            }
        }
        pw.println(last);

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
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
}