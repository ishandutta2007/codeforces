
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int k = sc.nextInt();
        line a[] = new line[n];
        for(int i = 0;i < n;i++) a[i] = new line(sc.nextInt(), sc.nextInt(), i);

        segment_tree b = new segment_tree(1200);
        Arrays.sort(a, new line());

        TreeSet<Integer> r = new TreeSet<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(a[o1].r, a[o2].r) * 2 + Integer.compare(a[o1].id, a[o2].id);
            }
        });

        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0;i <= n;i++) {
            int cnt = 0;
            while(i != n && (cnt == 0 || a[i].l == a[i - 1].l)) {
                cnt++;
                r.add(i);
                b.set(a[i].l, a[i].r, 1);
                i++;
            }
            if (i != n) i--;

            while (b.get() > k) {
                int id = r.pollLast();
                ans.add(a[id].id + 1);
                b.set(a[id].l, a[id].r, -1);
            }
        }

        pw.println(ans.size());
        for(int i : ans) pw.print(i + " ");
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

class line implements Comparator<line>{
    int l, r, id;
    line(int l, int r, int id) {
        this.l = l;
        this.r = r;
        this.id = id;
    }
    line() {}

    @Override
    public int compare(line o1, line o2) {
        return Integer.compare(o1.l, o2.l);
    }
}

class segment_tree {
    int max[], push[], last;

    segment_tree(int n) {
        max = new int [4 * n];
        push = new int [4 * n];
        last = n - 1;
    }

    void pushing(int v) {
        push[v * 2 + 1] += push[v];
        push[v * 2 + 2] += push[v];
        max[v * 2 + 1] += push[v];
        max[v * 2 + 2] += push[v];
        push[v] = 0;
    }

    int get() {
        return max[0];
    }

    void set(int l, int r, int x) {
        set(0, 0, last, l, r, x);
    }

    void set(int v, int l, int r, int left, int right, int x) {
        if (l > right || r < left) return;
        if (l >= left && r <= right) {
            push[v] += x;
            max[v] += x;
            return;
        }
        pushing(v);
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, left, right, x);
        set(v * 2 + 2, m + 1, r, left, right, x);
        max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
    }

}