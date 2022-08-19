import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PetyaTree implements Runnable {
    static class Node {
        int key = -1;
        int maxKey;
        int minKey;
        Node left = null;
        Node right = null;

        public void updateBounds() {
            minKey = key;
            maxKey = key;
            if (left != null) {
                left.updateBounds();
                minKey = Math.min(minKey, left.minKey);
                maxKey = Math.max(maxKey, left.maxKey);
            }
            if (right != null) {
                right.updateBounds();
                minKey = Math.min(minKey, right.minKey);
                maxKey = Math.max(maxKey, right.maxKey);
            }
        }

        public void findAnswers(double sumCases, int numCases, Request[] one, int min, int max) {
            if (left == null && right == null) {
                for (int i = min; i < max; ++i)
                    one[i].answer = sumCases / numCases;
                return;
            }
            int l = min - 1;
            int r = max;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (one[m].x > key)
                    r = m;
                else
                    l = m;
            }
            left.findAnswers(sumCases + right.minKey, numCases + 1, one, min, r);
            right.findAnswers(sumCases + left.maxKey, numCases + 1, one, r, max);
        }
    }

    static class Request implements Comparable<Request> {
        int x;
        int index;
        double answer;

        Request(int x, int index) {
            this.x = x;
            this.index = index;
        }

        public int compareTo(Request request) {
            return x - request.x;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        Node[] t = new Node[n];
        for (int i = 0; i < n; ++i) t[i] = new Node();
        Node root = null;
        for (int i = 0; i < n; ++i) {
            int parent = nextInt() - 1;
            t[i].key = nextInt();
            if (parent < 0) {
                root = t[i];
            } else {
                if (t[parent].left == null) t[parent].left = t[i]; else t[parent].right = t[i];
            }
        }
        for (Node x : t) {
            if (x.left != null && x.right != null) {
                if (x.left.key > x.right.key) {
                    Node tmp = x.left;
                    x.left = x.right;
                    x.right = tmp;
                }
            }
        }
        root.updateBounds();
        int k = nextInt();
        Request[] one = new Request[k];
        for (int i = 0; i < k; ++i) {
            int what = nextInt();
            one[i] = new Request(what, i);
        }
        Arrays.sort(one);
        root.findAnswers(0.0, 0, one, 0, one.length);
        double[] res = new double[k];
        for (Request req : one)
            res[req.index] = req.answer;
        for (double x : res)
            writer.printf("%.12f\n", x);
    }

    public static void main(String[] args) {
        new PetyaTree().run();
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