import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int q = nextInt();
        Deque<Integer> a = new ArrayDeque<>();
        for(int i = 0;i < n;i++) a.add(nextInt());
        int b[] = new int [n];
        int b2[] = new int [n];
        for(int i = 0;i < n;i++) {
            int first = a.getFirst();
            a.pollFirst();
            int second = a.pollFirst();
            b[i] = first;
            b2[i] = second;
            if (first < second) {
                int t = first;
                first = second;
                second = t;
            }
            a.addFirst(first);
            a.addLast(second);
        }
        int c[] = new int [n - 1];
        int first = a.pollFirst();
        for(int i = 0;i < n - 1;i++) c[i] = a.pollFirst();
        for(int i = 0;i < q;i++) {
            long r = nextLong();
            if (r <= n) {
                pw.println(b[(int) (r - 1)] + " " + b2[(int) (r - 1)]);
            }else{
                r -= n + 1;
                pw.println(first + " " + c[(int) (r % (n - 1))]);
            }
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
        while (!st.hasMoreTokens() || st == null) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}