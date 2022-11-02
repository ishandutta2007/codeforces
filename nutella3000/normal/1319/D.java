import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static ArrayList<Integer> gr[];
    static int dist[];
    static ArrayList<Integer> temp = new ArrayList<>();
    static int fin;

    static void build() {
        ArrayList<Integer> g[] = new ArrayList[n];
        for(int i = 0;i < n;i++) g[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            for(int j : gr[i]) g[j].add(i);
        }

        dist = new int [n];
        for(int i = 0;i < n;i++) dist[i] = (int) 1e9;
        dist[fin] = 0;
        Deque<Integer> bfs = new ArrayDeque<>();
        bfs.add(fin);
        while(!bfs.isEmpty()) {
            int v = bfs.pollFirst();

            for(int to : g[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    bfs.add(to);
                }
            }
        }
    }


    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt()  -1;
            gr[v1].add(v2);
        }

        int k = sc.nextInt();
        for(int i = 0;i < k;i++) {
            temp.add(sc.nextInt() - 1);
        }
        fin = temp.get(temp.size() - 1);
    }

    static void solve() throws IOException {
        scan();
        build();
        int ans1 = 0;
        int ans2 = 0;
        for(int u = 0;u < temp.size() - 1;u++) {
            int i = temp.get(u);
            int next = temp.get(u + 1);
            if (i == fin) break;
            int min = (int) 1e9;
            for(int to : gr[i]) {
                if (to != next) min = Math.min(min, dist[to]);
            }
            if (dist[next] > min) {
                ans1++;
                ans2++;
            }else if (dist[next] == min) {
                ans2++;
            }
        }

        pw.println(ans1 + " " + ans2);
    }




    public static void main(String[] args) throws IOException {
        sc = new Fast_Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();

        pw.close();
    }


    static Fast_Scanner sc;
    static PrintWriter pw;

    static class Fast_Scanner {
        static BufferedReader br;
        static StringTokenizer st = new StringTokenizer("");

        Fast_Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Fast_Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        Double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }


}