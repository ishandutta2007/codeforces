import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        boolean gr[][] = new boolean[n][n];
        for(int i = 0;i < n;i++) {
            String s = next();
            for(int j = 0;j < n;j++) {
                if (s.charAt(j) == '1') gr[i][j] = true;
                else gr[i][j] = false;
            }
        }

        int dist[][] = new int [n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if (i == j) {
                    dist[i][j] = 0;
                }else if (gr[i][j]) dist[i][j] = 1;
                else dist[i][j] = inf;
            }
        }
        for(int k = 0;k < n;k++) {
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int m = nextInt();
        ArrayList<Integer> ans = new ArrayList<>();
        int a[] = new int [m];
        for(int i = 0;i < m;i++) a[i] = nextInt() - 1;
        ans.add(a[0]);
        int last = a[0];
        int id = 0;
        for(int i = 1;i <= m;i++) {
            if (i == m || dist[last][a[i]] < i - id) {
                id = i - 1;
                last = a[i - 1];
                ans.add(a[i - 1]);
            }
        }
        pw.println(ans.size());
        for(int i : ans) pw.print((i + 1) + " ");
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