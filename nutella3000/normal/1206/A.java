import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static int bracket[];
    static ArrayList<Integer> gr[];
    static ArrayList<Integer> ver = new ArrayList<>();
    static int last_pref = 0;
    static long this_ans = 0;
    static long k[];
    static long cnt_eq[];
    static long pref[];
    static Deque<Integer> id_min = new ArrayDeque<>();

    static void dfs(int v) {
        last_pref += bracket[v];
        pref[v] = last_pref;

        int prev = ver.get(id_min.getLast());
        long pr_p = 0, eq_p = 0;
        if (prev != -1) {
            pr_p = pref[prev];
            eq_p = cnt_eq[prev];
        }

        if (pr_p < pref[v]) cnt_eq[v] = 0;
        else cnt_eq[v] = eq_p + 1;
        this_ans += cnt_eq[v];
        k[v] = this_ans;

        ver.add(v);

        if (pr_p >= last_pref) id_min.add(ver.size() - 1);

        for(int to : gr[v]) {
            dfs(to);
        }

        ver.remove(ver.size() - 1);
        if (id_min.getLast() == ver.size()) id_min.pollLast();
        this_ans -= cnt_eq[v];
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        bracket = new int [n];
        gr = new ArrayList[n];
        k = new long [n];
        cnt_eq = new long[n];
        pref = new long [n];


        char temp[] = sc.next().toCharArray();
        for(int i = 0;i < n;i++) {
            if (temp[i] == '(') bracket[i] = 1;
            else bracket[i] = -1;
        }

        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();


        for(int i = 1;i < n;i++) gr[sc.nextInt() - 1].add(i);


        ver.add(-1);
        id_min.add(0);
        dfs(0);

        long ans = 0;
        for(int i = 0;i < n;i++) {
            ans = (ans ^ ((long)(i + 1) * k[i]));
        }

        pw.println(ans);
    }




    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int max1 = 0, max2 = 0;
        for(int i = 0;i < n;i++) max1 = Math.max(max1, sc.nextInt());
        int m  =sc.nextInt();
        for(int i = 0;i < m;i++) max2 = Math.max(max2, sc.nextInt());
        pw.println(max1 + " " + max2);
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