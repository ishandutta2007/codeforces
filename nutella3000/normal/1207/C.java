import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            int n = nextInt();
            long a = nextLong();
            long b = nextInt();
            long ans = a * n + b * (n + 1);
            char h[] = next().toCharArray();
            ArrayList<Integer> cnt = new ArrayList<>();
            int cnt_ = 1;
            for(int i = 1;i < n;i++) {
                if (h[i] != h[i - 1]) {
                    cnt.add(cnt_);
                    cnt_ = 1;
                }else cnt_++;
            }
            cnt.add(cnt_);
            int now = 1;
            int me = 0;
            cnt.remove(0);
            for(int u = 0;u < cnt.size();u++) {
                int i = cnt.get(u);
                if (u == cnt.size() - 1) {
                    ans += a;
                }else {

                    if (now == 1) {
                        if (me == 0) ans += b * (i + 1) + a;
                        else ans += b * (i + 1);
                        me = 1;
                    } else {
                        if (b * (i - 1) > 2 * a) {
                            me = 0;
                            ans += a;
                        }else ans += b * (i - 1);
                    }
                    now = 1 - now;
                }
            }
            pw.println(ans);
        }
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