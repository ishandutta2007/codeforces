import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
    static class Building {
        long v;
        long c;

        Building(long v, long c) {
            this.v = v;
            this.c = c;
        }
    }

    static class Segment {
        long start;
        long v;
        long extra;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long s = in.nextLong();
        Building[] b = new Building[n];
        for (int i = 0; i < n; ++i) {
            long v = in.nextLong();
            long c = in.nextLong();
            b[i] = new Building(v, c);
        }
        Segment[] seg = new Segment[n + 1];
        for (int i = 0; i < seg.length; ++i) {
            seg[i] = new Segment();
        }
        seg[0].start = 0;
        seg[0].v = 0;
        seg[0].extra = 0;
        int sp = 1;
        Arrays.sort(b, new Comparator<Building>() {
            @Override
            public int compare(Building o1, Building o2) {
                int z = Long.compare(o1.v, o2.v);
                if (z == 0) z = Long.compare(o1.c, o2.c);
                return z;
            }
        });
        long lastv = -1;
        for (Building building : b) {
            if (building.v == lastv) continue;
            lastv = building.v;
            int left = 0;
            int right = sp;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (seg[middle].extra < building.c) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            if (seg[left].extra < building.c && seg[left].v == 0) continue;
            long when;
            if (seg[left].v == 0)
                when = 0;
            else
                when = (building.c - seg[left].extra + seg[left].v - 1) / seg[left].v;
            long start;
            long extra;
            if (right < sp && seg[left].start + when >= seg[right].start) {
                start = seg[right].start;
                extra = seg[right].extra - building.c;
            } else {
                start = seg[left].start + when;
                extra = seg[left].extra + when * seg[left].v - building.c;
            }
            if (extra < 0) throw new RuntimeException();
            while (sp > 0) {
                if (seg[sp - 1].start < start) break;
                if (seg[sp - 1].extra > extra + mul(building.v, seg[sp - 1].start - start)) break;
                --sp;
            }
            if (sp == 0) {
                seg[sp].start = start;
                seg[sp].extra = extra;
                seg[sp].v = building.v;
                ++sp;
            } else if (seg[sp - 1].start < start) {
                long got = seg[sp - 1].extra + mul(seg[sp - 1].v, start - seg[sp - 1].start);
                if (got <= extra) {
                    seg[sp].start = start;
                    seg[sp].extra = extra;
                    seg[sp].v = building.v;
                    ++sp;
                } else if (got - seg[sp - 1].v < s) {
                    long gap = got - extra;
                    long speed = building.v - seg[sp - 1].v;
                    long time = (gap + speed - 1) / speed;
                    if (got + mul((time - 1), seg[sp - 1].v) < s) {
                        seg[sp].start = start + time;
                        seg[sp].extra = extra + time * building.v;
                        seg[sp].v = building.v;
                        ++sp;
                    }
                }
            } else {
                long got = extra + mul(building.v, seg[sp - 1].start - start); 
                long gap = seg[sp - 1].extra - got;
                long speed = building.v - seg[sp - 1].v;
                long time = (gap + speed - 1) / speed;
                if (seg[sp - 1].extra + mul((time - 1), seg[sp - 1].v) < s) {
                    seg[sp].start = seg[sp - 1].start + time;
                    seg[sp].extra = got + time * building.v;
                    seg[sp].v = building.v;
                    ++sp;
                }
            }
        }
        long res = INF;
        for (int i = 0; i < sp; ++i) {
            if (seg[i].extra >= s) {
                res = Math.min(res, seg[i].start);
            } else if (seg[i].v > 0) {
                res = Math.min(res, seg[i].start + (s - seg[i].extra + seg[i].v - 1) / seg[i].v);
            }
        }
        out.println(res);
    }

    static final long INF = (long) 1.1e16;

    private long mul(long a, long b) {
        if (a == 0 || b == 0) return 0;
        if (a > INF / b) return INF;
        return a * b;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }