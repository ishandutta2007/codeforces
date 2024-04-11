import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt(); test > 0;test--) {
            int n = sc.nextInt();
            int mid = n / 2 - 1;
            int p[] = new int [n];
            for(int i = 0;i < n;i++) p[i] = sc.nextInt();
            int a[] = new int [3];

            int last = -1;
            int id = -1;
            for(int j = 0;j <= mid;j++) {
                if (last != p[j] && id <= 0) id++;
                else if (last != p[j] && id == 1 && a[1] > a[0]) id++;

                a[id]++;
                last = p[j];
            }


            int num = -inf;
            if (mid + 1 < n) num = p[mid + 1];

            for(int i = mid;i >= 0;i--) {
                if (p[i] != num) break;
                a[id]--;
            }


            if(a[2] == 0 || a[2] <= a[0]) pw.println("0 0 0");
            else pw.println(a[0] + " " + a[1] + " " + a[2]);

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