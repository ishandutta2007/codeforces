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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static class Man implements Comparable<Man> {
        String name;
        int higher;
        int height;

        Man(String name, int higher) {
            this.name = name;
            this.higher = higher;
        }


        public int compareTo(Man o) {
            return higher - o.higher;
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        String[] name = new String[n];
        Man[] men = new Man[n];
        for (int i = 0; i < n; i++) {
            name[i] = in.next();
            a[i] = in.nextInt();
            men[i] = new Man(name[i], a[i]);
        }
        Arrays.sort(men);
        int[] place = new int[n];
        Arrays.fill(place, -1);
        all: for (int i = n - 1; i >= 0; i--) {
            a[i] = men[i].higher;
            for (int j = 0; j < n; j++) {
                if (place[j] >= 0) {
                    continue;
                }
                if (a[i] == 0) {
                    place[j] = i;
                    continue all;
                }
                a[i]--;
            }
            out.println(-1);
            return;
        }
        for (int i = 0; i < n; i++) {
            men[place[i]].height = n - i;
        }
        for (Man e : men) {
            out.println(e.name + " " + e.height);
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