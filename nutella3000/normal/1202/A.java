import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            char a[] = sc.next().toCharArray();
            char b[] = sc.next().toCharArray();
            int k = 0;
            int id = 0;
            for(int i = 0;i < b.length;i++) {
                if (b[i] == '1') id = b.length - i - 1;
            }

            for(int i = a.length - 1;i >= 0;i--) {
                if (a[i - id] == '1') {
                    k = a.length - i - 1;
                    break;
                }
            }
            pw.println(k);
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