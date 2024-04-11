import java.util.Map;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            if (!count.containsKey(x)) {
                 count.put(x, 0);
            }
            count.put(x, count.get(x) + 1);
        }
        PriorityQueue<Element> pq = new PriorityQueue<Element>();
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            pq.add(new Element(e.getKey(), e.getValue()));
        }
        List<String> output = new ArrayList<String>();
        while (pq.size() >= 3) {
            Element e1 = pq.poll();
            Element e2 = pq.poll();
            Element e3 = pq.poll();
            int[] a = new int[]{e1.val, e2.val, e3.val};
            Arrays.sort(a);
            output.add(a[2] + " " + a[1] + " " + a[0]);
            e1.count--;
            e2.count--;
            e3.count--;
            if (e1.count != 0) {
                pq.add(e1);
            }
            if (e2.count != 0) {
                pq.add(e2);
            }
            if (e3.count != 0) {
                pq.add(e3);
            }
        }
        out.println(output.size());
        for (String e : output) {
            out.println(e);
        }
	}

    static class Element implements Comparable<Element> {
        int val;
        int count;

        Element(int val, int count) {
            this.val = val;
            this.count = count;
        }

        public int compareTo(Element o) {
            return o.count - count;
        }
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }