import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int a[] = new int [n];
        ArrayList<Integer> p[] = new ArrayList[n];
        ArrayList<Integer> c[] = new ArrayList[n];
        for(int i = 0;i < n;i++) {
            p[i] = new ArrayList<>();
            c[i] = new ArrayList<>();
        }

        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            int v = a[i];
            for(int j = 2;j <= Math.sqrt(v);j++) {
                int cnt = 0;
                while(v % j == 0) {
                    v /= j;
                    cnt++;
                    a[i] /= j;
                }
                cnt %= k;
                if (cnt != 0) {
                    p[i].add(j);
                    c[i].add(cnt);
                    for(int q = 0;q < cnt;q++) a[i] *= j;
                }
            }

            if (v != 1) {
                p[i].add(v);
                c[i].add(1);
            }
        }

        int b[] = new int [(int)1e5 + 1];
        int pair[] = new int [(int) 1e5 + 1];
        for(int i = 0;i < (int) 1e5 + 1;i++) pair[i] = -1;
        for(int i = 0;i < n;i++) {
            long v = 1;
            for(int j = 0;j < p[i].size();j++) {
                for(int q = 0;q < k - c[i].get(j);q++) {
                    v *= p[i].get(j);
                    if (v > 1e5) break;
                }
                if (v > 1e5) break;
            }
            if (v <= 1e5) pair[a[i]] = (int) v;
        }

        for(int i = 0;i < n;i++) b[a[i]]++;
        long ans = 0;

        for(int i = 0;i <= (int) 1e5;i++) {
            if (pair[i] != -1) {
                ans += (long)b[pair[i]] * b[i];
                if (pair[i] == i) {
                    ans -= b[i];
                }
            }
        }

        ans /= 2;
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

}