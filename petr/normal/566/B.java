import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            ArrayList<TaskB.Pair>[] a = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                a[i] = new ArrayList<>();
            for (int i = 0; i < 4 * n; ++i) {
                int z = in.nextInt() - 1;
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                a[x].add(new TaskB.Pair(y, z, i));
                a[y].add(new TaskB.Pair(x, z, i));
            }

            int[] inc = new int[n];
            int ind9 = -1;
            int pos = 0;
            int[] res = new int[4 * n];
            for (int it = 0; it < 4 * n; ++it) {
                int cur;
                if (ind9 == -1) {
                    while (a[pos].isEmpty()) ++pos;
                    cur = pos;
                } else {
                    cur = ind9;
                }

                TaskB.Pair entry = a[cur].get(0);
                a[cur].remove(0);
                int other = entry.x;
                int indOther = -1;
                for (int i = 0; i < a[other].size(); ++i)
                    if (a[other].get(i).x == cur && a[other].get(i).y == entry.y && a[other].get(i).ind == entry.ind) {
                        indOther = i;
                        break;
                    }
                if (indOther == -1)
                    throw new RuntimeException();
                a[other].remove(indOther);
                ++inc[entry.y];
                if (inc[entry.y] + a[entry.y].size() == 9)
                    ind9 = entry.y;
                else
                    ind9 = -1;
                res[entry.ind] = 4 * n - it - 1;
            }
            out.println("YES");
            int[] rev = new int[res.length];
            for (int i = 0; i < res.length; i++) {
                rev[res[i]] = i + 1;
            }
            for (int x : rev)
                out.print(x + " ");
            out.println();
        }

        static class Pair {
            int x;
            int y;
            int ind;

            public Pair(int x, int y, int ind) {
                this.x = x;
                this.y = y;
                this.ind = ind;
            }


            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                TaskB.Pair pair = (TaskB.Pair) o;

                if (x != pair.x) return false;
                return y == pair.y;

            }


            public int hashCode() {
                int result = x;
                result = 31 * result + y;
                return result;
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