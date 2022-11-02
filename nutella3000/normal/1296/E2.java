import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        char h[] = sc.next().toCharArray();
        int ans[] = new int [n];
        int cnt = 0;
        for(int col = 1;col <= 26;col++) {
            char last = 'a';
            for (int i = 0; i < n; i++) {
                if (ans[i] != 0) continue;
                if (h[i] >= last) {
                    last = h[i];
                    ans[i] = col;
                    cnt = col;
                }
            }
        }

        pw.println(cnt);
        for(int i = 0;i < n;i++) pw.print(ans[i] + " ");

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