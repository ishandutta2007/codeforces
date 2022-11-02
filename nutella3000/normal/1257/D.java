import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int ans = 0;
            int a[] = new int [n];
            for(int i = 0;i < n;i++) a[i] = sc.nextInt();

            int l = 0;
            int p[] = new int [n + 1];
            int m = sc.nextInt();
            for(int i = 0;i < m;i++) {
                int pow = sc.nextInt();
                int temp = sc.nextInt();
                p[temp] = Math.max(pow, p[temp]);
            }
            for(int i = n - 1;i >= 0;i--) p[i] = Math.max(p[i], p[i + 1]);
            int last_l = 0;
            boolean bad = false;
            while(l != n) {
                int left = -1;
                int right = n + 1;
                int max = 0;
                int num = 0;
                while(right - left > 1) {
                    int mid = ((left + right) / 2);
                    if (num >= mid) left = mid;
                    else{
                        if (max > p[mid]) right = mid;
                        else{
                            int new_max = 0;
                            while(l != n + 1 && num <= mid && new_max <= p[mid]) {
                                max = Math.max(max, new_max);
                                if (l != n) new_max = Math.max(new_max, a[l]);
                                l++;
                                num++;
                            }
                            num--;
                            l--;

                            if (num == mid) left = mid;
                            else right = mid;
                        }
                    }
                }
                ans++;
                if (last_l == l) {
                    bad = true;
                    break;
                }
                last_l = l;
            }

            if (bad) pw.println(-1);
            else pw.println(ans);
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