import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    static void add(HashMap<Integer, Integer> one, int two) {
        if (!one.containsKey(two)) one.put(two, 0);
        one.put(two, one.get(two) + 1);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int ans = inf;
        for(int l = 0;l < n;l++) {
            int cnt = 0;
            HashMap<Integer, Integer> b = new HashMap<>();
            for(int  i = 0;i < n;i++) {
                add(b, a[i]);
                if (b.get(a[i]) == 2) cnt++;
            }
            if (cnt == 0) ans = 0;
            for(int r = l;r < n;r++) {
                b.put(a[r], b.get(a[r]) - 1);
                if (b.get(a[r]) == 1) cnt--;
                if (cnt == 0) {
                    ans = Math.min(ans, r - l + 1);
                    break;
                }
            }
        }
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