
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        long st[] = new long[40];
        st[0] = 1;
        for(int i = 1;i < 40;i++) st[i] = st[i - 1] * 3;

        for(int q = sc.nextInt();q > 0;q--) {
            long n = sc.nextLong();
            long ans = 0;
            int id = 0;
            long sum = 0;
            for(int i = 0;i < 40;i++) {
                sum += st[i];
                if (n <= sum) {
                    id = i;
                    break;
                }
            }
            long pref[] = new long [40];
            pref[0] = 1;
            for(int i = 1;i < 40;i++) pref[i] = pref[i - 1] + st[i];

            for(int i = id;i >= 0;i--) {
                if (i != 0 && ans + pref[i - 1] >= n) continue;
                if (ans >= n) continue;
                ans += st[i];
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