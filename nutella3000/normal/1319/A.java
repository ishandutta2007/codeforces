import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        sc = new Fast_Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int r[] = new int [n];
        int b[] = new int [n];
        for(int i = 0;i < n;i++) r[i] = sc.nextInt();
        for(int i = 0;i < n;i++) b[i] = sc.nextInt();
        int left = 0;
         int right = 1000000;
        while(right - left > 1) {
            int mid = ((left + right) >> 1);
            int sum = 0;
            for(int i = 0;i < n;i++) {
                if (r[i] == 1 && b[i] == 1);
                else if (r[i] == 1) sum += mid;
                else if (b[i] == 1) sum--;
            }
            if (sum > 0) right = mid;
            else left = mid;

        }
        if (right >= 1000000) pw.println(-1);
        else pw.println(right);
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