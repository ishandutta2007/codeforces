import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        long[] l = new long[n];
        long[] r = new long[n];
        for (int i = 0; i < n; i++) {
            l[i] = Long.parseLong(next());
            r[i] = Long.parseLong(next());
        }
        long[] a = new long[m];
        for (int i = 0; i < m; i++) {
            a[i] = Long.parseLong(next());
        }
        List<Event> events = new ArrayList<Event>();
        List<Segment> segments = new ArrayList<Segment>(n - 1);
        for (int i = 0; i < n - 1; i++) {
            Segment segment = new Segment(i, l[i + 1] - r[i], r[i + 1] - l[i]);
            segments.add(i, segment);
            events.add(new Event(segment.l * 2 - 1, 1, segment, null));
        }
        List<Bridge> bridges = new ArrayList<Bridge>();
        for (int i = 0; i < m; i++) {
            Bridge bridge = new Bridge(i, a[i]);
            bridges.add(bridge);
            events.add(new Event(bridge.l * 2, 2, null, bridge));
        }
        Collections.sort(events);
        PriorityQueue<Segment> pq = new PriorityQueue<Segment>();
        int[] res = new int[n - 1];
        for (Event event : events) {
            if (event.type == 1) {
                pq.add(event.segment);
            } else {
                if (!pq.isEmpty()) {
                    Bridge bridge = event.bridge;
                    Segment segment = pq.remove();
                    if (bridge.l > segment.r) {
                        out.println("No");
                        return;
                    } else {
                        res[segment.i] = bridge.i;
                    }
                }
            }
        }
        if (!pq.isEmpty()) {
            out.println("No");
            return;
        }
        out.println("Yes");
        for (int i = 0; i < n - 1; i++) {
            out.print((res[i] + 1) + " ");
        }
        out.println();

    }

    class Bridge implements Comparable<Bridge> {
        int i;
        long l;

        public Bridge(int i, long l) {
            this.i = i;
            this.l = l;
        }

        public int compareTo(Bridge o) {
            return Long.compare(l, o.l);
        }
    }

    class Segment implements Comparable<Segment> {
        int i;
        long l;
        long r;

        public Segment(int i, long l, long r) {
            this.i = i;
            this.l = l;
            this.r = r;
        }

        public int compareTo(Segment o) {
            return Long.compare(r, o.r);
        }
    }

    class Event implements Comparable<Event> {
        long t;
        int type;
        Segment segment;
        Bridge bridge;

        public Event(long t, int type, Segment segment, Bridge bridge) {
            this.t = t;
            this.type = type;
            this.segment = segment;
            this.bridge = bridge;
        }

        public int compareTo(Event o) {
            return Long.compare(t, o.t);
        }
    }

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}