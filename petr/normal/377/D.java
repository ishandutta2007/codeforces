import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
    static class Employee {
        int l;
        int v;
        int r;
        int index;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Employee[] emps = new Employee[n];
        int maxr = 0;
        for (int i = 0; i < n; ++i) {
            emps[i] = new Employee();
            emps[i].index = i + 1;
            emps[i].l = in.nextInt();
            emps[i].v = in.nextInt();
            emps[i].r = in.nextInt();
            maxr = Math.max(maxr, emps[i].r);
        }
        Arrays.sort(emps, new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                return o1.l - o2.l;
            }
        });
        maxr += 3;
        int[] max = new int[4 * maxr + 10];
        int[] sum = new int[4 * maxr + 10];
        int[] maxAt = new int[4 * maxr + 10];
        int best = 0;
        int bestl = 0;
        int bestr = 0;
        Employee[] empByV = emps.clone();
        Arrays.sort(empByV, new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                return o1.v - o2.v;
            }
        });
        int ptrV = 0;
        initTree(max, sum, maxAt, 0, 0, maxr - 1);
        for (Employee emp : emps) {
            while (ptrV < empByV.length && empByV[ptrV].v < emp.l) {
                update(max, sum, maxAt, 0, 0, maxr - 1, empByV[ptrV].v, -1);
                update(max, sum, maxAt, 0, 0, maxr - 1, empByV[ptrV].r + 1, 1);
                ++ptrV;
            }
            update(max, sum, maxAt, 0, 0, maxr - 1, emp.v, 1);
            update(max, sum, maxAt, 0, 0, maxr - 1, emp.r + 1, -1);
            if (max[0] > best) {
                best = max[0];
                bestl = emp.l;
                bestr = maxAt[0];
            }
        }
        out.println(best);
        boolean first = true;
        for (Employee emp : emps) {
            if (bestl <= emp.v && bestr >= emp.v && bestl >= emp.l && bestr <= emp.r) {
                if (first) first = false; else out.print(" ");
                out.print(emp.index);
            }
        }
        out.println();
    }

    private void initTree(int[] max, int[] sum, int[] maxAt, int root, int rl, int rr) {
        if (rl == rr) {
            maxAt[root] = rl;
            return;
        }
        int rm = (rl + rr) / 2;
        initTree(max, sum, maxAt, root * 2 + 1, rl, rm);
        initTree(max, sum, maxAt, root * 2 + 2, rm + 1, rr);
    }

    private void update(int[] max, int[] sum, int[] maxAt, int root, int rl, int rr, int at, int by) {
        if (rl == rr) {
            max[root] += by;
            sum[root] += by;
            return;
        }
        int rm = (rl + rr) / 2;
        if (at <= rm) {
            update(max, sum, maxAt, root * 2 + 1, rl, rm, at, by);
        } else {
            update(max, sum, maxAt, root * 2 + 2, rm + 1, rr, at, by);
        }
        sum[root] = sum[root * 2 + 1] + sum[root * 2 + 2];
        int maxr = sum[root * 2 + 1] + max[root * 2 + 2];
        if (maxr <= max[root * 2 + 1]) {
            max[root] = max[root * 2 + 1];
            maxAt[root] = maxAt[root * 2 + 1];
        } else {
            max[root] = maxr;
            maxAt[root] = maxAt[root * 2 + 2];
        }
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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