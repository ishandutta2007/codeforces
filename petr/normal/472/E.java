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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    private int ci;
    private int cj;
    private int reslen;
    private int[] resi;
    private int[] resj;
    private boolean[][] frozen;
    private int[][] di;
    private int[][] dj;
    private int[][] ri;
    private int[][] rj;
    private int[] wi;
    private int[] wj;
    private int[][] nexti;
    private int[][] nextj;
    private int[] seqi;
    private int[] seqj;
    private int nseq;
    private int si;
    private int sj;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] start = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                start[i][j] = in.nextInt();
        int[][] finish = new int[n][m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                finish[i][j] = in.nextInt();
        if (n == 1 || m == 1) {
            solveForOne(n, m, start, finish, out);
        } else {
            solveForMany(n, m, start, finish, out);
        }
    }

    int[][] start;
    int n;
    int m;


    private void solveForMany(int n, int m, int[][] start, int[][] finish, PrintWriter out) {
        this.n = n;
        this.m = m;
        this.start = start;
        di = new int[n][m];
        dj = new int[n][m];
        ri = new int[n][m];
        rj = new int[n][m];
        wi = new int[1000];
        wj = new int[1000];
        nexti = new int[n][m];
        nextj = new int[n][m];
        Arrays.fill(wi, -1);
        Arrays.fill(wj, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                nexti[i][j] = wi[finish[i][j]];
                nextj[i][j] = wj[finish[i][j]];
                wi[finish[i][j]] = i;
                wj[finish[i][j]] = j;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int zi = wi[start[i][j]];
                int zj = wj[start[i][j]];
                if (zi < 0) {
                    out.println(-1);
                    return;
                }
                ri[i][j] = zi;
                rj[i][j] = zj;
                di[zi][zj] = i;
                dj[zi][zj] = j;
                wi[start[i][j]] = nexti[zi][zj];
                wj[start[i][j]] = nextj[zi][zj];
            }
        }
        seqi = new int[n * m];
        seqj = new int[n * m];
        nseq = 0;
        si = 0;
        sj = 0;
        while (nseq < n * m) {
            if (n - si > m - sj) {
                for (int t = sj; t < m; ++t) {
                    seqi[nseq] = si;
                    seqj[nseq] = t;
                    ++nseq;
                }
                ++si;
                if (si > n) throw new RuntimeException();
            } else {
                for (int t = si; t < n; ++t) {
                    seqi[nseq] = t;
                    seqj[nseq] = sj;
                    ++nseq;
                }
                ++sj;
                if (sj > m) throw new RuntimeException();
            }
        }
        if (si < n && sj < m) throw new RuntimeException();
        ci = di[n - 1][m - 1];
        cj = dj[n - 1][m - 1];
        reslen = 1;
        resi = new int[(int) 1e6 + 10];
        resj = new int[(int) 1e6 + 10];
        resi[0] = ci;
        resj[0] = cj;
        frozen = new boolean[n][m];
        qi = new int[n * m];
        qj = new int[n * m];
        pi = new int[n][m];
        pj = new int[n][m];
        lastGeneration = 0;
        generation = new int[n][m];
        for (int seqpos = 0; seqpos < nseq - 1; ++seqpos) {
            int ti = seqi[seqpos];
            int tj = seqj[seqpos];
            while (ti != di[ti][tj] || tj != dj[ti][tj]) {
                si = di[ti][tj];
                sj = dj[ti][tj];
                frozen[si][sj] = true;
                int ni;
                int nj;
                if (Math.abs(si - ti) > Math.abs(sj - tj)) {
                    ni = si + sign(ti - si);
                    nj = sj;
                } else if (Math.abs(si - ti) < Math.abs(sj - tj)) {
                    ni = si;
                    nj = sj + sign(tj - sj);
                } else {
                    ni = si + sign(ti - si);
                    nj = sj + sign(tj - sj);
                }
                if (frozen[ni][nj]) throw new RuntimeException();
                moveTo(ni, nj);
                frozen[si][sj] = false;
                oneSwap(si, sj);
            }
            frozen[ti][tj] = true;
        }
        out.println(reslen - 1);
        for (int i = 0; i < reslen; ++i) {
            out.println((resi[i] + 1) + " " + (resj[i] + 1));
        }
    }

    private void oneSwap(int si, int sj) {
        if (frozen[ci][cj]) throw new RuntimeException();
        if (frozen[si][sj]) throw new RuntimeException();
        if (ci == si && cj == sj) throw new RuntimeException();
        if (Math.abs(ci - si) > 1 || Math.abs(cj - sj) > 1) throw new RuntimeException();
        int tmp = start[ci][cj];
        start[ci][cj] = start[si][sj];
        start[si][sj] = tmp;
        tmp = ri[ci][cj];
        ri[ci][cj] = ri[si][sj];
        ri[si][sj] = tmp;
        tmp = rj[ci][cj];
        rj[ci][cj] = rj[si][sj];
        rj[si][sj] = tmp;
        di[ri[ci][cj]][rj[ci][cj]] = ci;
        dj[ri[ci][cj]][rj[ci][cj]] = cj;
        di[ri[si][sj]][rj[si][sj]] = si;
        dj[ri[si][sj]][rj[si][sj]] = sj;
        ci = si;
        cj = sj;
        resi[reslen] = si;
        resj[reslen] = sj;
        ++reslen;
    }

    int[][] generation;
    int[] qi;
    int[] qj;
    int[][] pi;
    int[][] pj;
    int lastGeneration;

    private void moveTo(int ni, int nj) {
        int qt = 0;
        int qh = 1;
        qi[0] = ni;
        qj[0] = nj;
        ++lastGeneration;
        generation[ni][nj] = lastGeneration;
        pi[ni][nj] = -1;
        pj[ni][nj] = -1;
        while (generation[ci][cj] < lastGeneration) {
            if (qt == qh) throw new RuntimeException();
            ni = qi[qt];
            nj = qj[qt];
            ++qt;
            for (int di = -1; di <= 1; ++di)
                for (int dj = -1; dj <= 1; ++dj) {
                    int mi = ni + di;
                    int mj = nj + dj;
                    if (mi >= 0 && mi < n && mj >= 0 && mj < m && !frozen[mi][mj] && generation[mi][mj] < lastGeneration) {
                        generation[mi][mj] = lastGeneration;
                        pi[mi][mj] = ni;
                        pj[mi][mj] = nj;
                        qi[qh] = mi;
                        qj[qh] = mj;
                        ++qh;
                    }
                }
        }
        while (pi[ci][cj] >= 0) {
            oneSwap(pi[ci][cj], pj[ci][cj]);
        }
    }

    private void solveForOne(int n, int m, int[][] start, int[][] finish, PrintWriter out) {
        for (int si = 0; si < n; ++si)
            for (int sj = 0; sj < m; ++sj)
                for (int ti = 0; ti < n; ++ti)
                    outer: for (int tj = 0; tj < m; ++tj) {
                        int di = sign(ti - si);
                        int dj = sign(tj - sj);
                        if ((di == 0) ^ (dj == 0)) {
                            for (int ci = 0; ci < n; ++ci) {
                                for (int cj = 0; cj < m; ++cj) {
                                    int w;
                                    if (ci == ti && cj == tj) {
                                        w = start[si][sj];
                                    } else if (ci == si && cj == sj) {
                                        w = start[ci + di][cj + dj];
                                    } else if (ci <= si && cj <= sj && ci <= ti && cj <= tj) {
                                        w = start[ci][cj];
                                    } else if (ci >= si && cj >= sj && ci >= ti && cj >= tj) {
                                        w = start[ci][cj];
                                    } else {
                                        w = start[ci + di][cj + dj];
                                    }
                                    if (w != finish[ci][cj]) {
                                        continue outer;
                                    }
                                }
                            }
                            out.println(Math.abs(ti - si) + Math.abs(tj - sj));
                            out.println((si + 1) + " " + (sj + 1));
                            int ci = si;
                            int cj = sj;
                            do {
                                ci += di;
                                cj += dj;
                                out.println((ci + 1) + " " + (cj + 1));
                            } while (ci != ti || cj != tj);
                            return;
                        }
                    }
        out.println(-1);
    }

    private int sign(int x) {
        if (x == 0) return 0; else if (x > 0) return 1; else return -1;
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}