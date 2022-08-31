import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Domino implements Runnable {
    int[][] adj;
    int[] res;
    int[] cur;
    int[] rem;
    int numTwos;
    long numRes;
    int[] have;
    int[][] field;
    int[][] sfield;

    private void solve() throws IOException {
        int height = nextInt();
        int width = nextInt();
        int[][] field = new int[height][width];
        this.field = field;
        for (int r = 0; r < height; ++r) {
            String s = nextToken();
            for (int c = 0; c < width; ++c) {
                char ch = s.charAt(c);
                if (ch >= 'a' && ch <= 'z')
                    field[r][c] = ch - 'a';
                else if (ch >= 'A' && ch <= 'B')
                    field[r][c] = 26 + ch - 'A';
                else
                    field[r][c] = -1;
            }
        }
        int[][] sfield = new int[height][width];
        this.sfield = sfield;
        for (int r = 0; r < height; ++r) sfield[r] = field[r].clone();
        int[][] pairs = new int[28][2];
        for (int i = 0; i < 28; ++i)
            Arrays.fill(pairs[i], -1);
        int id = 0;
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                if (field[r][c] >= 0) {
                    process(field, r, c, id, pairs);
                    process(field, r + 1, c, id, pairs);
                    process(field, r, c + 1, id, pairs);
                    process(field, r + 1, c + 1, id, pairs);
                    ++id;
                }
        if (id != 14) throw new RuntimeException();
        int[] nadj = new int[14];
        for (int i = 0; i < 28; ++i) {
            ++nadj[pairs[i][0]];
            if (pairs[i][0] != pairs[i][1]) ++nadj[pairs[i][1]];
        }
        adj = new int[14][];
        for (int i = 0; i < 14; ++i) adj[i] = new int[nadj[i]];
        Arrays.fill(nadj, 0);
        for (int i = 0; i < 28; ++i) {
            adj[pairs[i][0]][nadj[pairs[i][0]]++] = pairs[i][1];
            if (pairs[i][0] != pairs[i][1]) adj[pairs[i][1]][nadj[pairs[i][1]]++] = pairs[i][0];
        }
        have = new int[7 * 7];
        cur = new int[14];
        rem = new int[7];
        Arrays.fill(rem, 2);
        numRes = 0;
        numTwos = 7;
        rec(0, 1);
        writer.println(numRes);
        if (numRes == 0) while (true);
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                if (field[r][c] <= -2)
                    field[r][c] = res[-field[r][c] - 2];
        int[][] hh = new int[7][7];
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                for (int rr = 0; rr < height; ++rr)
                    for (int cc = 0; cc < width; ++cc)
                        if ((rr != r) || (cc != c))
                            if (sfield[rr][cc] == sfield[r][c] && sfield[rr][cc] >= 0) {
                                ++hh[field[rr][cc]][field[r][c]];
                                ++hh[field[r][c]][field[rr][cc]];
                            }
        for (int i = 0; i < 7; ++i)
            for (int j = 0; j < 7; ++j) {
                int need = (i == j) ? 4 : 2;
                if (need != hh[i][j]) throw new RuntimeException();
            }
        for (int r = 0; r < height; ++r) {
            for (int c = 0; c < width; ++c)
                if (field[r][c] < 0) writer.print("."); else writer.print(field[r][c]);
            writer.println();
        }
    }

    void verify() {
        int height = field.length;
        int width = field[0].length;
        int[][] field = new int[height][width];
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                field[r][c] = this.field[r][c];
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                if (field[r][c] <= -2)
                    field[r][c] = cur[-field[r][c] - 2];
        int[][] hh = new int[7][7];
        for (int r = 0; r < height; ++r)
            for (int c = 0; c < width; ++c)
                for (int rr = 0; rr < height; ++rr)
                    for (int cc = 0; cc < width; ++cc)
                        if ((rr != r) || (cc != c))
                            if (sfield[rr][cc] == sfield[r][c] && sfield[rr][cc] >= 0) {
                                ++hh[field[rr][cc]][field[r][c]];
                                ++hh[field[r][c]][field[rr][cc]];
                            }
        for (int i = 0; i < 7; ++i)
            for (int j = 0; j < 7; ++j) {
                int need = (i == j) ? 4 : 2;
                if (need != hh[i][j]) throw new RuntimeException();
            }

    }

    private void rec(int at, long toAdd) {
        if (at >= 14) {
            if (res == null)
                res = cur.clone();
            numRes += toAdd;
            //verify();
            return;
        }
        boolean hadTwo = false;
        for (int what = 0; what < 7; ++what) {
            if (rem[what] <= 0) continue;
            long nToAdd = toAdd;
            if (rem[what] == 2) {
                if (hadTwo) continue;
                hadTwo = true;
                nToAdd *= numTwos;
            }
            cur[at] = what;
            boolean ok = true;
            for (int x : adj[at])
                if (x <= at) {
                    ++have[what * 7 + cur[x]];
                    if (cur[x] != what)
                    ++have[cur[x] * 7 + what];
                }
            for (int x : adj[at])
                if (x <= at) {
                    if (have[what * 7 + cur[x]] > 1) ok = false;
                }
            if (ok) {
            if (rem[what] == 2) --numTwos;
            --rem[what];
            rec(at + 1, nToAdd);
            ++rem[what];
            if (rem[what] == 2) ++numTwos;
            }
            for (int x : adj[at])
                if (x <= at) {
                    --have[what * 7 + cur[x]];
                    if (cur[x] != what)
                    --have[cur[x] * 7 + what];
                }
        }
    }

    private void process(int[][] field, int r, int c, int id, int[][] pairs) {
        if (field[r][c] < 0) throw new RuntimeException();
        int what = field[r][c];
        field[r][c] = -(id + 2);
        if (pairs[what][0] < 0) {
            pairs[what][0] = id;
        } else if (pairs[what][1] < 0) {
            pairs[what][1] = id;
        } else {
            throw new RuntimeException();
        }
    }

    public static void main(String[] args) {
        new Domino().run();
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