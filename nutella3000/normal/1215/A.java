import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int a1 = sc.nextInt();
        int a2 = sc.nextInt();
        int k1 = sc.nextInt();
        int k2 = sc.nextInt();
        int n = sc.nextInt();
        int min_ans = Math.max(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2));

        if (k1 > k2) {
            int t = a1;
            a1 = a2;
            a2 = t;
            t = k1;
            k1 = k2;
            k2 = t;
        }
        int q = Math.min(a1, n / k1);
        int max_ans = q + Math.min(a2, (n - q * k1) / k2);

        pw.println(min_ans + " " + max_ans);
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