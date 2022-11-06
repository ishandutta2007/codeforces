import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;

public class template {
    public static void main(String[] args) throws Exception {
        new template().run();
    }

    public void run() throws Exception {
        FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt();
        if (n == 1) {
            out.println("1");
            out.flush();
            return;
        }
        adj = new LinkedList[n];
        for (int i = 0; i < n; i++)
            adj[i] = new LinkedList<>();
        for (int i = 0; i < n - 1; i++) {
            int a = f.nextInt() - 1, b = f.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        sz = new int[n];
        int size = n;
        marked = new int[n];
        leaf = new int[n];
        for (int i = 0; i < n; i++)
            if (adj[i].size() == 1)
                size -= removeLeaf(i, -1, i);
        if (size == 0) {
            for (int i = 0; i < n; i++) {
                if (adj[i].size() == 1) {
                    out.println(i + 1);
                    out.flush();
                    return;
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (marked[i] == 0) {
                dfs(i, -1);
                break;
            }
        int st = -1;
        int min = size;
        for (int i = 0; i < n; i++) {
            if (marked[i] != 0)
                continue;
            int val = -1;
            for (int j : adj[i]) {
                if (marked[j] != 0)
                    continue;
                int v = sz[j];
                if (v > sz[i])
                    v = size - sz[i];
                if (val == -1)
                    val = v;
                else if (val != v) {
                    val = -2;
                    break;
                }
            }
            if (val != -2 && val < min) {
                st = i;
                min = val;
            }
        }
        if (st == -1) {
            out.println(-1);
            out.flush();
            return;
        }
        HashMap<Integer, Integer> hs = new HashMap<>();
        for (int i : adj[st]) {
            if (!hs.containsKey(marked[i]))
                hs.put(marked[i], i);
            else
                hs.put(marked[i], -1);
        }
        hs.remove(0);
        for (int i : hs.keySet())
            if (hs.get(i) != -1)
                st = leaf[hs.get(i)];
        if (st == -1)
            out.println(-1);
        else {
            boolean works = true;
            LinkedList<Integer> q = new LinkedList<>();
            q.add(st);
            q.add(0);
            int[] deg = new int[n];
            Arrays.fill(deg, -1);
            boolean[] visited = new boolean[n];
            while (!q.isEmpty() && works) {
                int i = q.poll();
                int d = q.poll();
                visited[i] = true;
                if (deg[d] == -1)
                    deg[d] = adj[i].size();
                else if (deg[d] != adj[i].size())
                    works = false;
                for (int j : adj[i])
                    if (!visited[j]) {
                        q.add(j);
                        q.add(d + 1);
                    }
            }
            out.println(works ? st + 1 : -1);
        }
        ///
        out.flush();
    }

    int[] sz;
    LinkedList<Integer>[] adj;
    int[] marked;
    int[] leaf;

    public int removeLeaf(int i, int p, int l) {
        if (adj[i].size() > 2 || marked[i] != 0)
            return 0;
        marked[i] = p == -1 ? 1 : marked[p] + 1;
        leaf[i] = l;
        int ans = 1;
        for (int j : adj[i])
            if (j != p)
                ans += removeLeaf(j, i, l);
        return ans;
    }

    public int dfs(int i, int p) {
        if (marked[i] != 0)
            return 0;
        for (int j : adj[i])
            if (j != p)
                sz[i] += dfs(j, i);
        return ++sz[i];
    }

    ///
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}