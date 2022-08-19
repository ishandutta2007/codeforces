import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static class Cut implements Comparable<Cut> {
        int kind;
        int x1;
        int y1;
        int x2;
        int y2;

        Cut(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            if (x1 == x2) kind = 1; else kind = 2;
            if (x1 >= x2 && y1 >= y2) {
                this.x1 = x2;
                this.y1 = y2;
                this.x2 = x1;
                this.y2 = y1;
            }
        }

        public int compareTo(Cut o) {
            if (kind != o.kind) return kind - o.kind;
            if (kind == 1) {
                if (x1 != o.x1) return x1 - o.x1;
                return y1 - o.y1;
            } else {
                if (y1 != o.y1) return y1 - o.y1;
                return x1 - o.x1;
            }
        }
    }

    static class LineDesc {
        List<Cut> cuts = new ArrayList<Cut>(0);
        int totalLen;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int maxx = in.nextInt();
        int maxy = in.nextInt();
        int k = in.nextInt();
        Cut[] cuts = new Cut[k];
        for (int i = 0; i < k; ++i) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            cuts[i] = new Cut(x1, y1, x2, y2);
        }
        Random random = new Random(543715431531L);
        for (int i = 0; i <  k; ++i) {
            int j = i + random.nextInt(k - i);
            Cut tmp = cuts[i];
            cuts[i] = cuts[j];
            cuts[j] = tmp;
        }
        Arrays.sort(cuts);
        List<LineDesc> remains = new ArrayList<LineDesc>();
        int[] cnt = new int[3];
        boolean[] usedx = new boolean[k + 2];
        boolean[] usedy = new boolean[k + 2];
        int i = 0;
        while (i < cuts.length) {
            ++cnt[cuts[i].kind];
            int j = i;
            LineDesc cur = new LineDesc();
            if (cuts[i].kind == 1) {
                if (cuts[i].x1 < usedx.length) usedx[cuts[i].x1] = true;
                while (j < cuts.length && cuts[j].kind == cuts[i].kind && cuts[j].x1 == cuts[i].x1) ++j;
                int rightmost = 0;
                for (int t = i; t < j; ++t) {
                    if (cuts[t].y1 > rightmost) {
                        cur.cuts.add(new Cut(cuts[i].x1, rightmost, cuts[i].x1, cuts[t].y1));
                    }
                    rightmost = Math.max(rightmost, cuts[t].y2);
                }
                if (maxy > rightmost) {
                    cur.cuts.add(new Cut(cuts[i].x1, rightmost, cuts[i].x1, maxy));
                }
            } else {
                if (cuts[i].y1 < usedy.length) usedy[cuts[i].y1] = true;
                while (j < cuts.length && cuts[j].kind == cuts[i].kind && cuts[j].y1 == cuts[i].y1) ++j;
                int rightmost = 0;
                for (int t = i; t < j; ++t) {
                    if (cuts[t].x1 > rightmost) {
                        cur.cuts.add(new Cut(rightmost, cuts[i].y1, cuts[t].x1, cuts[i].y1));
                    }
                    rightmost = Math.max(rightmost, cuts[t].x2);
                }
                if (maxx > rightmost) {
                    cur.cuts.add(new Cut(rightmost, cuts[i].y1, maxx, cuts[i].y1));
                }
            }
            remains.add(cur);
            i = j;
        }
        int grundy = 0;
        for (LineDesc l : remains) {
            l.totalLen = 0;
            for (Cut x : l.cuts)
                l.totalLen += Math.abs(x.x1 - x.x2) + Math.abs(x.y1 - x.y2);
            grundy ^= l.totalLen;
        }
        for (i = 1; i < maxx; ++i)
            if (!usedx[i]) {
                LineDesc cur = new LineDesc();
                cur.cuts.add(new Cut(i, 0, i, maxy));
                cur.totalLen = maxy;
                remains.add(cur);
                if ((maxx - 1 - cnt[1]) % 2 != 0)
                    grundy ^= maxy;
                break;
            }
        for (i = 1; i < maxy; ++i)
            if (!usedy[i]) {
                LineDesc cur = new LineDesc();
                cur.cuts.add(new Cut(0, i, maxx, i));
                cur.totalLen = maxx;
                remains.add(cur);
                if ((maxy - 1 - cnt[2]) % 2 != 0)
                    grundy ^= maxx;
                break;
            }
        if (grundy == 0) {
            out.println("SECOND");
        } else {
            out.println("FIRST");
            for (LineDesc l : remains) {
                int len = l.totalLen;
                int need = len ^ grundy;
                if (need < len) {
                    int sx;
                    int sy;
                    int dx;
                    int dy;
                    if (l.cuts.get(0).kind == 1) {
                        sx = l.cuts.get(0).x1;
                        sy = 0;
                        dx = 0;
                        dy = 1;
                    } else {
                        sx = 0;
                        sy = l.cuts.get(0).y1;
                        dx = 1;
                        dy = 0;
                    }
                    int toKill = len - need;
                    int rightmost = -1;
                    for (Cut x : l.cuts) {
                        int thisLen = Math.abs(x.x1 - x.x2) + Math.abs(x.y1 - x.y2);
                        if (thisLen >= toKill) {
                            rightmost = (x.x1 - sx) + (x.y1 - sy) + toKill;
                            break;
                        }
                        toKill -= thisLen;
                    }
                    if (rightmost < 0) throw new RuntimeException();
                    out.println(sx + " " + sy + " " + (sx + rightmost * dx) + " " + (sy + rightmost * dy));
                    break;
                }
            }
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