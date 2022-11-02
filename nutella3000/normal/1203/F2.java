import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int r = sc.nextInt();
        ArrayList<pair> plus = new ArrayList<>();
        ArrayList<pair> minus = new ArrayList<>();

        for(int i = 0;i < n;i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (b > 0) plus.add(new pair(a, b));
            else minus.add(new pair(Math.max(a, -b), -b));
        }

        Collections.sort(plus, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                return Integer.compare(o1.a, o2.a);
            }
        });
        Collections.sort(minus, new pair());

        int cnt_plus = 0;
        for(pair i : plus) {
            if (i.a <= r) {
                cnt_plus++;
                r += i.b;
            }
        }

        int dp[][] = new int [n][n + 1];

        for(int i = 0;i < minus.size();i++) {
            for(int j = 0;j <= n;j++) {
                int prev = r;
                if (i == 0 && j > 0) prev = -inf;
                else if (i != 0) prev = dp[i - 1][j];

                int prev1 = r;
                if (i == 0 && j > 1) prev1 = -inf;
                else if (j == 0) prev1 = -inf;
                else if (i != 0) prev1 = dp[i - 1][j - 1];

                dp[i][j] = prev;
                if (minus.get(i).a <= prev1) dp[i][j] = Math.max(dp[i][j], prev1 - minus.get(i).b);
            }
        }

        int max = 0;
        for(int i = 0;i < minus.size();i++) {
            for(int j = max + 1;j <= n;j++) {
                if (dp[i][j] >= 0) max = j;
            }
        }

        pw.println(max + cnt_plus);
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

class pair implements Comparator<pair>{
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return -Integer.compare(o1.a - o1.b, o2.a - o2.b);
    }
}