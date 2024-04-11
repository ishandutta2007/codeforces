import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char h[] = sc.next().toCharArray();
        int cnt = 0;
        char ans[] = new char[h.length];
        for(int i = h.length - 1;i >= 0;i--) {
            if (h[i] == '0') cnt++;
            else cnt--;
            if (cnt < 0 || h[i] == '0') {
                ans[i] = '0';
                if (cnt < 0) cnt = 0;
            }
            else ans[i] = '1';
        }

        for(char i : ans) pw.print(i);
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

class triple {
    int a, b, x;
    triple(int a, int b, int x) {
        this.a = a;
        this.b = b;
        this.x = x;
    }

    triple() {}
}