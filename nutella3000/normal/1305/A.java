import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int t = sc.nextInt();
        for(int i = t;i > 0;i--) {
            int n = sc.nextInt();
            int a[] = new int [n];
            int b[] = new int [n];
            for(int j = 0;j < n;j++) a[j] = sc.nextInt();
            for(int j = 0;j < n;j++) b[j] = sc.nextInt();
            Arrays.sort(a);
            Arrays.sort(b);
            boolean bad = false;
            for(int j = 1;j < n;j++) if (b[j] + a[j] == a[j - 1] + b[j - 1]) bad = true;
            for(int j = 0;j < n;j++) pw.print(a[j] + " ");
            pw.println();
            for(int j = 0;j < n;j++) pw.print(b[j] + " ");
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

class pair {
    int a, t;
    pair(int a, int t) {
        this.a = a;
        this.t = t;
    }

    pair() {}

}