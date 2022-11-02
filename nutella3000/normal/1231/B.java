import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int k = sc.nextInt();
        char h[] = sc.next().toCharArray();

        if (n == 1 && h[0] != '0' && k >= 1) {
            h[0] = '0';
        }else if (n != 1 && h[0] != '1' && k >= 1) {
            h[0] = '1';
            k--;
        }

        for(int i = 1;i < n;i++) {
            if (k == 0) break;
            if (h[i] != '0') {
                h[i] = '0';
                k--;
            }
        }

        pw.println(h);
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