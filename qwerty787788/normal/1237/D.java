import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        Track[] a = new Track[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Track(i, in.nextInt());
        }
        Arrays.sort(a);
        TreeSet<Integer> pos = new TreeSet<>();
        int[] next = new int[n];
        int it = 0;
        for (Track t : a) {
            while (a[it].value * 2 < t.value) {
                pos.add(a[it].id);
                it++;
            }
            Integer h = pos.higher(t.id);
            if (h != null) {
                next[t.id] = h;
            } else {
                h = pos.isEmpty() ? null : pos.first();
                if (h != null) {
                    next[t.id] = h;
                } else {
                    next[t.id] = -1;
                }
            }
        }
        pos.clear();
        int[] res = new int[n];
        Arrays.fill(res, Integer.MAX_VALUE / 2);
        for (int i = n - 1; i >= 0; i--) {
            Track t = a[i];
            Integer h = pos.higher(t.id);
            if (h == null) {
                h = pos.isEmpty() ? null : pos.first();
            }
            if (h != null) {
                res[t.id] = res[h] + dist(n, t.id, h);
            }
            int nextBad = next[t.id];
            if (nextBad != -1) {
                res[t.id] = Math.min(res[t.id], dist(n, t.id, nextBad));
            }
            pos.add(t.id);
        }
        for (int x : res) {
            out.print((x >= Integer.MAX_VALUE / 2 ? -1 : x) + " ");
        }
        out.println();
    }

    int dist(int n, int from, int to) {
        if (from <= to) {
            return to - from;
        }
        return (n - from) + to;
    }

    class Track implements Comparable<Track> {
        int id;
        int value;

        public Track(int id, int value) {
            this.id = id;
            this.value = value;
        }

        @Override
        public int compareTo(Track track) {
            return Integer.compare(value, track.value);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
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