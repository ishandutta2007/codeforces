import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;


    final int MAX = (int) 1e5 + 10;

    class Value {
        int up, down;

        Value() {
            up = Integer.MAX_VALUE;
            down = Integer.MAX_VALUE;
        }

    }

    class SortedInts {
        ArrayList<Integer> vals;

        SortedInts() {
            vals = new ArrayList<>();
        }

        void add(int x) {
            vals.add(x);
        }

        void build() {
            Collections.sort(vals);
            sum = 0;
            for (long x : vals) {
                sum += x;
            }
            it = vals.size() - 1;
        }

        long getSum() {
            return sum + (vals.size() - it - 1) * 1L * newMin;
        }

        long sum;


        int it;

        void updateMin(int min) {
            newMin = min;
            while (it != -1 && vals.get(it) > newMin) {
                sum -= vals.get(it);
                it--;
            }
        }

        int newMin;
    }

    class Block {
        SortedInts up, down, upZero, downZero;
        int cntAllZero, cntUpZero, cntDownZero;
        int newMax, newMin;
        Value[] a;
        int from, to;

        Block(Value[] a, int from, int to) {
            this.a = a;
            this.from = from;
            this.to = to;
            up = new SortedInts();
            down = new SortedInts();
            upZero = new SortedInts();
            downZero = new SortedInts();
            cntAllZero = 0;
            cntUpZero = 0;
            cntDownZero = 0;
            newMax = 0;
            newMin = 0;
            for (int i = from; i < to; i++) {
                if (a[i].up != Integer.MAX_VALUE && a[i].down != Integer.MAX_VALUE) {
                    up.add(a[i].up);
                    down.add(a[i].down);
                } else if (a[i].up != Integer.MAX_VALUE) {
                    upZero.add(a[i].up);
                    cntDownZero++;
                } else if (a[i].down != Integer.MAX_VALUE) {
                    downZero.add(a[i].down);
                    cntUpZero++;
                } else {
                    cntAllZero++;
                }
            }
            up.build();
            down.build();
            upZero.build();
            downZero.build();
        }

        void updateMin(int x) {
            if (x > 0) {
                if (newMax == 0 || newMax > x) {
                    newMax = x;
                    up.updateMin(x);
                    upZero.updateMin(x);
                }
            } else {
                x = -x;
                if (newMin == 0 || newMin > x) {
                    newMin = x;
                    down.updateMin(x);
                    downZero.updateMin(x);
                }
            }
        }

        long getSum() {
            long result = up.getSum() + down.getSum();
            if (newMax != 0) {
                result += downZero.getSum();
                result += newMax * 1L * cntUpZero;
            }
            if (newMin != 0) {
                result += upZero.getSum();
                result += newMin * 1L * cntDownZero;
            }
            if (newMax != 0 && newMin != 0) {
                result += cntAllZero * 1L * (newMax + newMin);
            }
            return result;
        }

        void build() {
            if (newMax != 0) {
                for (int i = from; i < to; i++) {
                    a[i].up = Math.min(a[i].up, newMax);
                }
            }
            if (newMin != 0) {
                for (int i = from; i < to; i++) {
                    a[i].down = Math.min(a[i].down, newMin);
                }
            }
        }
    }

    private void solve() {
        int q = in.nextInt();
        int[] type = new int[q];
        int[] left = new int[q];
        int[] right = new int[q];
        int[] val = new int[q];
        for (int i = 0; i < q; i++) {
            type[i] = in.nextInt();
            left[i] = in.nextInt();
            right[i] = in.nextInt();
            if (type[i] == 1) {
                val[i] = in.nextInt();
            }
        }
        final int SQRT = 1000;
        Value[] a = new Value[MAX];
        for (int i = 0; i < MAX; i++) {
            a[i] = new Value();
        }
        for (int i = 0; i < q; i += SQRT) {
            ArrayList<Integer> pos = new ArrayList<>();
            pos.add(0);
            pos.add(MAX);
            for (int j = i; j < q && j < i + SQRT; j++) {
                pos.add(left[j]);
                pos.add(right[j]);
            }
            Collections.sort(pos);
            ArrayList<Block> blocks = new ArrayList<>();
            for (int j = 0; j + 1 < pos.size(); j++) {
                if (pos.get(j) - pos.get(j + 1) != 0) {
                    blocks.add(new Block(a, pos.get(j), pos.get(j + 1)));
                }
            }
            for (int j = i; j < q && j < i + SQRT; j++) {
                if (type[j] == 1) {
                    for (Block block : blocks) {
                        if (block.from >= left[j] && block.to <= right[j]) {
                            block.updateMin(val[j]);
                        }
                    }
                } else {
                    long res = 0;
                    for (Block block : blocks) {
                        if (block.from >= left[j] && block.to <= right[j]) {
                            res += block.getSum();
                        }
                    }
                    out.println(res);
                }
            }

            for (Block b : blocks) {
                b.build();
            }
        }
    }


    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}