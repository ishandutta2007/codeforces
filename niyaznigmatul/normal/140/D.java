import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static final int CONTEST_TIME = 720;
    static final int PROBLEM_READ = 10;
	public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int problemsSolved = 0;
        int sumTime = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] + sumTime > CONTEST_TIME - PROBLEM_READ) {
                break;
            }
            problemsSolved++;
            sumTime += a[i];
        }
        n = problemsSolved;
        a = Arrays.copyOf(a, problemsSolved);
        int time = 0;
        for (int i = 0; i < n; i++) {
            int current = PROBLEM_READ;
            for (int j = 0; j <= i; j++) {
                current += a[j];
            }
            if (current >= 360) {
                time += current - 360;
            }
        }
        out.println(problemsSolved + " " + time);
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