import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class D {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        Event[] events = new Event[2 * n];
        int[] xx = new int[2 * n];
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            int y = nextInt();
            xx[2 * i] = x;
            xx[2 * i + 1] = x + k;
            events[2 * i] = new Event(x, x + k, y, 1);
            events[2 * i + 1] = new Event(x, x + k, y + k, -1);
        }
        Arrays.sort(xx);
        int nx = 1;
        for (int i = 1; i < xx.length; i++) {
            if (xx[i] != xx[i - 1]) {
                xx[nx++] = xx[i];
            }
        }

        long[] res = new long[n];
        int[] c = new int[nx];
        long[] cy = new long[nx];

        Arrays.sort(events, new Comparator<Event>() {
            @Override
            public int compare(Event o1, Event o2) {
                return Integer.compare(o1.y, o2.y);
            }
        });

        for (Event event : events) {
            int ll = binsearch(xx, nx, event.l);
            int rr = binsearch(xx, nx, event.r);
            for (int i = ll; i < rr; i++) {
                if (c[i] > 0) {
                    res[c[i] - 1] += 1L * (xx[i + 1] - xx[i]) * (event.y - cy[i]);
                }
                c[i] += event.d;
                cy[i] = event.y;
            }
//            System.out.println(ll + " " + rr + " " + Arrays.toString(c));
        }

        for (int i = 0; i < n; i++) {
            out.println(res[i]);
        }
    }

    private int binsearch(int[] xx, int n, int x) {
        int l = -1;
        int r = n;
        while (r > l + 1) {
            int m = (l + r) >> 1;
            if (xx[m] > x) r = m; else l = m;
        }
        return l;
    }


    class Event {
        int l, r, y, d;

        public Event(int l, int r, int y, int d) {
            this.l = l;
            this.r = r;
            this.y = y;
            this.d = d;
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}