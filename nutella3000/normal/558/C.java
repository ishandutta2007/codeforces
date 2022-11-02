import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        int id[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            for(int j = 0;j < 20;j++) {
                if (a[i] >= (1 << j)) id[i] = j;
            }
        }

        int ans = 0;

        boolean updated[] = new boolean[n];
        for(int i = 0;i < 20;i++) {
            boolean one = false;
            boolean two = false;
            for(int j = 0;j < n;j++) {
                if (!updated[j] && id[j] >= 0 && (a[j] & (1 << id[j])) != 0) one = true;
                else two = true;
            }

            if (one && two) {
                for(int j = 0;j < n;j++) {
                    if (id[j] >= 0 && !updated[j] && (a[j] & (1 << id[j])) != 0) {
                        ans += (id[j] + 1);
                        updated[j] = true;
                        a[j] >>= (id[j] + 1);
                    }
                }
            }

            for(int j = 0;j  < n;j++) id[j]--;
        }

        int cnt[] = new int [20];
        for(int i = 0;i <n;i++) {
            for(int j = 1;j < 20;j++) {
                if (a[i] < (1 << (j - 1))) {
                    cnt[j - 1]++;
                    break;
                }
            }
        }

        int num = n;
        int sum = 0;
        for(int i = 0;i < 20;i++) sum += cnt[i] * i;

        int min = sum;

        for(int i = 0;i < 20;i++) {
            num -= cnt[i];
            sum -= num;
            sum += n - num;
            min = Math.min(min, sum);
        }

        pw.println(min + ans);
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}