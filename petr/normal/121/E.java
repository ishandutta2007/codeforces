import java.io.*;
import java.util.StringTokenizer;

public class HappyArray implements Runnable {
    static class Node {
        int numHappy = 0;
        int nextEvent = 0;
        int delta = 0;
        Node left = null;
        Node right = null;
    }

    int[] nextHappy;

    /*private void stress() throws FileNotFoundException {
        Random random = new Random(491753154315431L);
        while (true) {
            int n = random.nextInt(10) + 1;
            int m = 1000;
            PrintWriter writer = new PrintWriter("input.txt");
            writer.println(n + " " + m);
            for (int i = 0; i < n; ++i) {
                writer.print(random.nextInt(1000) + 1);
                writer.print(" ");
            }
            writer.println();
            for (int i = 0; i < m; ++i) {
                int l = random.nextInt(n) + 1;
                int r = random.nextInt(n) + 1;
                if (l > r) {
                    int t = l;
                    l = r;
                    r = t;
                }
                if (random.nextBoolean())
                    writer.println("count " + l + " " + r + " ");
                else
                    writer.println("add " + l + " " + r + " " + (random.nextInt(100) + 1));
            }
            writer.close();
            run();
            System.out.print(".");
        }
    }*/

    private void solve() throws IOException {
        int[] happy = new int[(1 << 5) - 2];
        int pos = 0;
        for (int len = 1; len <= 4; ++len) {
            for (int mask = 0; mask < (1 << len); ++mask) {
                int num = 0;
                for (int i = 0; i < len; ++i)
                    if ((mask & (1 << (len - 1 - i))) != 0) num = num * 10 + 7; else num = num * 10 + 4;
                happy[pos++] = num;
            }
        }
        if (pos != happy.length) throw new RuntimeException();
        nextHappy = new int[10001];
        int curNext = 20000;
        pos = happy.length - 1;
        for (int i = 10000; i >= 0; --i) {
            if (pos >= 0 && happy[pos] == i) {
                --pos;
                curNext = i;
            }
            nextHappy[i] = curNext;
        }
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
        }
        Node root = buildTree(0, n - 1, a);
        for (int i = 0; i < m; ++i) {
            String op = nextToken();
            if (op.equals("count")) {
                int l = nextInt() - 1;
                int r = nextInt() - 1;
                writer.println(count(root, 0, n - 1, l, r));
            } else if (op.equals("add")) {
                int l = nextInt() - 1;
                int r = nextInt() - 1;
                int d = nextInt();
                add(root, 0, n - 1, l, r, d);
            }
        }
    }

    private void add(Node root, int left, int right, int l, int r, int d) {
        l = Math.max(l, left);
        r = Math.min(r, right);
        if (l > r)
            return;
        if (l == left && r == right) {
            addToWholeNode(root, left, right, d);
            return;
        }
        root.left.delta += root.delta;
        root.right.delta += root.delta;
        root.left.nextEvent -= root.delta;
        root.right.nextEvent -= root.delta;
        root.delta = 0;
        int middle = (left + right) / 2;
        add(root.left, left, middle, l, r, d);
        add(root.right, middle + 1, right, l, r, d);
        updateNode(root);
    }

    private void addToWholeNode(Node root, int left, int right, int d) {
        if (root.nextEvent == 0) throw new RuntimeException();
        if (d < root.nextEvent) {
            root.nextEvent -= d;
            root.delta += d;
            return;
        }
        if (left == right) {
            if (nextHappy[root.delta] == root.delta)
                --root.numHappy;
            if (root.numHappy != 0) throw new RuntimeException();
            root.delta += d;
            int next = nextHappy[root.delta];
            if (next == root.delta) {
                ++root.numHappy;
                root.nextEvent = 1;
            } else {
                root.nextEvent = next - root.delta;
            }
            return;
        }
        root.left.delta += root.delta;
        root.right.delta += root.delta;
        root.left.nextEvent -= root.delta;
        root.right.nextEvent -= root.delta;
        root.delta = 0;
        int middle = (left + right) / 2;
        addToWholeNode(root.left, left, middle, d);
        addToWholeNode(root.right, middle + 1, right, d);
        updateNode(root);
    }

    private int count(Node root, int left, int right, int l, int r) {
        l = Math.max(l, left);
        r = Math.min(r, right);
        if (l > r)
            return 0;
        if (l == left && r == right)
            return root.numHappy;
        int middle = (left + right) / 2;
        return count(root.left, left, middle, l, r) + count(root.right, middle + 1, right, l, r);
    }

    private Node buildTree(int left, int right, int[] a) {
        Node res = new Node();
        if (left == right) {
            int val = a[left];
            int next = nextHappy[val];
            if (next == val) {
                ++res.numHappy;
                res.nextEvent = 1;
            } else {
                res.nextEvent = next - val;
            }
            res.delta = val;
        } else {
            int middle = (left + right) / 2;
            res.left = buildTree(left, middle, a);
            res.right = buildTree(middle + 1, right, a);
            updateNode(res);
        }
        return res;
    }

    private void updateNode(Node res) {
        if (res.delta != 0) throw new RuntimeException();
        res.numHappy = res.left.numHappy + res.right.numHappy;
        res.nextEvent = Math.min(res.left.nextEvent, res.right.nextEvent);
    }

    public static void main(String[] args) throws FileNotFoundException {
        new HappyArray().run();
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