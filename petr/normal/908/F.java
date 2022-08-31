import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            TaskF.Point[] pts = new TaskF.Point[n];
            for (int i = 0; i < n; ++i) {
                pts[i] = new TaskF.Point();
                pts[i].pos = in.nextInt();
                pts[i].kind = "GRB".indexOf(in.next().charAt(0));
            }
            Arrays.sort(pts, new Comparator<TaskF.Point>() {

                public int compare(TaskF.Point o1, TaskF.Point o2) {
                    return o1.pos - o2.pos;
                }
            });
            int prevGreen = -1;
            long res = 0;
            for (int i = 0; i < pts.length; ++i) {
                if (pts[i].kind == 0) {
                    if (prevGreen < 0) {
                        for (int j = 0; j < i; ++j) {
                            if (pts[j].kind == 1) {
                                res += pts[i].pos - pts[j].pos;
                                break;
                            }
                        }
                        for (int j = 0; j < i; ++j) {
                            if (pts[j].kind == 2) {
                                res += pts[i].pos - pts[j].pos;
                                break;
                            }
                        }
                    } else {
                        int prev = prevGreen;
                        int maxJump = 0;
                        for (int j = prevGreen + 1; j <= i; ++j) {
                            if (pts[j].kind != 1) {
                                int jump = pts[j].pos - pts[prev].pos;
                                maxJump = Math.max(maxJump, jump);
                                prev = j;
                            }
                        }
                        int maxJump2 = maxJump;
                        maxJump = 0;
                        prev = prevGreen;
                        for (int j = prevGreen + 1; j <= i; ++j) {
                            if (pts[j].kind != 2) {
                                int jump = pts[j].pos - pts[prev].pos;
                                maxJump = Math.max(maxJump, jump);
                                prev = j;
                            }
                        }
                        res += 2 * (pts[i].pos - pts[prevGreen].pos) - Math.max(0, maxJump + maxJump2 - (pts[i].pos - pts[prevGreen].pos));
                    }
                    prevGreen = i;
                }
            }
            if (prevGreen < 0) {
                for (int j = n - 1; j >= 0; --j) {
                    if (pts[j].kind == 1) {
                        res += pts[j].pos;
                        break;
                    }
                }
                for (int j = n - 1; j >= 0; --j) {
                    if (pts[j].kind == 2) {
                        res += pts[j].pos;
                        break;
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (pts[j].kind == 1) {
                        res += -pts[j].pos;
                        break;
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (pts[j].kind == 2) {
                        res += -pts[j].pos;
                        break;
                    }
                }
            } else {
                for (int j = n - 1; j > prevGreen; --j) {
                    if (pts[j].kind == 1) {
                        res += pts[j].pos - pts[prevGreen].pos;
                        break;
                    }
                }
                for (int j = n - 1; j > prevGreen; --j) {
                    if (pts[j].kind == 2) {
                        res += pts[j].pos - pts[prevGreen].pos;
                        break;
                    }
                }
            }
            out.println(res);
        }

        static class Point {
            int kind;
            int pos;

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