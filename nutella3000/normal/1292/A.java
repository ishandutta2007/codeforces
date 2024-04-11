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
        int q = sc.nextInt();
        boolean used[][] = new boolean[2][n + 1];
        int cnt_bad = 0;
        while(q-- > 0) {
            int id1 = sc.nextInt() - 1;
            int id2 = sc.nextInt() - 1;
            int mul = 1;
            if (used[id1][id2]) mul = -1;
            for(int id3 = Math.max(0, id2 - 1);id3 <= id2 + 1;id3++) {
                if (used[1 - id1][id3]) cnt_bad += mul;
            }

            used[id1][id2] = !used[id1][id2];

            if (cnt_bad == 0 && !used[1][n - 1]) pw.println("Yes");
            else pw.println("No");
        }
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