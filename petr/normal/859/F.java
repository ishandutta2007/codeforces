import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
            long C = in.nextLong();
            long[] s = new long[2 * n - 1];
            for (int i = 0; i < s.length; ++i) s[i] = in.nextLong();
            long res = 0;
            long totalDelta = 0;
            long balanceDelta = 0;
            TreeSet<TaskF.Segment> byTotal = new TreeSet<>(new Comparator<TaskF.Segment>() {

                public int compare(TaskF.Segment o1, TaskF.Segment o2) {
                    int z = Long.compare(o1.total, o2.total);
                    if (z == 0) z = Integer.compare(o1.index, o2.index);
                    return z;
                }
            });
            TreeSet<TaskF.Segment> byBalance = new TreeSet<>(new Comparator<TaskF.Segment>() {

                public int compare(TaskF.Segment o1, TaskF.Segment o2) {
                    int z = Long.compare(o1.balance, o2.balance);
                    if (z == 0) z = Integer.compare(o1.index, o2.index);
                    return z;
                }
            });
            for (int i = 0; i < n; ++i) {
                long minBalance = 0;
                if (i > 0) {
                    long extraTotal = s[2 * i] + s[2 * i - 1];
                    while (!byTotal.isEmpty()) {
                        TaskF.Segment seg = byTotal.last();
                        if (seg.total + totalDelta + extraTotal < C) break;
                        byTotal.remove(seg);
                        byBalance.remove(seg);
                        long newBalance = (seg.balance + balanceDelta) - (C - (seg.total + totalDelta));
                        minBalance = Math.min(minBalance, newBalance);
                    }
                    if (!byBalance.isEmpty()) {
                        TaskF.Segment seg = byBalance.first();
                        long newBalance = (seg.balance + balanceDelta) - extraTotal;
                        minBalance = Math.min(minBalance, newBalance);
                    }
                    totalDelta += extraTotal;
                    balanceDelta -= extraTotal;
                }
                minBalance = Math.min(minBalance, -Math.min(C, s[2 * i]));
                long putHere = -minBalance;
                res += putHere;
                balanceDelta += putHere;
                if (s[2 * i] < C) {
                    TaskF.Segment seg = new TaskF.Segment(i, s[2 * i] - totalDelta, (putHere - s[2 * i]) - balanceDelta);
                    byBalance.add(seg);
                    byTotal.add(seg);
                }
                //out.print(putHere + " ");
            }
            //out.println();
            out.println(res);
        }

        static class Segment {
            int index;
            long total;
            long balance;

            public Segment(int index, long total, long balance) {
                this.index = index;
                this.total = total;
                this.balance = balance;
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