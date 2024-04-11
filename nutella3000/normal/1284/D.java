import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9;
    static int n;

    static boolean solve(int f[][], int s[][]) {
        pair time[] = new pair[2 * n];

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 2;j++) {
                time[i * 2 + j] = new pair(f[i][j], i, j);
            }
        }
        Arrays.sort(time, new pair());

        boolean ans = true;

        TreeSet<Integer> max_l = new TreeSet<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return -Integer.compare(s[o1][0], s[o2][0]) * 2 + Integer.compare(o1, o2);
            }
        });

        TreeSet<Integer> min_r = new TreeSet<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(s[o1][1], s[o2][1]) * 2 + Integer.compare(o1, o2);
            }
        });

        for(int i = 0;i < 2 * n;i++) {
            int v = time[i].id;
            if (time[i].type == 1) {
                max_l.remove(v);
                min_r.remove(v);
            }else{
                max_l.add(v);
                min_r.add(v);

                int l = s[max_l.first()][0];
                int r = s[min_r.first()][1];
                if (r < l) ans = false;
            }
        }
        return ans;
        //if (ans) pw.println("YES");
        //else pw.println("NO");
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        n = sc.nextInt();
        int f[][] = new int [n][2];
        int s[][] = new int [n][2];
        for(int i = 0;i < n;i++) {
            f[i][0] = sc.nextInt();
            f[i][1] = sc.nextInt();
            s[i][0] = sc.nextInt();
            s[i][1] = sc.nextInt();
        }

        boolean ans = solve(f, s) && solve(s, f);
        pw.println(ans ? "YES" : "NO");
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
    int t, id, type;
    pair(int t, int id, int type) {
        this.t = t;
        this.id = id;
        this.type = type;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.t, o2.t) * 2 + Integer.compare(o1.type, o2.type);
    }
}