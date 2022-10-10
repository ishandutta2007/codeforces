import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by Admin on 11.03.2017.
 */
public class Study {

    public static void main(String[] args) {
        new Study().run();
    }

    private int[][] graph;
    private int[] visited;
    private ArrayList<Integer> result;

    private void run() {
        IO files = new IO();
        int n = files.nextInt(), k = files.nextInt();
        int[] top = new int[k];
        graph = new int[n + 1][];

        graph[0] = new int[k];
        for (int i = 0; i < k; i++) {
            top[i] = files.nextInt();
            graph[0][i] = top[i];
        }

        for (int i = 1; i <= n; i++) {
            graph[i] = new int[files.nextInt()];
            for (int j = 0; j < graph[i].length; j++) {
                graph[i][j] = files.nextInt();
            }
        }

        visited = new int[n + 1];
        result = new ArrayList<>();
        dfs(0, files);

        files.out.println(result.size() - 1);
        for (int course : result) {
            if (course != 0) {
                files.out.print(course + " ");
            }
        }
        files.out.close();
    }

    private void dfs(int v, IO files) {
        visited[v] = 1;

        for (int u : graph[v]) {
            if (visited[u] == 0) {
                dfs(u, files);
            } else if (visited[u] == 1) {
                files.out.println(-1);
                files.out.close();
                System.exit(0);
            }
        }

        visited[v] = 2;
        result.add(v);
    }

    class IO {
        private BufferedReader in;
        private StringTokenizer st;
        PrintWriter out;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}