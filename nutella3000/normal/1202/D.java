import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            long n = sc.nextInt();
            pw.print(1);
            ArrayList<Long> c = new ArrayList<>();
            while(n != 0) {
                long cnt = 0;
                while((cnt + 1) * cnt / 2 <= n) {
                    cnt++;
                    //pw.print(3);
                }
                n -= cnt * (cnt - 1) / 2;
                c.add(cnt);
            }
            long this_c = 0;
            while(!c.isEmpty()) {
                for(long i = this_c;i < c.get(c.size() - 1);i++) pw.print(3);
                pw.print(7);
                this_c = c.get(c.size() - 1);
                c.remove(c.size() - 1);
            }
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