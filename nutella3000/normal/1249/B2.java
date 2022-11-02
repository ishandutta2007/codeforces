
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int q = sc.nextInt();
        while(q-- > 0) {
            int n = sc.nextInt();
            int p[] = new int [n];
            for(int i = 0;i < n;i++) p[i] = sc.nextInt() - 1;
            int ans[] = new int [n];
            for(int i = 0;i < n;i++) {
                if (ans[i] != 0) continue;
                int v = p[i];
                ans[i] = 1;
                while (v != i) {
                    v = p[v];
                    ans[i]++;
                }

                v = p[i];
                while(v != i) {
                    ans[v] = ans[i];
                    v = p[v];
                }
            }

            for(int i : ans) pw.print(i + " ");
            pw.println();
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

class pair implements Comparator<pair>{
    int m, p;
    pair(int x, int y) {
        m = x;
        p = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.m, o2.m) * 2 + Integer.compare(o1.p, o2.p);
    }
}