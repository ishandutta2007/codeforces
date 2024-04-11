import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        sc = new Fast_Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int b[] = new int [n];
        long sum[] = new long[1000000];


        for(int i = 0;i < n;i++) {
            int v = sc.nextInt();
            sum[v - i + 200000] += v;
        }

        long max = -1;
        for(int i = 0;i < sum.length;i++) max = Math.max(max, sum[i]);

        pw.println(max);

        pw.close();
    }


    static Fast_Scanner sc;
    static PrintWriter pw;

    static class Fast_Scanner {
        static BufferedReader br;
        static StringTokenizer st = new StringTokenizer("");

        Fast_Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Fast_Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        Double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }


}