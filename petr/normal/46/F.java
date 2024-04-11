import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Rooms implements Runnable {
    static class Door {
        int a;
        int b;
    }

    static class Component {
        Set<String> names = new HashSet<String>();
        Set<Door> keys = new HashSet<Door>();

        public int size() {
            return names.size() + keys.size();
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        Door[] door = new Door[m];
        for (int i = 0; i < m; ++i) {
            door[i] = new Door();
            door[i].a = nextInt() - 1;
            door[i].b = nextInt() - 1;
        }
        Component[][] res = new Component[2][];
        for (int step = 0; step < 2; ++step) {
            Component[] where = new Component[n];
            for (int i = 0; i < n; ++i) {
                where[i] = new Component();
            }
            for (int i = 0; i < k; ++i) {
                String name = nextToken();
                int room = nextInt() - 1;
                Component cur = where[room];
                cur.names.add(name);
                int cnt = nextInt();
                for (int j = 0; j < cnt; ++j) {
                    cur.keys.add(door[nextInt() - 1]);
                }
            }
            while (true) {
                boolean changed = false;
                for (Door d : door) {
                    if (where[d.a] == where[d.b])
                        continue;
                    if (where[d.a].keys.contains(d) || where[d.b].keys.contains(d)) {
                        changed = true;
                        Component a = where[d.a];
                        Component b = where[d.b];
                        a.keys.addAll(b.keys);
                        a.names.addAll(b.names);
                        for (int i = 0; i < n; ++i)
                            if (where[i] == b)
                                where[i] = a;
                    }
                }
                if (!changed)
                    break;
            }
            res[step] = where;
        }
        boolean result = true;
        for (int i = 0; i < n; ++i) {
            Component a = res[0][i];
            Component b = res[1][i];
            if (a.names.equals(b.names) && a.keys.equals(b.keys))
                continue;
            result = false;
            break;
        }
        if (result)
            writer.println("YES");
        else
            writer.println("NO");

    }

    public static void main(String[] args) {
        new Rooms().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}