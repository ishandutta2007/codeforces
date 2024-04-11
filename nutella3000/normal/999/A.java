import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter pw=  new PrintWriter(System.out);
       int n = nextInt();
       int k = nextInt();
       Deque<Integer> b = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            b.add(nextInt());
        }
        int ans = 0;
        while (!b.isEmpty() && b.peekFirst() <= k) {
            b.pollFirst();
            ans++;
        }
        while (!b.isEmpty() && b.peekLast() <= k) {
            b.pollLast();
            ans++;
        }
        pw.println(ans);
       pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st= new StringTokenizer("");
    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
}