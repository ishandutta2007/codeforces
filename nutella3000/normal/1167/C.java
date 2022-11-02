import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static ArrayList<Integer> gr[];
    static int comp[];
    static int cnt_of_edges = 0;
    static void dfs(int v,int k) {
        if (comp[v] != 0) return;
        comp[v] = k;
        for(int i : gr[v]) {
            dfs(i, k);
            cnt_of_edges++;
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        ArrayList<Integer> peoples[] = new ArrayList[m];
        gr = new ArrayList[m];
        comp = new int [m];
        for(int i = 0;i < m;i++) {
            gr[i] = new ArrayList<>();
            peoples[i] = new ArrayList<>();
        }
        ArrayList<Integer> group[] = new ArrayList[n];
        for(int i = 0;i < n;i++) group[i] = new ArrayList<>();
        for(int i = 0;i < m;i++) {
            int k = nextInt();
            for(int j = 0;j < k;j++) {
                int v = nextInt() - 1;
                peoples[i].add(v);
                group[v].add(i);
            }
        }
        for(int i = 0;i < n;i++) {
            int last = -1;
            for(int j : group[i]) {
                if (last != -1) {
                    gr[last].add(j);
                    gr[j].add(last);
                }
                last = j;
            }
        }
        ArrayList<Integer> edge = new ArrayList<>();
        int k = 1;
        for(int i = 0;i < m;i++) {
            if (comp[i] == 0) {
                dfs(i, k);
                edge.add(cnt_of_edges);
                cnt_of_edges = 0;
                k++;
            }
        }
        int ans1[] = new int [k];
        for(int i = 0;i < m;i++) {
            ans1[comp[i]] += peoples[i].size();
        }
        for(int i = 1;i < k;i++) ans1[i] -= edge.get(i - 1) / 2;
        int cnt[] = new int [n];
        for(int i = 0;i < n;i++) {
            if (group[i].size() != 0) {
                cnt[i] = ans1[comp[group[i].get(0)]];
            }else cnt[i] = 1;
        }
        for(int i = 0;i < n;i++) pw.print(cnt[i] + " ");
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