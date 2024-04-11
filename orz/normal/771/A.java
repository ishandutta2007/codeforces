import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by jetbrains on 03/18/2017.
 */
public class A {

    public static void main(String[] args) throws IOException {
        new A().run();
    }

    ArrayList<Integer>[] graph;
    int[] color;

    private void run() throws IOException {
        IO files = new IO();
        int n = files.nextInt(), m = files.nextInt();

        graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = files.nextInt() - 1, b = files.nextInt() - 1;
            graph[a].add(b);
            graph[b].add(a);
        }

        color = new int[n];
        Arrays.fill(color, -1);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                dfs(i, c);
                c++;
            }
        }

        ArrayList<Integer>[] vars = new ArrayList[c];
        for (int i = 0; i < c; i++) {
            vars[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            vars[color[i]].add(i);
        }

        for (int i = 0; i < c; i++) {
            for (int v : vars[i]) {
                if (graph[v].size() != vars[i].size() - 1) {
                    files.println("NO");
                    files.close();
                    return;
                }
            }
        }

        files.println("YES");
    }

    private void dfs(int v, int c) {
        color[v] = c;

        for (int u : graph[v]) {
            if (color[u] == -1) {
                dfs(u, c);
            }
        }
    }

    class IO {

        BufferedReader in;
        PrintWriter out;
        StringTokenizer st;

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        public IO(String name) throws FileNotFoundException {
            in = new BufferedReader(new FileReader(name + ".in"));
            out = new PrintWriter(name + ".out");
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(in.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public void print(String string) {
            out.print(string);
        }

        public void println(String string) {
            out.println(string);
        }

        public void println() {
            out.println();
        }

        public void close() {
            out.close();
        }

    }


}