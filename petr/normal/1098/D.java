import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            boolean[] adds = new boolean[q];
            int[] xs = new int[q];
            for (int qi = 0; qi < q; ++qi) {
                String kind = in.next();
                adds[qi] = kind.equals("+");
                xs[qi] = in.nextInt();
            }
            int[] sortedX = xs.clone();
            Random random = new Random(57341543531L + System.currentTimeMillis());
            for (int i = 0; i < q; ++i) {
                int j = random.nextInt(i + 1);
                int t = sortedX[i];
                sortedX[i] = sortedX[j];
                sortedX[j] = t;
            }
            Arrays.sort(sortedX);
            int cnt = 0;
            for (int i = 0; i < sortedX.length; ++i) {
                if (i == 0 || sortedX[i] > sortedX[i - 1]) {
                    sortedX[cnt++] = sortedX[i];
                }
            }
            sortedX = Arrays.copyOf(sortedX, cnt);

            TaskD.Fenwick fenwick = new TaskD.Fenwick(sortedX.length);
            TaskD.Fenwick fenwick2 = new TaskD.Fenwick(sortedX.length);

            int total = 0;

            for (int qi = 0; qi < q; ++qi) {
                int xValue = xs[qi];
                int xPos = Arrays.binarySearch(sortedX, xValue);
                if (adds[qi]) {
                    fenwick.upd(xPos, xValue);
                    fenwick2.upd(sortedX.length - 1 - xPos, 1);
                    ++total;
                } else {
                    fenwick.upd(xPos, -xValue);
                    fenwick2.upd(sortedX.length - 1 - xPos, -1);
                    --total;
                }
                int gaps = 0;
                int at = sortedX.length - 1 - fenwick2.findPrevNonZero(sortedX.length - 1);
                if (at < sortedX.length) {
                    long sum = fenwick.get(at);
                    while (at + 1 < sortedX.length) {
                        int left = at;
                        int right = sortedX.length;
                        while (right - left > 1) {
                            int middle = (left + right) >> 1;
                            if (sortedX[middle] <= 2 * sum) {
                                left = middle;
                            } else {
                                right = middle;
                            }
                        }
                        int next = sortedX.length - 1 - fenwick2.findPrevNonZero(sortedX.length - 1 - right);
                        if (next >= sortedX.length) break;
                        at = left;
                        sum = fenwick.get(at);
                        if (2 * sum < sortedX[next]) {
                            ++gaps;
                        }
                        sum += fenwick.val[next];
                        at = next;
                    }
                }
                out.println(Math.max(0, total - 1 - gaps));
            }
        }

        static class Fenwick {
            long[] a;
            long[] val;

            public Fenwick(int n) {
                a = new long[n];
                val = new long[n];
            }

            void upd(int at, long by) {
                val[at] += by;
                while (at < a.length) {
                    a[at] += by;
                    at |= at + 1;
                }
            }

            long get(int upto) {
                long res = 0;
                while (upto >= 0) {
                    res += a[upto];
                    upto = (upto & (upto + 1)) - 1;
                }
                return res;
            }

            int findPrevNonZero(int upto) {
                while (upto >= 0 && val[upto] == 0) {
                    if (a[upto] == 0) {
                        upto = (upto & (upto + 1)) - 1;
                    } else {
                        --upto;
                    }
                }
                return upto;
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

    }
}