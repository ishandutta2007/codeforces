import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        long rx;
        long ry;
        long rz;
        boolean found;
        long[] min;
        long[] max;
        long[] left;
        long[] right;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            max = new long[4];
            min = new long[4];
            left = new long[4];
            right = new long[4];
            long[] coord = new long[4];
            Arrays.fill(min, Long.MAX_VALUE);
            Arrays.fill(max, Long.MIN_VALUE);
        /*long[] sx = new long[n];
        long[] sy = new long[n];
        long[] sz = new long[n];*/
            for (int i = 0; i < n; ++i) {
                long x = in.nextLong();
                long y = in.nextLong();
                long z = in.nextLong();
            /*sx[i] = x;
            sy[i] = y;
            sz[i] = z;*/
                coord[0] = x + y + z;
                coord[1] = x - y - z;
                coord[2] = x + y - z;
                coord[3] = x - y + z;
                for (int j = 0; j < 4; ++j) {
                    min[j] = Math.min(min[j], coord[j]);
                    max[j] = Math.max(max[j], coord[j]);
                }
            }
            long left = -1;
            long right = (long) 6.1e18;
            while (right > left + 1) {
                long middle = left + ((right - left) >> 1);
                find(min, max, middle);
                if (found) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            find(min, max, right);
        /*long got = 0;
        for (int i = 0; i < n; ++i) {
            long dist = Math.abs(sx[i] - rx) + Math.abs(sy[i] - ry) + Math.abs(sz[i] - rz);
            got = Math.max(dist, got);
        }
        if (got != right) throw new RuntimeException();*/
            out.println(rx + " " + ry + " " + rz);
            //out.println(right);
        }

        private void find(long[] min, long[] max, long maxDist) {
            found = false;
            outer:
            for (long mod2 = 0; mod2 < 2; ++mod2) {
                for (int j = 0; j < 4; ++j) {
                    long cleft = max[j] - maxDist;
                    long cright = min[j] + maxDist;
                    if ((cleft & 1) != mod2) ++cleft;
                    if ((cright & 1) != mod2) --cright;
                    if (cleft > cright) {
                        continue outer;
                    }
                    left[j] = (cleft - mod2) >> 1;
                    right[j] = (cright - mod2) >> 1;
                }
                long sleft = Math.max(left[0] + left[1], left[2] + left[3]);
                long sright = Math.min(right[0] + right[1], right[2] + right[3]);
                if (sleft <= sright) {
                    long e01 = sleft - left[0] - left[1];
                    left[1] += e01 - Math.min(e01, right[0] - left[0]);
                    left[0] += Math.min(e01, right[0] - left[0]);
                    long e23 = sleft - left[2] - left[3];
                    left[3] += e23 - Math.min(e23, right[2] - left[2]);
                    left[2] += Math.min(e23, right[2] - left[2]);
                    found = true;
                    rx = left[0] + left[1] + mod2;
                    ry = left[0] - left[3];
                    rz = left[0] - left[2];
                    return;
                }
            }
        }

    }

    static class InputReader {
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
}