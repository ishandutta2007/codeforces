import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            char h[] = sc.next().toCharArray();
            int x[] = new int [n];
            int y[] = new int [n];
            TreeMap<pair, Integer> a = new TreeMap<>(new Comparator<pair>() {
                @Override
                public int compare(pair o1, pair o2) {
                    return Integer.compare(o1.x, o2.x) * 2 + Integer.compare(o1.y, o2.y);
                }
            });
            a.put(new pair(0, 0), -1);
            int ans_l = -1;
            int ans_r = inf;

            for(int i = 0;i < n;i++) {
                if (i != 0) {
                    x[i] = x[i - 1];
                    y[i] = y[i - 1];
                }

                if (h[i] == 'L') x[i]--;
                if (h[i] == 'R') x[i]++;
                if (h[i] == 'U') y[i]++;
                if (h[i] == 'D') y[i]--;

                if (a.containsKey(new pair(x[i], y[i])) && i - a.get(new pair(x[i], y[i])) < ans_r - ans_l + 1) {
                    ans_r = i + 1;
                    ans_l = a.get(new pair(x[i], y[i])) + 2;
                }
                a.put(new pair(x[i], y[i]), i);
            }
            if (ans_r == inf) pw.println(-1);
            else pw.println(ans_l + " " + ans_r);
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

class pair {
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}