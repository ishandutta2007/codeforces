import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

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
}

class TaskD {
    static class City {
        List<Road> roads = new ArrayList<>(1);
        int subtreeSize;
        City parent;

        public int initSubtreeSizes(City parent) {
            this.parent = parent;
            subtreeSize = 1;
            for (Road r : roads) {
                if (r.dest == parent) continue;
                subtreeSize += r.dest.initSubtreeSizes(this);
            }
            return subtreeSize;
        }
    }

    static class Road {
        City dest;
        Road rev;
        int len;
        long times;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        City[] cities = new City[n];
        for (int i = 0; i < n; ++i) cities[i] = new City();
        Road[] roads = new Road[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int l = in.nextInt();
            City ca = cities[a];
            City cb = cities[b];
            Road ab = new Road();
            Road ba = new Road();
            ab.dest = cb;
            ab.rev = ba;
            ab.len = l;
            ca.roads.add(ab);
            ba.dest = ca;
            ba.rev = ab;
            ba.len = l;
            cb.roads.add(ba);
            roads[i] = ab;
        }
        City root = cities[0];
        root.initSubtreeSizes(null);
        long sum = 0;
        for (Road r : roads) {
            City a = r.dest;
            City b = r.rev.dest;
            if (a.parent == b) {
                r.times = a.subtreeSize * (long) (n - a.subtreeSize);
            } else if (b.parent == a) {
                r.times = b.subtreeSize * (long) (n - b.subtreeSize);
            } else throw new RuntimeException();
            sum += r.times * r.len;
        }
        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            Road r = roads[in.nextInt() - 1];
            int w = in.nextInt();
            sum += r.times * (w - r.len);
            r.len = w;
            out.println(6.0 * sum / n / (n - 1));
        }
    }
}

class InputReader {
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