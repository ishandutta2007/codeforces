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
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[][] = new int [m][n];
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0;i < m;i++) ans.add(i);

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                a[i][j] = sc.nextInt();
            }
        }

        for(int i = 0;i < n - 1;i++) {
            long sum = 0;
            for(int j = 0;j < m;j++) sum += a[j][i] - a[j][n - 1];

            pair s[] = new pair [m];
            for(int j = 0;j < m;j++) s[j] = new pair(a[j][i] - a[j][n - 1], j);
            Arrays.sort(s, new pair());
            for(int j = 0;j < m;j++) {
                if (sum >= 0) {
                    if (ans.size() > j) {
                        ans.clear();
                        for(int q = 0;q < j;q++) ans.add(s[q].id);
                    }
                    break;
                }

                sum -= s[j].x;
            }

        }

        pw.println(ans.size());
        for(int i : ans) pw.print(i + 1 + " ");
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

class pair implements Comparator<pair>{
    int x, id;
    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }
    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}