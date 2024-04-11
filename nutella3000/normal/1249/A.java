
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
            int a[] = new int[n];
            for(int i = 0;i < n;i++) a[i] = sc.nextInt();
            Arrays.sort(a);
            int ans = 1;
            for(int i = 1;i < n;i++) {
                if (a[i] == a[i - 1] + 1) ans = 2;
            }
            pw.println(ans);
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