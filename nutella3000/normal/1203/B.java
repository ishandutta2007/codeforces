import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int cnt[] = new int [10001];
            for(int i = 0;i < 4 * n;i++) cnt[sc.nextInt()]++;
            boolean bad = false;
            long sq = -1;
            int id2 = 10000;
            for(int id1 = 0;id1 <= 10000;id1++) {
                while(id2 >= 0 && cnt[id2] <= 0) id2--;
                if (cnt[id1] <= 0) continue;
                if (cnt[id1] == 1) bad = true;
                if (cnt[id2] == 1) bad = true;
                if (sq == -1) sq = id1 * id2;
                if (sq != id1 * id2) bad = true;
                cnt[id1]-= 2;
                cnt[id2] -= 2;

                id1--;
            }

            if (bad) pw.println("NO");
            else pw.println("YES");
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