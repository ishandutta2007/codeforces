import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String me = in.nextLine().trim();
        int n = Integer.parseInt(in.nextLine().trim());
        Map<String, Integer> pnts = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(in.nextLine(), " \t\r\n'");
            String name = st.nextToken();
            if (!name.equals(me) && !pnts.containsKey(name)) {
                pnts.put(name, 0);
            }
            String t1 = st.nextToken();
            if (!t1.equals("likes")) {
                st.nextToken();
            }
            String who = st.nextToken();
            if (!me.equals(who) && !pnts.containsKey(who)) {
                pnts.put(who, 0);
            }
            if (who.equals(me)) {
                String t = name;
                name = who;
                who = t;
            }
            if (!name.equals(me)) {
                continue;
            }
            Integer z = pnts.get(who);
            if (t1.equals("posted")) {
                z += 15;
            } else if (t1.equals("commented")) {
                z += 10;
            } else {
                z += 5;
            }
            pnts.put(who, z);
        }
        Map.Entry<String, Integer>[] ar = pnts.entrySet().toArray(new Map.Entry[pnts.size()]);
        Arrays.sort(ar, new Comparator<Map.Entry<String, Integer>>() {
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                if (o1.getValue().intValue() != o2.getValue().intValue()) {
                    return o2.getValue() - o1.getValue();
                }
                return o1.getKey().compareTo(o2.getKey());
            }
        });
        for (Map.Entry<String, Integer> e : ar) {
            out.println(e.getKey());
        }
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String nextLine() {
        try {
            return readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}