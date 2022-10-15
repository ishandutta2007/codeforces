import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int[] c1 = readAll(in);
        int[] c2 = c1.clone();
        int best = -1;
        String ans1 = getAll(c1);
        String ans2 = getAll(c2);
        for (int i = 1; i < 10; i++) {
            int j = 10 - i;
            if (c1[i] == 0 || c2[j] == 0) {
                continue;
            }
            int[] d1 = c1.clone();
            int[] d2 = c2.clone();
            d1[i]--;
            d2[j]--;
            StringBuilder sb1 = new StringBuilder();
            StringBuilder sb2 = new StringBuilder();
            for (int k1 = 0; k1 < 10; k1++) {
                int k2 = 9 - k1;
                while (d1[k1] > 0 && d2[k2] > 0) {
                    sb1.appendCodePoint(k1 + '0');
                    sb2.appendCodePoint(k2 + '0');
                    d1[k1]--;
                    d2[k2]--;
                }
            }
            sb1.appendCodePoint(i + '0');
            sb2.appendCodePoint(j + '0');
            while (d1[0] > 0 && d2[0] > 0) {
                sb1.append('0');
                sb2.append('0');
                d1[0]--;
                d2[0]--;
            }
            if (best < sb1.length()) {
                ans1 = getAll(d1) + sb1.toString();
                ans2 = getAll(d2) + sb2.toString();
                best = sb1.length();
            }
        }
        if (best < Math.min(c1[0], c2[0])) {
            best = Math.min(c1[0], c2[0]);
            StringBuilder sb = new StringBuilder();
            while (c1[0] > 0 && c2[0] > 0) {
                sb.append('0');
                c1[0]--;
                c2[0]--;
            }
            ans1 = getAll(c1) + sb.toString();
            ans2 = getAll(c2) + sb.toString();
        }
        out.println(ans1 + " " + ans2);
	}

    static String getAll(int[] c1) {
        StringBuilder ret = new StringBuilder();
        for (int i = 0; i < c1.length; i++) {
            for (int j = 0; j < c1[i]; j++) {
                ret.appendCodePoint('0' + i);
            }
        }
        return ret.toString();
    }

    static int[] readAll(FastScanner in) {
        int[] ret = new int[10];
        for (char c : in.next().toCharArray()) {
            ret[c - '0']++;
        }
        return ret;
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

    }