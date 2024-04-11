import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    static boolean pos(int cnt1, int num1, int cnt2, int num2) {
        int q = num1 - num2;
        q += (cnt1 - cnt2) / 2 * 9;
        return q > 0;
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);

        int n = sc.nextInt();
        char h[] = sc.next().toCharArray();

        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 0;
        for(int i = 0;i < n / 2;i++) {
            if (h[i] == '?') cnt1++;
            else num1 += h[i] - '0';
        }
        for(int i = n / 2;i < n;i++) {
            if (h[i] == '?') cnt2++;
            else num2 += h[i] - '0';
        }

        if (pos(cnt1, num1, cnt2, num2) || pos(cnt2, num2, cnt1, num1)) pw.println("Monocarp");
        else pw.println("Bicarp");
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

class edge {
    int to, id;
    edge(int to, int id) {
        this.to = to;
        this.id = id;
    }

    edge() {}
}