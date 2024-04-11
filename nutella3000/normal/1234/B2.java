import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static long inf = (long) 1e15 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        Deque<Integer> ans = new ArrayDeque<>();
        HashSet<Integer> cont = new HashSet<>();
        for(int i = 0;i < n;i++) {
            int v = nextInt();
            if (cont.contains(v)) continue;
            if (ans.size() == k) {
                cont.remove(ans.pollLast());
            }
            ans.addFirst(v);
            cont.add(v);
        }

        pw.println(ans.size());
        for(int i : ans) pw.print(i + " ");
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