import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static pair mask[] = new pair[(1 << 21)];
    static int n, a[];

    static void add(int x, int id) {
        if (mask[x].y < id) {
            mask[x].x = mask[x].y;
            mask[x].y = id;
        }else if (mask[x].x < id) {
            if (id == mask[x].y) return;
            mask[x].x = id;
        }
    }

    static void merge(int mask1, int mask2) {
        add(mask1, mask[mask2].x);
        add(mask1, mask[mask2].y);
    }


    static void scan() throws IOException {
        for(int i = 0;i < (1 << 21);i++) mask[i] = new pair(-1, -1);
        n = sc.nextInt();
        a = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = sc.nextInt();
            add(a[i], i);
        }

        for(int i = (1 << 21) - 1;i >= 0;i--) {
            if (i == 15) {
                n++;
                n--;
            }
            for(int j = 0;j <= 20;j++) {
                if (((1 << j) & i) == 0) {
                    merge(i, i + (1 << j));
                }
            }
        }
    }

    static void solve() throws IOException {
        scan();
        int ans = 0;
        for(int i = 0;i < n - 2;i++) {
            int new_ans = a[i];
            int ms = 0;
            for(int j = 20; j >= 0;j--) {
                if (((1 << j) & new_ans) != 0) continue;
                if (mask[ms + (1 << j)].x > i) ms += (1 << j);
            }

            ans = Math.max(ans, new_ans + ms);
        }

        pw.println(ans);
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