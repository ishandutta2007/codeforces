import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m, a[][];
    static ArrayList<Integer> used;
    static int num[];
    static int ans;

    static void rec(int id) {
        if (id == used.size()) {
            check();
            return;
        }

        for(int i = 0;i < n;i++) {
            num[id] = i;
            rec(id + 1);
        }
    }

    static void check() {
        int new_ans = 0;
        for(int i = 0;i < n;i++) {
            int max = 0;
            for(int j = 0;j < used.size();j++) {
                max = Math.max(max, a[(i + num[j]) % n][used.get(j)]);
            }
            new_ans += max;
        }
        ans = Math.max(ans, new_ans);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int test = nextInt();
        while(test-- > 0) {
            n = nextInt();
            m = nextInt();
            a = new int [n][m];
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) a[i][j] = nextInt();
            }
            used = new ArrayList<>();
            num = new int [n * m];
            ans = 0;

            pair b[] = new pair[n * m];

            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    b[i * m + j] = new pair(a[i][j], j);
                }
            }

            Arrays.sort(b, new pair());

            for(int i = b.length - 1;i >= Math.max(0, b.length - 5);i--) {
                int v = b[i].y;

                boolean bad = false;

                for(int j = 0;j < used.size();j++) if (used.get(j) == v) bad = true;

                if (!bad) used.add(v);
            }

            rec(0);

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

class pair implements Comparator<pair>{
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}