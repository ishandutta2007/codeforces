import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int cnt[] = new int [n];
        for(int i = 0;i < n - 1;i++) {
            int from = nextInt() - 1;
            int to = nextInt() - 1;
            cnt[from]++;
            cnt[to]++;
        }
        long ans = 0;
        boolean bad = false;
        for(int i = 0;i < n;i++) {
            if (cnt[i] == 1) ans++;
            if (cnt[i] == 2) bad = true;
        }
        ans = (ans - 1) * ans / 2;
        if (ans >= n - 1 && !bad) pw.print("YES");
        else pw.print("NO");
        pw.close();
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw = new PrintWriter(System.out);

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