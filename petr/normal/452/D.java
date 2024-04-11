import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static class Machine implements Comparable<Machine> {
        int id;
        int firstFree;

        Machine(int id, int firstFree) {
            this.id = id;
            this.firstFree = firstFree;
        }

        public int compareTo(Machine o) {
            int z = firstFree - o.firstFree;
            if (z != 0) return z;
            return id - o.id;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        TreeSet<Machine> first = new TreeSet<Machine>();
        TreeSet<Machine> second = new TreeSet<Machine>();
        TreeSet<Machine> third = new TreeSet<Machine>();
        int k = in.nextInt();
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        int n3 = in.nextInt();
        int t1 = in.nextInt();
        int t2 = in.nextInt();
        int t3 = in.nextInt();
        for (int i = 0; i < n1; ++i)
            first.add(new Machine(i, 0));
        for (int i = 0; i < n2; ++i)
            second.add(new Machine(i, 0));
        for (int i = 0; i < n3; ++i)
            third.add(new Machine(i, 0));
        int res = 0;
        for (int i = 0; i < k; ++i) {
            Machine f = first.first();
            first.remove(f);
            Machine s = second.first();
            second.remove(s);
            Machine t = third.first();
            third.remove(t);
            int start = Math.max(f.firstFree, Math.max(s.firstFree - t1, t.firstFree - t1 - t2));
            f.firstFree = start + t1;
            first.add(f);
            s.firstFree = start + t1 + t2;
            second.add(s);
            t.firstFree = start + t1 + t2 + t3;
            third.add(t);
            res = t.firstFree;
        }
        out.println(res);
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