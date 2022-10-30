import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[][] = new int [n][m];
        ArrayList<Integer> ans1 = new ArrayList<>();
        ArrayList<Integer> ans2 = new ArrayList<>();
        int b[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) a[i][j] = nextInt();
        }
        for(int i = 0;i < n - 1;i++) {
            for(int j = 0;j < m  - 1;j++) {
                if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1 && a[i][j + 1] == 1) {
                    ans1.add(i + 1);
                    ans2.add(j + 1);
                    b[i][j] = 1;
                    b[i + 1][j] = 1;
                    b[i][j + 1] = 1;
                    b[i + 1][j + 1] = 1;
                }
            }
        }
        boolean bad = false;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if (a[i][j] != b[i][j]) bad = true;
            }
        }
        if (bad) pw.println(-1);
        else{
            pw.println(ans1.size());
            for(int i = 0;i < ans1.size();i++) {
                pw.println(ans1.get(i) + " " + ans2.get(i));
            }
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