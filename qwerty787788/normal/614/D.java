import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int n = in.nextInt();
        int maxLevel = in.nextInt();
        int cf = in.nextInt();
        int cm = in.nextInt();
        long money = in.nextLong();
        final int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        Arrays.sort(order, new Comparator<Integer>() {
            public int compare(Integer x, Integer y) {
                return Integer.compare(a[x], a[y]);
            }
        });
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = a[order[i]];
            if (i > 0) {
                b[i] += b[i - 1];
            }
        }
        long sumForMax = 0;
        long answer = -1;
        int when = -1;
        long bestMin = -1;
        for (int max = 0; max <= n; max++) {
            long leftMoney = money - ((long) max * maxLevel - sumForMax);
            if (leftMoney < 0) {
                break;
            }
            if (max == n) {
                long cur = (long) n * cf + (long) maxLevel * cm;
                if (cur > answer) {
                    answer = cur;
                    when = n;
                    bestMin = maxLevel; 
                }
                break;
            }
            long l = -1;
            long r = maxLevel;
            while (l < r - 1) {
                long mid = (l + r) >>> 1;
                int left = -1;
                int right = n - max;
                while (left < right - 1) {
                    int middle = (left + right) >>> 1;
                    if (a[order[middle]] < mid) {
                        left = middle;
                    } else {
                        right = middle;
                    }
                }
                long sum = left < 0 ? 0 : b[left];
                long needSum = mid * right - sum;
                if (needSum > leftMoney) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            long cur = (long) cf * max + (long) cm * l;
            if (cur > answer) {
                answer = cur;
                when = max;
                bestMin = l;
            }
            sumForMax += a[order[n - max - 1]];
        }
        out.println(answer);
        int[] c = a.clone();
        for (int i = 0; i < when; i++) {
            c[order[n - i - 1]] = maxLevel;
        }
        for (int i = 0; i < n; i++) {
            if (c[i] < bestMin) {
                c[i] = (int) bestMin;
            }
        } 
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(c[i]);
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new D().run();
    }
}