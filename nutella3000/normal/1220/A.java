import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        char h[] = sc.next().toCharArray();
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0;i < h.length;i++) {
            if (h[i] == 'z') cnt0++;
            if (h[i] == 'n') cnt1++;
        }

        for(int i = 0;i < cnt1;i++) pw.print(1 + " ");
        for(int i = 0;i < cnt0;i++) pw.print(0 + " ");
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