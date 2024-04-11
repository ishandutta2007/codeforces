import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static int cnt(int b) {
        int ans = 0;
        while(b != 0) {
            if ((b & 1) == 1) ans++;
            b >>= 1;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int num = 10001;
        int v[] = new int [num];
        for(int i = 0;i < n;i++) v[nextInt()]++;

        long ans = 0;
        ArrayList<Integer> t = new ArrayList<>();
        for(int i = 0;i < num * 2;i++) if (cnt(i) == k) t.add(i);

        for(int i = 0;i < num;i++) {
            for(int q : t) {
                int j = (i ^ q);
                if (j < num) {
                    if (i == j) ans += (long) v[i] * (v[i] - 1);
                    else ans += (long) v[i] * v[j];
                }
            }
        }
        pw.println(ans / 2);
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

class w implements Comparator<w>{
    int x, id;
    w(int x, int id) {
        this.x = x;
        this.id = id;
    }

    w() {}

    @Override
    public int compare(w w, w t1) {
        return -Integer.compare(w.x, t1.x);
    }
}