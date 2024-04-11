import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static class Contestant {
        int s;
        int r;
        Contestant nextSame;
        boolean canWin;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();

        Contestant[] contestants = new Contestant[n];
        for (int i = 0; i < n; ++i) {
            contestants[i] = new Contestant();
            contestants[i].s = in.nextInt();
            contestants[i].r = in.nextInt();
        }

        doit(contestants.clone());

        boolean first = true;
        for (int i = 0; i < n; ++i) if (contestants[i].canWin) {
            if (first) first = false; else out.print(" ");
            out.print(i + 1);
        }
        out.println();
    }

    private void doit(Contestant[] contestants) {
        Arrays.sort(contestants, new Comparator<Contestant>() {
            public int compare(Contestant o1, Contestant o2) {
                int z = o2.r - o1.r;
                if (z == 0) z = o2.s - o1.s;
                return z;
            }
        });
        int cnt = 0;
        for (int i = 0; i < contestants.length; ++i) {
            contestants[cnt++] = contestants[i];
            if (cnt >= 2 && contestants[cnt - 1].s <= contestants[cnt - 2].s) {
                if (contestants[cnt - 1].s == contestants[cnt - 2].s && contestants[cnt - 1].r == contestants[cnt - 2].r) {
                    contestants[cnt - 1].nextSame = contestants[cnt - 2];
                    contestants[cnt - 2] = contestants[cnt - 1];
                }
                --cnt;
            } else {
                while (cnt >= 3) {
                    Contestant a = contestants[cnt - 3];
                    Contestant b = contestants[cnt - 2];
                    Contestant c = contestants[cnt - 1];
                    if ((a.r - b.r) * (long) c.r * (b.s - c.s) * a.s - (a.s - b.s) * (long) c.s * (b.r - c.r) * a.r < 0) {
                        contestants[cnt - 2] = c;
                        --cnt;
                    } else {
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < cnt; ++i) {
            Contestant cur = contestants[i];
            while (cur != null) {
                cur.canWin = true;
                cur = cur.nextSame;
            }
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