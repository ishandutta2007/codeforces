import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int p = nextInt();
        int k = nextInt();
        long a[] = new long [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        TreeMap<Integer, Integer> cnt = new TreeMap<>();
        int b[] = new int [n];
        for(int i = 0;i < n;i++) {
            long cc = (a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p) + 3 * p;
            int next = (int)(cc % p);
            if (cnt.containsKey(next)) cnt.put(next, cnt.get(next) + 1);
            else cnt.put(next, 1);
        }
        long ans = 0;
        for(Map.Entry<Integer, Integer> i : cnt.entrySet()) {
            ans += (long) i.getValue() * (i.getValue() - 1) / 2;
        }
        pw.print(ans);
        pw.close();
    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw = new PrintWriter(System.out);

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