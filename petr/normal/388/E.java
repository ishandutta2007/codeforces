import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collection;
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
    static class Line {
        long[][] data = new long[2][3];
        long[] pr;
        Line nextSameDir = null;
        int kind = -1;

        Line(long[][] data) {
            this.data = data;
            pr = new long[3];
            for (int i = 0; i < 3; ++i) pr[i] = data[1][i] - data[0][i];
            long g = 0;
            for (int i = 0; i < 3; ++i) g = gcd(g, Math.abs(pr[i]));
            for (int i = 0; i < 3; ++i) if (pr[i] > 0) break; else if (pr[i] < 0) {
                g = -g;
                break;
            }
            for (int i = 0; i < 3; ++i) pr[i] /= g;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Line line = (Line) o;

            if (!Arrays.equals(pr, line.pr)) return false;

            return true;
        }

        public int hashCode() {
            return Arrays.hashCode(pr);
        }
    }

    static class Plane {
        long[] koef;
        Line i1;
        Line i2;
        Plane nextSameKoef;

        Plane(long[] koef, Line i1, Line i2) {
            this.koef = koef;
            this.i1 = i1;
            this.i2 = i2;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Plane plane = (Plane) o;

            if (!Arrays.equals(koef, plane.koef)) return false;

            return true;
        }

        public int hashCode() {
            return Arrays.hashCode(koef);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Line[] lines = new Line[n];
        HashMap<Line, Line> firstByDir = new HashMap<Line, Line>();
        for (int i = 0; i < n; ++i) {
            long[][] data = new long[2][3];
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 3; ++k)
                    data[j][k] = in.nextLong();
            lines[i] = new Line(data);
            lines[i].nextSameDir = firstByDir.get(lines[i]);
            firstByDir.put(lines[i], lines[i]);
        }
        int totalKinds = 0;
        for (Line line : firstByDir.values()) {
            while (line != null) {
                line.kind = totalKinds;
                line = line.nextSameDir;
            }
            ++totalKinds;
        }
        HashMap<Plane, Plane> firstByKoef = new HashMap<Plane, Plane>();
        for (int a = 0; a < n; ++a)
            for (int b = a + 1; b < n; ++b) {
                long[] koef = makePlane(lines[a].data, lines[b].data);
                if (koef == null) continue;
                Plane pl = new Plane(koef, lines[a], lines[b]);
                pl.nextSameKoef = firstByKoef.get(pl);
                firstByKoef.put(pl, pl);
                if (lines[a].kind != lines[b].kind) {
                    long[] outside = new long[3];
                    for (int i = 0; i < 3; ++i) if (koef[i] != 0) {
                        outside[i] = 1;
                        break;
                    }
                    long[] shifted = new long[3];
                    for (int i = 0; i < 3; ++i) shifted[i] = lines[a].data[0][i] + outside[i];
                    long[] orthogonal = makePlane(lines[a].data, new long[][]{lines[a].data[0], shifted});
                    if (orthogonal == null) throw new RuntimeException();
                    long atAlpha = 0;
                    long free = orthogonal[3];
                    for (int i = 0; i < 3; ++i) {
                        atAlpha += (lines[b].data[1][i] - lines[b].data[0][i]) * orthogonal[i];
                        free += lines[b].data[0][i] * orthogonal[i];
                    }
                    if (atAlpha == 0) throw new RuntimeException();
                    free = -free;
                    long g = gcd(Math.abs(atAlpha), Math.abs(free));
                    if (atAlpha < 0) g = -g;
                    atAlpha /= g;
                    free /= g;
                    long[] coords = new long[4];
                    for (int i = 0; i < 3; ++i) {
                        coords[i + 1] = lines[b].data[0][i] * atAlpha + free * (lines[b].data[1][i] - lines[b].data[0][i]);
                    }
                    coords[0] = atAlpha;
                    g = 0;
                    for (int i = 0; i < 4; ++i) g = gcd(g, Math.abs(coords[i]));
                    g = -g;
                    for (int i = 0; i < 4; ++i) coords[i] /= g;
                    Plane magic = new Plane(coords, lines[a], lines[b]);
                    magic.nextSameKoef = firstByKoef.get(magic);
                    firstByKoef.put(magic, magic);
                }
            }
        int[] generation = new int[totalKinds];
        int lastGen = 0;
        int res = 1;
        for (Plane first : firstByKoef.values()) {
            ++lastGen;
            int cur = 0;
            while (first != null) {
                if (generation[first.i1.kind] < lastGen) {
                    generation[first.i1.kind] = lastGen;
                    ++cur;
                }
                if (generation[first.i2.kind] < lastGen) {
                    generation[first.i2.kind] = lastGen;
                    ++cur;
                }
                first = first.nextSameKoef;
            }
            res = Math.max(res, cur);
        }
        out.println(res);
    }

    private long[] makePlane(long[][] a, long[][] b) {
        long[] v1 = new long[3];
        long[] v2 = new long[3];
        for (int i = 0; i < 3; ++i) {
            v1[i] = a[1][i] - a[0][i];
            v2[i] = b[0][i] - a[0][i];
        }
        long[] pr = prod(v1, v2);
        boolean allZero = true;
        for (int i = 0; i < 3; ++i) if (pr[i] != 0) allZero = false;
        if (allZero) {
            for (int i = 0; i < 3; ++i) {
                v2[i] = b[1][i] - a[0][i];
            }
            pr = prod(v1, v2);
            allZero = true;
            for (int i = 0; i < 3; ++i) if (pr[i] != 0) allZero = false;
            if (allZero) throw new RuntimeException();
        }
        long g = 0;
        for (int i = 0; i < 3; ++i) g = gcd(g, Math.abs(pr[i]));
        for (int i = 0; i < 3; ++i) if (pr[i] > 0) break; else if (pr[i] < 0) {
            g = -g;
            break;
        }
        for (int i = 0; i < 3; ++i) pr[i] /= g;
        for (int i = 0; i < 3; ++i) pr[3] -= pr[i] * a[0][i];
        if (!onside(pr, a[0]) || !onside(pr, a[1]) || !onside(pr, b[0]) || !onside(pr, b[1]))
            return null;
        return pr;
    }

    private boolean onside(long[] pr, long[] v) {
        long res = pr[3];
        for (int i = 0; i < 3; ++i) res += pr[i] * v[i];
        return res == 0;
    }

    private long[] prod(long[] v1, long[] v2) {
        long[] res = new long[4];
        for (int i = 0; i < 3; ++i) {
            int j = i + 1;
            if (j == 3) j = 0;
            int k = j + 1;
            if (k == 3) k = 0;
            res[i] = v1[j] * v2[k] - v1[k] * v2[j];
        }
        return res;
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
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