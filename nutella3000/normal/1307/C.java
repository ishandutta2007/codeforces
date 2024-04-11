import java.io.*;
import java.util.*;


public class Main {
    static long inf = (long) (1e11);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char h[] = sc.next().toCharArray();
        int cnt1[] = new int [26];
        for(int i = 0;i < h.length;i++) {
            cnt1[h[i] - 'a']++;
        }

        long cnt2[][] = new long [26][26];
        for(int i = 0;i < 26;i++) {
            for(int j = 0;j < 26;j++) {
                int q = cnt1[j];
                for(int w = 0;w < h.length;w++) {
                    if (h[w] == ('a' + j)) q--;
                    if (h[w] == ('a' + i))  cnt2[i][j] += q;
                }
            }
        }

        long ans = 0;
        for(int i = 0;i < 26;i++) {
            ans = Math.max(cnt1[i], ans);
            for(int j = 0;j < 26;j++) ans = Math.max(ans, cnt2[i][j]);
        }

        pw.println(ans);

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