import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int a[] = new int [4];
        for(int i = 0;i < 4;i++) a[i] = sc.nextInt();
        Arrays.sort(a);

        boolean good = false;
        if (a[0] + a[2] == a[1] + a[3]) good = true;
        if (a[0] + a[3] == a[1] + a[2]) good = true;
        if (a[0] + a[1] + a[2] == a[3]) good = true;
        pw.println(good ? "YES" : "NO");
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