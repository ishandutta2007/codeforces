import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.Collections;
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
        TaskG1 solver = new TaskG1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG1 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            in.nextInt();
            int[] a = new int[n];
            int maxa = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                maxa = Math.max(maxa, a[i] + 1);
            }
            int[] first = new int[maxa];
            int[] last = new int[maxa];
            int[] count = new int[maxa];
            Arrays.fill(first, n);
            Arrays.fill(last, -1);
            for (int i = 0; i < n; ++i) {
                int d = a[i];
                first[d] = Math.min(first[d], i);
                last[d] = Math.max(last[d], i);
                ++count[d];
            }
            List<TaskG1.Value> vals = new ArrayList<>();
            for (int i = 0; i < first.length; ++i)
                if (first[i] <= last[i]) {
                    vals.add(new TaskG1.Value(first[i], last[i], count[i]));
                }
            Collections.sort(vals, new Comparator<TaskG1.Value>() {

                public int compare(TaskG1.Value o1, TaskG1.Value o2) {
                    return o1.left - o2.left;
                }
            });
            int[] max = new int[vals.size() + 1];
            int[] min = new int[vals.size() + 1];
            min[0] = n;
            for (int i = 0; i < vals.size(); ++i) {
                max[i + 1] = Math.max(max[i], vals.get(i).right);
                min[i + 1] = Math.min(min[i], vals.get(vals.size() - 1 - i).left);
            }
            int prev = 0;
            int res = n;
            for (int i = 1; i <= vals.size(); ++i) {
                if (max[i] < min[vals.size() - i]) {
                    int mc = 0;
                    for (int j = prev; j < i; ++j) {
                        mc = Math.max(mc, vals.get(j).am);
                    }
                    res -= mc;
                    prev = i;
                }
            }
            out.println(res);
        }

        static class Value {
            int left;
            int right;
            int am;

            public Value(int left, int right, int am) {
                this.left = left;
                this.right = right;
                this.am = am;
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