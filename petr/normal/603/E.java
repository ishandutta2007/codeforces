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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int[] parent;
        int[] size;
        int[] changeLogSmall;
        int[] changeLogBig;
        int changeLogPtr;
        int numOdd;

        int get(int x) {
            while (true) {
                int y = parent[x];
                if (y == x) return y;
                x = y;
            }
        }

        void union(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) return;
            if ((size[x] & 1) != 0 && (size[y] & 1) != 0) numOdd -= 2;
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x];
                changeLogSmall[changeLogPtr] = x;
                changeLogBig[changeLogPtr] = y;
                ++changeLogPtr;
            } else {
                parent[y] = x;
                size[x] += size[y];
                changeLogSmall[changeLogPtr] = y;
                changeLogBig[changeLogPtr] = x;
                ++changeLogPtr;
            }
        }

        void undo(int toPtr) {
            while (changeLogPtr > toPtr) {
                --changeLogPtr;
                int small = changeLogSmall[changeLogPtr];
                int big = changeLogBig[changeLogPtr];
                parent[small] = small;
                size[big] -= size[small];
                if ((size[small] & 1) != 0 && (size[big] & 1) != 0) numOdd += 2;
            }
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Road[] byOrd = new Road[m];
            for (int i = 0; i < m; ++i) {
                byOrd[i] = new Road();
                byOrd[i].a = in.nextInt() - 1;
                byOrd[i].b = in.nextInt() - 1;
                byOrd[i].l = in.nextInt();
            }
            Road[] byLen = byOrd.clone();
            Arrays.sort(byLen, new Comparator<Road>() {

                public int compare(Road o1, Road o2) {
                    return Integer.compare(o1.l, o2.l);
                }
            });
            for (int i = 0; i < m; ++i) {
                byOrd[i].indexByOrd = i;
                byLen[i].indexByLen = i;
            }
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
            changeLogSmall = new int[n * 20];
            changeLogBig = new int[n * 20];
            changeLogPtr = 0;
            numOdd = n;
            solve(byOrd, byLen, 0, m, -1, m);
            for (Road r : byOrd) {
                int a = r.answer;
                if (a == m) out.println(-1);
                else out.println(byLen[a].l);
            }
        }

        private void solve(Road[] byOrd, Road[] byLen, int leftOrd, int rightOrd, int leftLen, int rightLen) {
            if (leftOrd == rightOrd) return;
            if (leftLen >= rightLen) {
                throw new RuntimeException();
            }
            if (leftLen + 1 == rightLen) {
                for (int i = leftOrd; i < rightOrd; ++i) {
                    byOrd[i].answer = rightLen;
                }
                return;
            }
            if (rightOrd - leftOrd >= rightLen - leftLen) {
                int midOrd = (leftOrd + rightOrd) / 2;
                int saved = changeLogPtr;
                for (int i = leftOrd + 1; i <= midOrd; ++i) {
                    Road r = byOrd[i];
                    if (r.indexByLen <= leftLen) {
                        union(r.a, r.b);
                    }
                }
                int midLen = leftLen;
                while (numOdd > 0) {
                    ++midLen;
                    if (midLen == rightLen) break;
                    Road r = byLen[midLen];
                    if (r.indexByOrd <= midOrd) {
                        union(r.a, r.b);
                    }
                }
                undo(saved);
                for (int i = leftOrd + 1; i <= midOrd; ++i) {
                    Road r = byOrd[i];
                    if (r.indexByLen <= leftLen) {
                        union(r.a, r.b);
                    }
                }
                solve(byOrd, byLen, midOrd, rightOrd, leftLen, midLen);
                undo(saved);
                for (int i = leftLen + 1; i < midLen && i < rightLen; ++i) {
                    Road r = byLen[i];
                    if (r.indexByOrd <= leftOrd) {
                        union(r.a, r.b);
                    }
                }
                solve(byOrd, byLen, leftOrd, midOrd, midLen - 1, rightLen);
                undo(saved);
            } else {
                int midLen = (leftLen + rightLen) / 2;
                int saved = changeLogPtr;
                for (int i = leftLen + 1; i <= midLen; ++i) {
                    Road r = byLen[i];
                    if (r.indexByOrd <= leftOrd) {
                        union(r.a, r.b);
                    }
                }
                int midOrd = leftOrd;
                while (numOdd > 0) {
                    ++midOrd;
                    if (midOrd == rightOrd) break;
                    Road r = byOrd[midOrd];
                    if (r.indexByLen <= midLen) {
                        union(r.a, r.b);
                    }
                }
                undo(saved);
                for (int i = leftOrd + 1; i <= midOrd && i < rightOrd; ++i) {
                    Road r = byOrd[i];
                    if (r.indexByLen <= leftLen) {
                        union(r.a, r.b);
                    }
                }
                solve(byOrd, byLen, midOrd, rightOrd, leftLen, midLen);
                undo(saved);
                for (int i = leftLen + 1; i <= midLen; ++i) {
                    Road r = byLen[i];
                    if (r.indexByOrd <= leftOrd) {
                        union(r.a, r.b);
                    }
                }
                solve(byOrd, byLen, leftOrd, midOrd, midLen, rightLen);
                undo(saved);
            }
        }

        static class Road {
            int a;
            int b;
            int l;
            int indexByOrd;
            int indexByLen;
            int answer;

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