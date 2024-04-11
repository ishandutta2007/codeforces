import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int a[] = new int [n];
        int pref[] = new int [n + 1];
        pref[0] = 1;
        for(int i = 0;i < n;i++) {
            a[i] = sc.nextInt();
            pref[i + 1] = pref[i];
            if (a[i] < 0) pref[i + 1] *= -1;
        }

        long ans1 = 0;
        long cnt1 = 0, cnt2 = 0;
        for(int i = 0;i <= n;i++) {
            if (pref[i] == 1) {
                ans1 += cnt1;
                cnt1++;
            }else{
                ans1 += cnt2;
                cnt2++;
            }
        }

        pw.println(((long)n * (n + 1) / 2 - ans1) + " " + ans1);

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