import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int max = (int) 4e5 + 2;

    static void solve() throws IOException {
        int temp = sc.nextInt();
        int k = sc.nextInt();
        int cnt[] = new int [max];
        for(int i = 0;i < temp;i++) cnt[sc.nextInt()]++;

        int pref[] = new int [max];
        for(int i = 1;i < max;i++) pref[i] = pref[i - 1] + cnt[i];

        int min = inf;

        for(int start = 1;start < max;start++) {
            int l = start;
            int r = start;
            int num = 0;
            int v_k = k;
            int new_ans = 0;
            while(v_k > 0 && r < max) {
                int q = Math.min(pref[r] - pref[l - 1], v_k);
                new_ans += num * q;
                v_k -= q;

                l = l * 2;
                r = r * 2 + 1;
                num++;
            }
            if (v_k == 0)
            min = Math.min(min, new_ans);
        }

        pw.println(min);
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
    int x, y;

    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pair() {
    }
}