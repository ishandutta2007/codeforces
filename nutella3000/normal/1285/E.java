import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int q = sc.nextInt();q > 0;q--) {
            int n = sc.nextInt();
            line a[] = new line[n];
            for(int i  =0;i < n;i++) {
                a[i] = new line(sc.nextInt(), sc.nextInt());
            }

            Arrays.sort(a, new Comparator<line>() {
                @Override
                public int compare(line o1, line o2) {
                    return Integer.compare(o1.l, o2.l);
                }
            });

            int max_r = -inf;
            int id = -1;
            int max2_r = -inf;
            int cnt[] = new int [n];
            int ans = 0;
            int cnt_in_per = 0;
            for(int i = 0;i < n;i++) {
                cnt_in_per++;
                if (a[i].l > max2_r && a[i].l <= max_r && max2_r != -inf) {
                    cnt[id]++;
                }
                if (a[i].l > max_r && max_r != -inf) {
                    if (cnt_in_per == 2) cnt[i - 1]--;
                    ans++;
                    max2_r = -inf;
                    max_r = a[i].r;
                    id = i;
                    cnt_in_per = 1;
                    continue;
                }

                if (max_r < a[i].r) {
                    max2_r = max_r;
                    max_r = a[i].r;
                    id = i;
                }else if (max2_r < a[i].r) {
                    max2_r = a[i].r;
                }
            }
            if (cnt_in_per == 1) cnt[n - 1]--;

            int max = -inf;
            for(int i = 0;i < n;i++) max = Math.max(cnt[i], max);
            pw.println(max + ans + 1);
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

/*
class segment_tree {
    int cnt[], last;
    int push[];
    segment_tree(int n) {
        cnt = new int [4 * n];
        push = new int [4 * n];
        last = n - 1;
    }

    void build(int v, int l, int r) {
        if (l == r) {
            cnt[v] = 1;
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, );
    }

    void push(int v) {
        push[v * 2 + 1] += push[v];
        push[v * 2 + 2] += push[v];
        cnt[v * 2 + 1] += push[v];
        cnt[v * 2 + 2] += push[v];
        push[v] = 0;
    }

    void set(int l, int r) {
        set(0, 0, last, l, r);
    }

    void set(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            min[v]++;
            push[v]++;
            return;
        }
        push(v);
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, left, right);
        set(v * 2 + 2, m + 1, r, left, right);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    int get(int id) {
        return get(0, 0, last, id);
    }

    int get(int v, int l, int r, int id) {
        if (l > id || r < id) return -1;
        if (l == id && r == id) return min[id];
        push(v);
        int m = ((l + r) >> 1);
        int ans = get(v * 2 + 1, l, m, id);
        if (ans == -1) ans = get(v * 2 + 2, m + 1, r, id);
        return ans;
    }
}*/

class line {
    int l, r;
    line(int l, int r) {
        this.l = l;
        this.r = r;
    }

    line() {}
}