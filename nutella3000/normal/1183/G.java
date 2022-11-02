import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = nextInt();
        while (t-- > 0) {
            int n = nextInt();
            sweet a[] = new sweet[n];
            for (int i = 0; i < n; i++) a[i] = new sweet();
            for (int i = 0; i < n; i++) {
                int num = nextInt() - 1;
                int bad = nextInt();
                if (bad == 1) a[num].a++;
                else a[num].b++;
            }
            Arrays.sort(a, new sweet());
            ArrayList<Integer> id = new ArrayList<>();
            int ans1 = 0;
            for (int i = 0; i < n; i++) {
                if (a[i].a + a[i].b > id.size()) {
                    id.add(i);
                }
            }
            int cnt[] = new int[id.size()];
            int last = inf;
            for (int i = id.size() - 1; i >= 0; i--) {
                int k = a[id.get(i)].a + a[id.get(i)].b;
                cnt[i] = Math.min(k, last - 1);
                ans1 += cnt[i];
                last = cnt[i];
            }
            TreeMap<Integer, Integer> bad_cnt = new TreeMap<>();
            int ans2 = 0;
            int cnt_sz = id.size() - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (i == 0) {
                    if (!bad_cnt.containsKey(a[i].a)) bad_cnt.put(a[i].a, 0);
                    bad_cnt.put(a[i].a, bad_cnt.get(a[i].a) + 1);
                }
                while (cnt_sz >= 0 && (cnt[cnt_sz] > a[i].a + a[i].b || i == 0)) {
                    ans2 += Math.min(bad_cnt.lastKey(), cnt[cnt_sz]);
                    bad_cnt.put(bad_cnt.lastKey(), bad_cnt.lastEntry().getValue() - 1);
                    if (bad_cnt.lastEntry().getValue() == 0) bad_cnt.pollLastEntry();
                    cnt_sz--;
                }
                if (!bad_cnt.containsKey(a[i].a)) bad_cnt.put(a[i].a, 0);
                bad_cnt.put(a[i].a, bad_cnt.get(a[i].a) + 1);
            }
            pw.println(ans1 + " " + ans2);
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}

class sweet implements Comparator<sweet> {
    int a, b;

    sweet(int a, int b) {
        this.a = a;
        this.b = b;
    }

    sweet() {
    }

    @Override
    public int compare(sweet o1, sweet o2) {
        return Integer.compare(o1.a + o1.b, o2.a + o2.b);
    }
}