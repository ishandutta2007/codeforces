import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        long a[] = new long [n];
        sale b[] = new sale[m];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        for(int i = 0;i < m;i++) b[i] = new sale(nextInt(), nextInt() - 1);
        Arrays.sort(b, new sale());
        long l = 0;
        long r = 100000000000l;
        long a_[] = new long [n];
        for(int i = 0;i < n;i++) a_[i] = a[i];
        while(l != r - 1) {
            long mid = (l + r) / 2;
            long cnt1 = mid;
            long cnt2 = 0;
            int id = m - 1;
            while(id >= 0 && b[id].d > mid) {
                id--;
            }
            while(id >= 0) {
                if (cnt1 > b[id].d) {
                    cnt2 += cnt1 - b[id].d;
                    cnt1 = b[id].d;
                }
                long u = Math.min(a[b[id].t], cnt1);
                a[b[id].t] -= u;
                cnt1 -= u;
                id--;
            }
            cnt2 += cnt1;
            boolean can = true;
            for(int i = 0;i < n;i++) {
                if (a[i] * 2 > cnt2) can = false;
                cnt2 -= a[i] * 2;
                a[i] = 0;
            }
            for(int i = 0;i < n;i++) a[i] = a_[i];
            if (can) r = mid;
            else l = mid;
        }
        pw.print(r);
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
class sale implements Comparator<sale>{
    long d; int t;
    sale(long d, int t) {
        this.d = d;
        this.t = t;
    }
    sale() {}

    @Override
    public int compare(sale o1, sale o2) {
        return Long.compare(o1.d, o2.d);
    }
}