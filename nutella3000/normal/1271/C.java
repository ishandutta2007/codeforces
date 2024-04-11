import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int xr[] = new int[] {-1, 1, 0, 0};
    static int yr[] = new int[] {0, 0, -1, 1};
    static pair school;

    static int f(pair a, pair s) {
        if (dist(a, school) != dist(a, s) + dist(s, school)) return 0;
        return 1;
    }

    static int dist(pair a, pair b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        school = new pair(sc.nextInt(), sc.nextInt());

        int ans1 = -1;
        pair ans = new pair(0, 0);

        pair a[] = new pair[n];

        for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), sc.nextInt());

        for(int i = 0;i < 4;i++) {
            pair c = new pair(xr[i] + school.x, yr[i] + school.y);
            int cnt = 0;
            for(int j = 0;j < n;j++) {
                cnt += f(a[j], c);
            }

            if (cnt > ans1) {
                ans1 = cnt;
                ans = c;
            }
        }

        pw.println(ans1);
        pw.println(ans.x + " " + ans.y);

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
}