import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, a[];
    static ArrayList<Integer> gr[];

    static void scan(int a[]) throws IOException {
        for(int i = 0;i < a.length;i++) a[i] = sc.nextInt();
    }

    static void create(ArrayList<Integer> a[]) {
        for(int i = 0;i < a.length;i++) a[i] = new ArrayList<>();
    }

    static int max(int a[]) {
        int ans = Integer.MIN_VALUE;
        for(int i = 0;i < a.length;i++) ans = Math.max(ans, a[i]);
        return ans;
    }

    static int min(int a[]) {
        int ans = Integer.MAX_VALUE;
        for(int i = 0;i < a.length;i++) ans = Math.min(ans, a[i]);
        return ans;
    }

    static int cnt(int a[], int num) {
        int ans = 0;
        for(int i = 0;i < a.length;i++) if (a[i] == num) ans++;
        return ans;
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        a = new int [n];
        scan(a);
        gr = new ArrayList[n];
        create(gr);
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        scan();
        int max = max(a);
        int cnt1 = cnt(a, max);
        int cnt2 = cnt(a, max - 1);
        int ans = max + 2;

        for(int i = 0;i < n;i++) {
            int v1 = cnt1;
            int v2 = cnt2;
            if (a[i] == max) v1--;
            if (a[i] == max - 1) v2--;
            int next = max;
            for(int to : gr[i]) {
                if (a[to] == max) {
                    v1--;
                    next = max + 1;
                }
                if (a[to] == max - 1) v2--;
            }
            if (v2 > 0) next = max + 1;
            if (v1 > 0) next = max + 2;
            ans = Math.min(ans, next);
        }

        pw.println(ans);
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;
    static class Scanner {
        BufferedReader br ;
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