import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        int b[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            b[i] = nextInt();
        }
        int cnt1 = 0;
        for(int i = 0;i < n;i++) {
            if (a[i] > b[i]) cnt1++;
        }
        w t[] = new w[n];
        if (cnt1 < n - cnt1) {
            for(int i = 0;i < n;i++) t[i] = new w(b[i], a[i], i + 1);
        }else for(int i = 0;i < n;i++) t[i] = new w(a[i], b[i], i + 1);
        Arrays.sort(t, new w());
        pw.println(Math.max(cnt1, n - cnt1));
        ArrayList<Integer> ans = new ArrayList<>();
        if (cnt1 >= n - cnt1) {
            for (int i = 0; i < n; i++) {
                if (t[i].a > t[i].b) pw.print(t[i].id + " ");
            }
        }else{
            for(int i = n - 1;i >= 0;i--) {
                ans.add(t[i].b);
                ans.add(t[i].a);
                if (t[i].a > t[i].b) pw.print(t[i].id + " ");
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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
class w implements Comparator<w>{
    int a, b, id;
    w(int a, int b, int ind) {
        this.a =a;
        this.b = b;
        id = ind;
    }
    w() {}

    @Override
    public int compare(w w, w t1) {
        return Integer.compare(w.a, t1.a);
    }
}