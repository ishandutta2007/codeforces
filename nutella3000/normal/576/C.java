import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    static void solve() throws IOException {
        int n = sc.nextInt();
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), sc.nextInt(), i);
        Arrays.sort(a, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                int a1 = o1.x / 1000;
                int a2 = o2.x / 1000;
                if (a1 != a2) return Integer.compare(a1, a2);
                if (a1 % 2 == 0) return Integer.compare(o1.y, o2.y);
                return -Integer.compare(o1.y, o2.y);
            }
        });

        for(int i = 0;i < n;i++) {
            pw.print(a[i].id + 1 + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
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
    int x, y, id;
    pair(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }

    pair() {}
}