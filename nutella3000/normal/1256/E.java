import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), i);
        Arrays.sort(a, new pair());
        int dp[] = new int [n];
        int prev[] = new int [n];
        for(int i = 0;i < n;i++) dp[i] = inf;

        for(int i = 2;i < n;i++) {
            for(int j = i - 3;j >= -1 && j >= i - 7;j--) {
                if (j == -1) {
                    if (dp[i] > a[i].x - a[0].x) {
                        dp[i] = a[i].x - a[0].x;
                        prev[i] = -1;
                    }
                }else{
                    if (dp[i] > dp[j] + a[i].x - a[j + 1].x) {
                        dp[i] = dp[j] + a[i].x - a[j + 1].x;
                        prev[i] = j;
                    }
                }
            }
        }

        int ans1 = dp[n - 1];
        int ans2 = 0;
        int ans3[] = new int [n];
        int v = n - 1;
        while(v != -1) {
            ans2++;
            for(int i = v;i > prev[v];i--) ans3[a[i].id] = ans2;
            v = prev[v];
        }

        pw.println(ans1 + " " + ans2);
        for(int i = 0;i < n;i++) pw.print(ans3[i] + " ");

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

class pair implements Comparator<pair> {
    int x, id;
    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }

    pair () {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}