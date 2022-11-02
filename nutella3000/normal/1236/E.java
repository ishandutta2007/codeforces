import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static int xr[] = new int[]{0, 1, 0, -1};
    static int yr[] = new int[]{1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }

        pair a[] = new pair[m];
        for(int i = 0;i < m;i++) {
            a[i] = new pair(i + 1, sc.nextInt());
        }

        long ans = 0;
        ArrayList<Integer> right[] = new ArrayList[n + m + 2];
        ArrayList<Integer> left[] = new ArrayList[n + m + 2];
        ArrayList<Integer> num1[] = new ArrayList[n +  m + 2];
        ArrayList<Integer> num2[] = new ArrayList[n + m + 2];
        for(int i = 0;i < n + m + 2;i++) {
            right[i] = new ArrayList<>();
            left[i] = new ArrayList<>();
            num1[i] = new ArrayList<>();
            num2[i] = new ArrayList<>();
        }

        for(int i = 0;i < m;i++) {
            right[a[i].id - a[i].t + m].add(a[i].id);
            left[a[i].id + a[i].t].add(a[i].id);
        }
        for(int i = 0;i <= n + m;i++) {
            Collections.sort(right[i]);
            Collections.sort(left[i], new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer t1) {
                    return -Integer.compare(o1, t1);
                }
            });
        }

        for(int i = 0;i <= n + m;i++) {
            for(int j : right[i]) {
                int l = -1;
                int r = inf;
                if (i != 0) r = right[i - 1].size();

                while(r - l > 1) {
                    int mid = ((l + r) >> 1);
                    if (right[i - 1].get(mid) >= j) r = mid;
                    else l = mid;
                }

                if (r == inf || r == right[i - 1].size()) num1[i].add(1);
                else num1[i].add(1 + num1[i - 1].get(r));
            }
        }

        for(int i = n + m;i >= 0;i--) {
            for(int j : left[i]) {
                int l = -1;
                int r = 0;
                if (i != n + m) r = left[i + 1].size();

                while(r - l > 1) {
                    int mid = ((l + r) >> 1);
                    if (left[i + 1].get(mid) <= j) r = mid;
                    else l = mid;
                }

                if (i == n + m || r == left[i + 1].size()) num2[i].add(1);
                else num2[i].add(1 + num2[i + 1].get(r));
            }
        }

        /*for(int i = 0;i < n + m + 2;i++) {
            pw.print(i + ": ");
            for(int j : num1[i]) pw.print(j + " ");
            pw.println();
        }

        for(int i = 0;i < n + m + 2;i++) {
            pw.print(i + ": ");
            for(int j : num2[i]) pw.print(j + " ");
            pw.println();
        }

        pw.println();*/

        for(int i = 1;i <= n;i++) {
            int l = -1;
            int r = num1[i + m].size();
            while(r - l > 1) {
                int mid = ((l + r) >> 1);
                if (right[i + m].get(mid) >= i) r = mid;
                else l = mid;
            }
            int second = m + 1;
            if (r != num1[i + m].size()) second -= num1[i + m].get(r);

            ans += Math.min(n - i, second);
            //pw.println(ans);


            l = -1;
            r = num2[i].size();
            while(r - l > 1) {
                int mid = ((l + r) >> 1);
                if (left[i].get(mid) <= i) r = mid;
                else l = mid;
            }

            second = m + 1;
            if (r != num2[i].size()) second -= num2[i].get(r);

            ans += Math.min(i - 1, second);

            //pw.println(ans);
        }

        pw.println(ans + n);
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

class pair {
    int t, id;
    pair(int t, int id) {
        this.t = t;
        this.id = id;
    }

    pair() {}
}