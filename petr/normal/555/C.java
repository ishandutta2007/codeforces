import java.util.Arrays;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static class Tree {
        int[] arr;
        int n;

        public Tree(int n) {
            this.n = n;
            arr = new int[4 * n + 10];
            Arrays.fill(arr, -1);
        }

        void update(int l, int r, int v) {
            internalUpd(0, 0, n - 1, l, r, v);
        }

        int get(int x) {
            return internalGet(0, 0, n - 1, x);
        }

        private int internalGet(int root, int rl, int rr, int x) {
            int res = arr[root];
            if (rl == rr) return res;
            int rm = (rl + rr) / 2;
            if (x <= rm) return Math.max(res, internalGet(root * 2 + 1, rl, rm, x)); else return Math.max(res, internalGet(root * 2 + 2, rm + 1, rr, x));
        }

        private void internalUpd(int root, int rl, int rr, int l, int r, int v) {
            if (l > r) return;
            if (rl == l && rr == r) {
                arr[root] = Math.max(arr[root], v);
                return;
            }
            int rm = (rl + rr) / 2;
            internalUpd(root * 2 + 1, rl, rm, l, Math.min(rm, r), v);
            internalUpd(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, l), r, v);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] qx = new int[q];
        int[] qy = new int[q];
        boolean[] qup = new boolean[q];
        for (int iq = 0; iq < q; ++iq) {
            qx[iq] = in.nextInt() - 1;
            qy[iq] = in.nextInt() - 1;
            qup[iq] = in.next().equals("U");
        }
        int[] allX = normalize(qx);
        int[] allY = normalize(qy);
        Tree left = new Tree(allY.length);
        Tree up = new Tree(allX.length);
        for (int iq = 0; iq < q; ++iq) {
            int x = Arrays.binarySearch(allX, qx[iq]);
            int y = Arrays.binarySearch(allY, qy[iq]);
            if (qup[iq]) {
                int stopAt = up.get(x);
                if (stopAt < 0) {
                    out.println(allY[y] + 1);
                } else {
                    out.println(allY[y] - allY[stopAt]);
                }
                up.update(x, x, y);
                left.update(stopAt + 1, y, x);
            } else {
                int stopAt = left.get(y);
                if (stopAt < 0) {
                    out.println(allX[x] + 1);
                } else {
                    out.println(allX[x] - allX[stopAt]);
                }
                left.update(y, y, x);
                up.update(stopAt + 1, x, y);
            }
        }
    }

    private int[] normalize(int[] qx) {
        int[] allX = qx.clone();
        shuffle(allX);
        Arrays.sort(allX);
        int xCnt = 1;
        for (int i = 1; i < allX.length; ++i) if (allX[i] > allX[i - 1]) {
            allX[xCnt++] = allX[i];
        }
        allX = Arrays.copyOf(allX, xCnt);
        return allX;
    }

    Random random = new Random(5437534511L + System.currentTimeMillis());

    private void shuffle(int[] allX) {
        for (int i = 0; i < allX.length; ++i) {
            int j = i + random.nextInt(allX.length - i);
            int tmp = allX[i];
            allX[i] = allX[j];
            allX[j] = tmp;
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

}