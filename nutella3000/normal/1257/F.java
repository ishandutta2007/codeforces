import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        TreeMap<int[], Integer> a = new TreeMap<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                for(int i = 0;i < o1.length;i++) {
                    if (o1[i] < o2[i]) return -1;
                    if (o1[i] > o2[i]) return 1;
                }
                return 0;
            }
        });

        int n = sc.nextInt();
        int b[] = new int [n];
        for(int i = 0;i < n;i++) b[i] = sc.nextInt();


        for(int x = 0;x < (1 << 15);x++) {
            int d[] = new int [n];
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < 15;j++) {
                    int num = ((1 << j) & b[i]);
                    if (num > 0) num = 1;
                    if (((1 << j) & x) != 0) num = 1 - num;
                    d[i] += num;
                }
            }
            int min = inf;
            for(int i = 0;i < n;i++) min = Math.min(min, d[i]);
            for(int i = 0;i < n;i++) d[i] -= min;
            if (!a.containsKey(d)) a.put(d, x);
        }

        for(int i = 0;i < n;i++) b[i] >>= 15;

        for(int x = 0;x < (1 << 15);x++) {
            int d[] = new int [n];
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < 15;j++) {
                    int num = ((1 << j) & b[i]);
                    if (num > 0) num = 1;
                    if (((1 << j) & x) != 0) num = 1 - num;
                    d[i] += num;
                }
            }
            int min = inf;
            for(int i = 0;i < n;i++) min = Math.min(min, d[i]);
            for(int i = 0;i < n;i++) d[i] -= min;
            int rev_d[] = new int[n];
            int max = 0;
            for(int i = 0;i < n;i++) max = Math.max(max, d[i]);
            for(int i = 0;i < n;i++) rev_d[i] = max - d[i];
            if (a.containsKey(rev_d)) {
                System.out.println((x << 15) + a.get(rev_d));
                return;
            }
        }
        pw.println(-1);
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