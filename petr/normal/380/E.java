import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static class Item {
        int pos;
        int what;

        Item(int pos, int what) {
            this.pos = pos;
            this.what = what;
        }
    }
    
    static final double SMALL = Math.pow(0.5, 30);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Item[] b = new Item[n];
        for (int i = 0; i < n; ++i) b[i] = new Item(i + 1, in.nextInt());
        Arrays.sort(b, new Comparator<Item>() {
            @Override
            public int compare(Item o1, Item o2) {
                return o2.what - o1.what;
            }
        });
        double res = 0;
        int[] next = new int[n + 2];
        int[] prev = new int[n + 2];
        int[] first = new int[4 * n + 20];
        initFirst(first, 0, 0, n + 1);
        setFirst(first, 0, 0, n + 1, 0);
        setFirst(first, 0, 0, n + 1, n + 1);
        int[] last = new int[4 * n + 20];
        initFirst(last, 0, 0, n + 1);
        setFirst(last, 0, 0, n + 1, 0);
        setFirst(last, 0, 0, n + 1, n + 1);
        Arrays.fill(next, -1);
        Arrays.fill(prev, -1);
        next[0] = n + 1;
        prev[n + 1] = 0;
        for (Item cur : b) {
            int after = findFirst(first, 0, 0, n + 1, cur.pos);
            int before = n + 1 - findFirst(last, 0, 0, n + 1, n + 1 - cur.pos);
            int left = cur.pos;
            int right = cur.pos;
            double leftSum = cur.pos - before;
            int tmp = before;
            double mult = 1.0;
            while (tmp > 0 && mult > SMALL) {
                mult *= 0.5;
                leftSum += mult * (tmp - prev[tmp]);
                tmp = prev[tmp];
            }
            double rightSum = after - cur.pos;
            tmp = after;
            mult = 1.0;
            while (tmp < n + 1 && mult > SMALL) {
                mult *= 0.5;
                rightSum += mult * (next[tmp] - tmp);
                tmp = next[tmp];
            }
            res += 0.5 * cur.what * leftSum * rightSum;
            prev[cur.pos] = before;
            next[cur.pos] = after;
            next[before] = cur.pos;
            prev[after] = cur.pos;
            setFirst(first, 0, 0, n + 1, cur.pos);
            setFirst(last, 0, 0, n + 1, n + 1 - cur.pos);
        }
        out.printf(String.format("%.15f", res / n / n));
    }

    private void setFirst(int[] first, int root, int rl, int rr, int at) {
        if (at < first[root])
            first[root] = at;
        if (rl == rr) {
            return;
        }
        int rm = (rl + rr) / 2;
        if (at <= rm)
            setFirst(first, root * 2 + 1, rl, rm, at);
        else
            setFirst(first, root * 2 + 2, rm + 1, rr, at);
    }

    private void initFirst(int[] first, int root, int rl, int rr) {
        first[root] = rr + 1;
        if (rl == rr) {
            return;
        }
        int rm = (rl + rr) / 2;
        initFirst(first, root * 2 + 1, rl, rm);
        initFirst(first, root * 2 + 2, rm + 1, rr);
    }

    private int findFirst(int[] first, int root, int rl, int rr, int atleast) {
        if (atleast == rl) {
            return first[root];
        }
        int rm = (rl + rr) / 2;
        if (rm < atleast) {
            return findFirst(first, root * 2 + 2, rm + 1, rr, atleast);
        } else {
            int x = findFirst(first, root * 2 + 1, rl, rm, atleast);
            if (x > rm) {
                x = findFirst(first, root * 2 + 2, rm + 1, rr, rm + 1);
            }
            return x;
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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