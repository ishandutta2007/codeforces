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
        int m = sc.nextInt();
        int temp[] = new int[n];
        for(int i = 0;i < n;i++) temp[i] = sc.nextInt();
        segment_tree a = new segment_tree(temp);

        for(int i = 0;i < m;i++) {
            int t = sc.nextInt();
            if (t == 1) {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                pw.println(a.get(l, r));
            }
            if (t == 2) {
                int l = sc.nextInt() - 1;
                int r = sc.nextInt() - 1;
                int x = sc.nextInt();
                a.mod(l, r, x);
            }
            if (t == 3) {
                int l = sc.nextInt() - 1;
                int x = sc.nextInt();
                a.set(l, x);
            }
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

class segment_tree {
    int max[];
    long sum[];
    int last;

    segment_tree(int a[]) {
        int n = a.length;
        last = n - 1;
        max = new int [4 * n];
        sum = new long [4 * n];
        build(0, 0, last, a);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            max[v] = a[l];
            sum[v] = a[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);

        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    void set(int k, int x) {
        set(0, 0, last, k, x);
    }

    void set(int v, int l, int r, int k, int x) {
        if (l > k || r < k) return;
        if (l == k && r == k) {
            sum[v] = x;
            max[v] = x;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, k, x);
        set(v * 2 + 2, m + 1, r, k, x);

        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
    }

    long get(int l, int r) {
        return get(0, 0, last, l, r);
    }

    long get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return 0;
        if (l >= left && r <= right) return sum[v];
        int m = ((l + r) >> 1);
        return get(v * 2 + 1, l, m, left, right) + get(v * 2 + 2, m +  1, r, left, right);
    }

    void mod(int l, int r, int x) {
        mod(0, 0, last, l, r, x);
    }

    void mod(int v, int l, int r, int left, int right, int x) {
        if (l > right || r < left) return;
        if (max[v] < x) return;
        if (l == r) {
            sum[v] %= x;
            max[v] %= x;
            return;
        }
        int m = ((l + r) >> 1);
        mod(v * 2 + 1, l, m, left, right, x);
        mod(v * 2 + 2, m + 1, r, left, right, x);

        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
        sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];

    }


}