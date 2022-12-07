import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ngfam
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DDevelopingGame solver = new DDevelopingGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDevelopingGame {
        static int MAXN = 300030;
        static int[] lazy = new int[MAXN << 3];
        static Node[] tree = new Node[MAXN << 2];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int a[] = new int[n];
            int b[] = new int[n];
            int c[] = new int[n];

            ArrayList<Integer> lower[] = new ArrayList[MAXN];
            ArrayList<Integer> upper[] = new ArrayList[MAXN];

            for (int i = 0; i < tree.length; ++i) {
                tree[i] = new Node();
                tree[i].maxVal = 0;
                tree[i].idVal = 0;
            }

            for (int i = 0; i < MAXN; ++i) {
                lower[i] = new ArrayList<>();
                upper[i] = new ArrayList<>();
            }

            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
                c[i] = in.nextInt();
                upper[c[i]].add(i);
                lower[b[i] - 1].add(i);
            }

            build(1, 0, MAXN - 1);

            int ans = 0, ansl = 0, ansr = 0;
            for (int i = MAXN - 1; i >= 0; --i) {
                for (int id : lower[i]) {
                    update(1, 0, MAXN - 1, a[id], b[id], -1);
                }
                for (int id : upper[i]) {
                    update(1, 0, MAXN - 1, a[id], b[id], 1);
                }

//            System.out.println("Currently: " + i);

                Node cur = query(1, 0, MAXN - 1, 0, i);

                if (cur.maxVal > ans) {
                    ansl = cur.idVal;
                    ansr = i;
                    ans = cur.maxVal;
                }
            }
            out.println(ans);
            for (int i = 0; i < n; ++i) {
                if (ansl >= a[i] && ansl <= b[i] && ansr >= b[i] && ansr <= c[i]) {
                    out.print((i + 1) + " ");
                }
            }
        }

        private Node query(int x, int l, int r, int u, int v) {

            push(x);
            if (l > v || r < u) return new Node();
            if (l >= u && r <= v) {
                return tree[x];
            }
            int mid = (l + r) >> 1;
            Node a = query(x << 1, l, mid, u, v);
            Node b = query(x << 1 | 1, mid + 1, r, u, v);
            if (a.compareTo(b) < 0) return b;
            return a;
        }

        private void build(int x, int l, int r) {
            lazy[x] = 0;
            tree[x].idVal = r;
            if (l == r) {
                return;
            }
            int mid = (l + r) / 2;
            build(x << 1, l, mid);
            build(x << 1 | 1, mid + 1, r);
        }

        private void update(int x, int l, int r, int u, int v, int val) {
            push(x);
            lazy[x] = 0;
            if (l > v || r < u) return;
            if (l >= u && r <= v) {
                lazy[x] += val;
                push(x);
                lazy[x] = 0;
                return;
            }
            int mid = (l + r) / 2;
            update(x * 2, l, mid, u, v, val);
            update(x * 2 + 1, mid + 1, r, u, v, val);
            if (tree[x * 2].compareTo(tree[x * 2 + 1]) < 0) {
                tree[x].maxVal = tree[x * 2 + 1].maxVal;
                tree[x].idVal = tree[x * 2 + 1].idVal;
            } else {
                tree[x].maxVal = tree[x * 2].maxVal;
                tree[x].idVal = tree[x * 2].idVal;
            }
        }

        private void push(int x) {
            tree[x].maxVal += lazy[x];
            lazy[x * 2] += lazy[x];
            lazy[x * 2 + 1] += lazy[x];
            lazy[x] = 0;
        }

        class Node implements Comparable<Node> {
            int maxVal;
            int idVal;

            Node() {
                maxVal = 0;
                idVal = 0;
            }

            public int compareTo(Node rhs) {
                if (maxVal > rhs.maxVal) return 1;
                if (maxVal < rhs.maxVal) return -1;
                return 0;
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}