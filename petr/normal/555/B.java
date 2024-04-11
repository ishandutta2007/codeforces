import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Segment implements Comparable<Segment> {
        long min;
        long max;
        Bridge assigned = null;
        int index;

        public Segment(int index, long min, long max) {
            this.index = index;
            this.min = min;
            this.max = max;
        }

        public int compareTo(Segment o) {
            int z = Long.compare(max, o.max);
            if (z == 0) {
                z = index - o.index;
            }
            return z;
        }
    }

    static class Bridge {
        int index;
        long len;

        public Bridge(int index, long len) {
            this.index = index;
            this.len = len;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long[] l = new long[n];
        long[] r = new long[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextLong();
            r[i] = in.nextLong();
        }

        Segment[] segs = new Segment[n - 1];
        for (int i = 0; i + 1 < n; ++i) {
            segs[i] = new Segment(i, l[i + 1] - r[i], r[i + 1] - l[i]);
        }
        Segment[] originalSegs = segs.clone();
        Arrays.sort(segs, new Comparator<Segment>() {
            public int compare(Segment o1, Segment o2) {
                return Long.compare(o1.min, o2.min);
            }
        });

        Bridge[] bridges = new Bridge[m];
        for (int i = 0; i < m; ++i) {
            bridges[i] = new Bridge(i + 1, in.nextLong());
        }

        Arrays.sort(bridges, new Comparator<Bridge>() {
            public int compare(Bridge o1, Bridge o2) {
                return Long.compare(o1.len, o2.len);
            }
        });

        TreeSet<Segment> available = new TreeSet<>();
        int ptr = 0;
        for (Bridge b : bridges) {
            while (ptr < segs.length && segs[ptr].min <= b.len) {
                available.add(segs[ptr++]);
            }
            if (!available.isEmpty()) {
                Segment s = available.pollFirst();
                if (s.max < b.len) {
                    out.println("No");
                    return;
                }
                s.assigned = b;
            }
        }

        if (ptr < segs.length || !available.isEmpty()) {
            out.println("No");
            return;
        }

        out.println("Yes");
        boolean first = true;
        for (Segment s : originalSegs) {
            if (first) first = false; else out.print(" ");
            out.print(s.assigned.index);
        }
        out.println();
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}