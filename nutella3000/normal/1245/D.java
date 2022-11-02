import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, x[], y[], c[], k[], id[];
    static boolean used[];

    static void scan() throws IOException {
        n = sc.nextInt();
        x = new int [n];
        y = new int [n];
        c = new int [n];
        k = new int [n];
        id = new int [n];
        used = new boolean[n];
        for(int i = 0;i < n;i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            id[i] = -1;
        }
        for(int i = 0;i < n;i++) c[i] = sc.nextInt();
        for(int i = 0;i < n;i++) k[i] = sc.nextInt();

    }

    static long dist(int o1, int o2) {
        return (long)(k[o1] + k[o2]) * (Math.abs(x[o1] - x[o2]) + Math.abs(y[o1] - y[o2]));
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        scan();
        long sum = 0;
        for(int i = 0;i < n;i++) {
            int min = inf;
            int min_id = -1;
            for(int j = 0;j < n;j++) {
                if (!used[j] && c[j] < min) {
                    min = c[j];
                    min_id = j;
                }
            }
            sum += c[min_id];
            used[min_id] = true;
            for(int j = 0;j < n;j++) {
                if (!used[j] && dist(min_id, j) < c[j]) {
                    c[j] = (int)dist(min_id, j);
                    id[j] = min_id;
                }
            }
        }

        pw.println(sum);
        int cnt = 0;
        for(int i = 0;i < n;i++) if (id[i] == -1) cnt++;
        pw.println(cnt);
        for(int i = 0;i < n;i++) if (id[i] == -1) pw.print(i + 1 + " ");
        pw.println();
        pw.println(n - cnt);
        for(int i = 0;i < n;i++) {
            if (id[i] != -1) {
                pw.println(i + 1 + " " + (id[i] + 1));
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


class city implements Comparator<city>{
    int x, y, c, k, id;

    city() {}

    @Override
    public int compare(city o1, city o2) {
        return Integer.compare(o1.c, o2.c);
    }
}