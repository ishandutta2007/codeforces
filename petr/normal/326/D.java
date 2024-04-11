import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Rectangle {
        int x1;
        int y1;
        int x2;
        int y2;
        Rectangle nextStart;
        Rectangle nextEnd;
    }

    static class Description {
        int[][] angleSum;
        int[][] maxValid;
    }

    static class Candidate {
        int x = -1;
        int y = -1;
        Candidate nextAll;
        Candidate prevAll;
        Candidate nextElim;
        Candidate prevElim;
    }

    static final int SIZE = 3000;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Rectangle[] r = new Rectangle[n];
        for (int i = 0; i < n; ++i) {
            r[i] = new Rectangle();
            r[i].x1 = in.nextInt();
            r[i].y1 = in.nextInt();
            r[i].x2 = in.nextInt();
            r[i].y2 = in.nextInt();
        }
        /*n = 100000;
        r = new Rectangle[n];
        for (int i = 0; i < n; ++i) {
            r[i] = new Rectangle();
            r[i].x1 = i % 1000;
            r[i].y1 = i / 1000;
            r[i].x2 = r[i].x1 + 1;
            r[i].y2 = r[i].y1 + 1;
        }*/
        Description dNormal = describe(r, true);
        Rectangle[] rInv = new Rectangle[n];
        for (int i = 0; i < n; ++i) {
            rInv[i] = new Rectangle();
            rInv[i].x1 = SIZE - r[i].x2;
            rInv[i].y1 = SIZE - r[i].y2;
            rInv[i].x2 = SIZE - r[i].x1;
            rInv[i].y2 = SIZE - r[i].y1;
        }
        Description dInv = describe(rInv, false);
        Candidate sentinel = new Candidate();
        Candidate[] sentinelElim = new Candidate[SIZE + 1];
        for (int i = 0; i <= SIZE; ++i) {
            sentinelElim[i] = new Candidate();
        }
        Candidate[] candidateByX = new Candidate[SIZE + 1];
        for (int diag = -(SIZE - 1); diag <= SIZE - 1; ++diag) {
            sentinel.nextAll = sentinel;
            sentinel.prevAll = sentinel;
            for (int i = 0; i <= SIZE; ++i) {
                sentinelElim[i].nextElim = sentinelElim[i];
                sentinelElim[i].prevElim = sentinelElim[i];
            }
            int sx;
            int sy;
            int ex;
            int ey;
            if (diag >= 0) {
                sx = diag;
                sy = 0;
                ex = SIZE;
                ey = SIZE - diag;
            } else {
                sx = 0;
                sy = -diag;
                ex = SIZE + diag;
                ey = SIZE;
            }
            int maxx = ex;
            Arrays.fill(candidateByX, null);
            for (int x = ex, y = ey; x >= sx; --x, --y) {
                while (dNormal.angleSum[maxx][maxx - x + y] - dNormal.angleSum[maxx][y] - dNormal.angleSum[x][maxx - x + y] + dNormal.angleSum[x][y] != (maxx - x) * (maxx - x)) {
                    if (candidateByX[maxx] != null) {
                        Candidate cur = candidateByX[maxx];
                        cur.prevElim.nextElim = cur.nextElim;
                        cur.nextElim.prevElim = cur.prevElim;
                        cur.nextAll.prevAll = cur.prevAll;
                        cur.prevAll.nextAll = cur.nextAll;
                        candidateByX[cur.x] = null;
                    }
                    --maxx;
                }
                if (sentinel.nextAll != sentinel && sentinel.nextAll.x - x <= dNormal.maxValid[x][y]) {
                    outputSolution(out, r, x, y, sentinel.nextAll.x, sentinel.nextAll.y);
                    return;
                }
                Candidate se = sentinelElim[x];
                Candidate cur = se.nextElim;
                while (cur != se) {
                    cur.prevElim.nextElim = cur.nextElim;
                    cur.nextElim.prevElim = cur.prevElim;
                    cur.nextAll.prevAll = cur.prevAll;
                    cur.prevAll.nextAll = cur.nextAll;
                    candidateByX[cur.x] = null;
                    cur = cur.nextElim;
                }
                int maxInv = dInv.maxValid[SIZE - x][SIZE - y];
                if (maxInv > 0) {
                    candidateByX[x] = new Candidate();
                    candidateByX[x].x = x;
                    candidateByX[x].y = y;
                    candidateByX[x].nextAll = sentinel.nextAll;
                    candidateByX[x].prevAll = sentinel;
                    candidateByX[x].prevAll.nextAll = candidateByX[x];
                    candidateByX[x].nextAll.prevAll = candidateByX[x];
                    candidateByX[x].nextElim = sentinelElim[x - maxInv].nextElim;
                    candidateByX[x].prevElim = sentinelElim[x - maxInv];
                    candidateByX[x].prevElim.nextElim = candidateByX[x];
                    candidateByX[x].nextElim.prevElim = candidateByX[x];
                }
            }
        }
        out.println("NO");
    }

    private void outputSolution(PrintWriter out, Rectangle[] r, int x1, int y1, int x2, int y2) {
        out.print("YES ");
        int count = 0;
        for (Rectangle rect : r)
            if (rect.x1 >= x1 && rect.y1 >= y1 && rect.x2 <= x2 && rect.y2 <= y2)
                ++count;
        out.println(count);
        count = 0;
        int index = 0;
        for (Rectangle rect : r) {
            ++index;
            if (rect.x1 >= x1 && rect.y1 >= y1 && rect.x2 <= x2 && rect.y2 <= y2) {
                if (count > 0) out.print(" ");
                ++count;
                out.print(index);
            }
        }
        out.println();
    }

    private Description describe(Rectangle[] r, boolean needAngle) {
        Description desc = new Description();
        if (needAngle) {
            int[][] angleSum = new int[SIZE + 1][SIZE + 1];
            for (Rectangle rect : r)
                for (int x = rect.x1; x < rect.x2; ++x)
                    for (int y = rect.y1; y < rect.y2; ++y) {
                        ++angleSum[x + 1][y + 1];
                    }
            for (int x = 1; x <= SIZE; ++x)
                for (int y = 1; y <= SIZE; ++y)
                    angleSum[x][y] = angleSum[x][y] + angleSum[x - 1][y] + angleSum[x][y - 1] - angleSum[x - 1][y - 1];
            desc.angleSum = angleSum;
        }
        int[][] maxValid = new int[SIZE + 1][SIZE + 1];
        for (int x = 0; x < SIZE; ++x)
            for (int y = 0; y < SIZE; ++y)
                maxValid[x][y] = 0;
        for (Rectangle rect : r)
           maxValid[rect.x1][rect.y1] = Math.min(SIZE - rect.x1, SIZE - rect.y1);
        {
            Rectangle[] firstStart = new Rectangle[SIZE + 1];
            Rectangle[] firstEnd = new Rectangle[SIZE + 1];
            for (Rectangle rect : r) {
                rect.nextStart = firstStart[rect.y1 + 1];
                firstStart[rect.y1 + 1] = rect;
                rect.nextEnd = firstEnd[rect.y2];
                firstEnd[rect.y2] = rect;
            }
            int[] numBad = new int[SIZE + 1];
            for (int y = 0; y < SIZE; ++y) {
                Rectangle cr = firstStart[y];
                while (cr != null) {
                    ++numBad[cr.x1];
                    cr = cr.nextStart;
                }
                cr = firstEnd[y];
                while (cr != null) {
                    --numBad[cr.x1];
                    cr = cr.nextEnd;
                }
                int mxx = SIZE;
                for (int x = SIZE - 1; x >= 0; --x) {
                    if (numBad[x] > 0) mxx = x;
                    maxValid[x][y] = Math.min(maxValid[x][y], mxx - x);
                }
            }
        }
        {
            Rectangle[] firstStart = new Rectangle[SIZE + 1];
            Rectangle[] firstEnd = new Rectangle[SIZE + 1];
            for (Rectangle rect : r) {
                rect.nextStart = firstStart[rect.x1 + 1];
                firstStart[rect.x1 + 1] = rect;
                rect.nextEnd = firstEnd[rect.x2];
                firstEnd[rect.x2] = rect;
            }
            int[] numBad = new int[SIZE + 1];
            for (int x = 0; x < SIZE; ++x) {
                Rectangle cr = firstStart[x];
                while (cr != null) {
                    ++numBad[cr.y1];
                    cr = cr.nextStart;
                }
                cr = firstEnd[x];
                while (cr != null) {
                    --numBad[cr.y1];
                    cr = cr.nextEnd;
                }
                int mxy = SIZE;
                for (int y = SIZE - 1; y >= 0; --y) {
                    if (numBad[y] > 0) mxy = y;
                    maxValid[x][y] = Math.min(maxValid[x][y], mxy - y);
                }
            }
        }
        desc.maxValid = maxValid;
        return desc;
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