import java.io.InputStream;
import java.io.InputStreamReader;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
    static class Intersector {
        long minxplusy = Long.MIN_VALUE;
        long maxxplusy = Long.MAX_VALUE;
        long minxminusy = Long.MIN_VALUE;
        long maxxminusy = Long.MAX_VALUE;

        void update(long kx, long ky, long a) {
            if (Math.abs(kx) != Math.abs(ky)) throw new RuntimeException();
            if (kx == 0) {
                if (a <= 0) return;
                minxplusy = Long.MAX_VALUE;
                maxxplusy = Long.MIN_VALUE;
                minxminusy = Long.MAX_VALUE;
                maxxminusy = Long.MIN_VALUE;
                return;
            }
            if (kx > 0) {
                if (ky > 0) {
                    maxxplusy = Math.min(maxxplusy, safeDivide(-a, kx));
                } else {
                    maxxminusy = Math.min(maxxminusy, safeDivide(-a, kx));
                }
            } else {
                if (ky < 0) {
                    minxplusy = Math.max(minxplusy, safeDivide(a + (-kx) - 1, -kx));
                } else {
                    minxminusy = Math.max(minxminusy, safeDivide(a + (-kx) - 1, -kx));
                }
            }
        }

        private long safeDivide(long a, long b) {
            if (a > 0) return a / b; else return (a - b + 1) / b;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        boolean[] know = new boolean[l + 1];
        long[] k = new long[l + 1];
        long[] ax = new long[l + 1];
        long[] ay = new long[l + 1];
        know[0] = true;
        know[l] = true;
        k[l] = 1;
        boolean knowP = false;
        long px = 0;
        long py = 0;
        for (int i = 0; i < n; ++i) {
            long t = in.nextLong();
            long x = in.nextLong();
            long y = in.nextLong();
            if ((x + y + t) % 2 != 0) {
                out.println("NO");
                return;
            }
            int when = (int) (t % l);
            long ck = -t / l;
            if (!know[when]) {
                know[when] = true;
                k[when] = ck;
                ax[when] = x;
                ay[when] = y;
            } else {
                if (knowP) {
                    if (k[when] * px + ax[when] != ck * px + x || Math.abs(k[when] * (double) px + ax[when] - ck * (double) px - x) > 1e62) {
                        out.println("NO");
                        return;
                    }
                    if (k[when] * py + ay[when] != ck * py + y || Math.abs(k[when] * (double) py + ay[when] - ck * (double) py - y) > 1e62) {
                        out.println("NO");
                        return;
                    }
                } else {
                    knowP = true;
                    long numx = x - ax[when];
                    long numy = y - ay[when];
                    long den = k[when] - ck;
                    if (numx % den != 0 || numy % den != 0) {
                        out.println("NO");
                        return;
                    }
                    px = numx / den;
                    py = numy / den;
                }
            }
        }

        {
            Intersector intersector = new Intersector();
            int prev = 0;
            for (int i = 1; i <= l; ++i) if (know[i]) {
                long dk = k[i] - k[prev];
                long dax = ax[i] - ax[prev];
                long day = ay[i] - ay[prev];
                for (int kx = -1; kx <= 1; kx += 2) {
                    for (int ky = -1; ky <= 1; ky += 2) {
                       intersector.update(kx * dk, ky * dk, kx * dax + ky * day - (i - prev));
                    }
                }
                prev = i;
            }
            if (knowP) {
                if (px + py < intersector.minxplusy || px + py > intersector.maxxplusy) {
                    out.println("NO");
                    return;
                }
                if (px - py < intersector.minxminusy || px - py > intersector.maxxminusy) {
                    out.println("NO");
                    return;
                }
                if ((px + py + l) % 2 != 0) {
                    out.println("NO");
                    return;
                }
            } else {
                if (intersector.minxplusy > intersector.maxxplusy) {
                    out.println("NO");
                    return;
                }
                if (intersector.minxminusy > intersector.maxxminusy) {
                    out.println("NO");
                    return;
                }
                long xplusy;
                if (intersector.minxplusy == Long.MIN_VALUE) {
                    if (intersector.maxxplusy == Long.MAX_VALUE) {
                        xplusy = 0;
                    } else {
                        xplusy = intersector.maxxplusy - 1;
                    }
                } else {
                    xplusy = intersector.minxplusy;
                }
                long xminusy;
                if (intersector.minxminusy == Long.MIN_VALUE) {
                    if (intersector.maxxminusy == Long.MAX_VALUE) {
                        xminusy = 0;
                    } else {
                        xminusy = intersector.maxxminusy - 1;
                    }
                } else {
                    xminusy = intersector.minxminusy;
                }
                if ((xplusy + l) % 2 != 0) {
                    if (xplusy < intersector.maxxplusy) {
                        ++xplusy;
                    } else {
                        out.println("NO");
                        return;
                    }
                }
                if ((xminusy + l) % 2 != 0) {
                    if (xminusy < intersector.maxxminusy) {
                        ++xminusy;
                    } else {
                        out.println("NO");
                        return;
                    }
                }
                px = (xplusy + xminusy) / 2;
                py = (xplusy - xminusy) / 2;
            }
        }

        int prev = 0;
        for (int i = 1; i <= l; ++i) if (know[i]) {
            long dk = k[i] - k[prev];
            long dax = ax[i] - ax[prev];
            long day = ay[i] - ay[prev];
            long dx = dk * px + dax;
            long dy = dk * py + day;
            if ((Math.abs(dx) + Math.abs(dy) > i - prev) || (Math.abs(dx) + Math.abs(dy) + (i - prev)) % 2 != 0) throw new RuntimeException();
            int extra = (int) ((i - prev - Math.abs(dx) - Math.abs(dy)) / 2);
            while (dx > 0) {
                out.print('R');
                --dx;
            }
            while (dx < 0) {
                out.print('L');
                ++dx;
            }
            while (dy > 0) {
                out.print('U');
                --dy;
            }
            while (dy < 0) {
                out.print('D');
                ++dy;
            }
            for (int j = 0; j < extra; ++j) {
                out.print("LR");
            }
            prev = i;
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