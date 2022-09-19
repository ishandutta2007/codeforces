import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        Edge[] edges = new Edge[m];
        for (int i = 0; i < m; i++) {
            edges[i] = new Edge(nextInt(), nextInt() == 1);
        }
        List<Edge> tree = new ArrayList<>();
        List<Edge> noTree = new ArrayList<>();
        for (Edge edge : edges) {
            if (edge.inTree) tree.add(edge);
            else noTree.add(edge);
        }
        Collections.sort(tree);
        Collections.sort(noTree);
        for (int i = 0; i < n - 1; i++) {
            tree.get(i).a = i;
            tree.get(i).b = i + 1;
        }
        int k = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i - 1; j++) {
                if (k < noTree.size() && noTree.get(k).w >= tree.get(i - 1).w) {
                    noTree.get(k).a = j;
                    noTree.get(k).b = i;
                    k++;
                } else {
                    break;
                }
            }
        }
        if (k < noTree.size()) {
            out.println(-1);
        } else {
            for (Edge edge : edges) {
                out.println((edge.a + 1) + " " + (edge.b + 1));
            }
        }

    }

    class Edge implements Comparable<Edge> {
        int w;
        boolean inTree;
        int a;
        int b;

        public Edge(int w, boolean inTree) {
            this.w = w;
            this.inTree = inTree;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(w, o.w);
        }
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}