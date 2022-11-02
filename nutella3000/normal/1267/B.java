import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int left[], right[];

    static void gfs(int a[]) {
        Deque<Integer> o1 = new ArrayDeque<>();
        Deque<Integer> o2 = new ArrayDeque<>();

        for(int i = 0;i < a.length;i++) {
            while(!o1.isEmpty() && a[o1.getLast()] >= a[i]) o1.pollLast();
            while(!o2.isEmpty() && a[o2.getLast()] >= a[a.length - i - 1]) o2.pollLast();

            if (o1.isEmpty()) left[i] = 0;
            else left[i] = o1.getLast() + 1;

            if (o2.isEmpty()) right[a.length - i - 1] = a.length - 1;
            else right[a.length - i - 1] = o2.getLast() - 1;

            o1.add(i);
            o2.add(a.length - i - 1);
        }

    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char h[] = sc.next().toCharArray();
        int n = h.length;
        ArrayList<Character> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            if (i == 0 || h[i] != h[i - 1]) {
                a.add(h[i]);
                b.add(1);
            }else b.set(b.size() - 1, b.get(b.size() - 1) + 1);
        }

        int l = 0;
        int r = a.size() - 1;
        int ans = 0;
        while(l < r) {
            if (a.get(l) != a.get(r) || b.get(l) + b.get(r) < 3) ans = -1;
            l++;
            r--;
        }

        if (ans != -1 && b.get(l) != 1) ans = b.get(l) + 1;
        else ans = 0;
        pw.println(ans);

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