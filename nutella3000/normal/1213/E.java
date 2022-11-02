import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static char a[], b[];

    static boolean check(char res[]) {
        for(int i = 0;i < res.length - 1;i++) {
            if (res[i] == a[0] && res[i + 1] == a[1]) return false;
            if (res[i] == b[0] && res[i + 1] == b[1]) return false;
        }
        return true;
    }

    static void solve() throws IOException {
        int n = sc.nextInt();
        a = sc.next().toCharArray();
        b = sc.next().toCharArray();

        char one[][] = new char[6][3 * n];
        char two[][] = new char[6][3 * n];

        int p[][] = new int [6][3];
        p[0][0] = 0; p[0][1] = 1; p[0][2] = 2;
        p[1][0] = 0; p[1][1] = 2; p[1][2] = 1;
        p[2][0] = 1; p[2][1] = 0; p[2][2] = 2;
        p[3][0] = 1; p[3][1] = 2; p[3][2] = 0;
        p[4][0] = 2; p[4][1] = 0; p[4][2] = 1;
        p[5][0] = 2; p[5][1] = 1; p[5][2] = 0;

        for(int i = 0;i < 3 * n;i++) {
            for(int j = 0;j < 6;j++) {
                one[j][i] = (char) ('a' + p[j][i / n]);

                two[j][i] = (char) ('a' + p[j][i % 3]);
            }
        }

        pw.println("YES");

        for(int i = 0;i < 6;i++) {
            if (check(one[i])) {
                pw.println(one[i]);
                return;
            }
            if (check(two[i])) {
                pw.println(two[i]);
                return;
            }
        }
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