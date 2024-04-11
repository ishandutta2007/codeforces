import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s1 = in.next();
        String s2 = in.next();
        String virus = in.next();
        int[] l = new int[virus.length()];
        for (int i = 2; i < virus.length(); ++i)
            for (int j = i - 1; j >= 1; --j)
                if (virus.substring(0, i).endsWith(virus.substring(0, j))) {
                    l[i] = j;
                    break;
                }
        int[][][] best = new int[s1.length() + 1][s2.length() + 1][virus.length()];
        int[][][] via = new int[s1.length() + 1][s2.length() + 1][virus.length()];
        for (int[][] a : best) for (int[] b : a) Arrays.fill(b, -1);
        best[0][0][0] = 0;
        for (int p1 = 0; p1 <= s1.length(); ++p1)
            for (int p2 = 0; p2 <= s2.length(); ++p2)
                for (int v = 0; v < virus.length(); ++v)
                    if (best[p1][p2][v] >= 0) {
                        int cbest = best[p1][p2][v];
                        if (p1 + 1 <= s1.length()) {
                            if (best[p1 + 1][p2][v] < cbest) {
                                best[p1 + 1][p2][v] = cbest;
                                via[p1 + 1][p2][v] = 1;
                            }
                        }
                        if (p2 + 1 <= s2.length()) {
                            if (best[p1][p2 + 1][v] < cbest) {
                                best[p1][p2 + 1][v] = cbest;
                                via[p1][p2 + 1][v] = 2;
                            }
                        }
                        if (p1 + 1 <= s1.length() && p2 + 1 <= s2.length() && s1.charAt(p1) == s2.charAt(p2)) {
                            int nv = v;
                            char ch = s1.charAt(p1);
                            while (true) {
                                if (virus.charAt(nv) == ch) {
                                    ++nv;
                                    break;
                                }
                                if (nv == 0) break;
                                nv = l[nv];
                            }
                            if (nv < virus.length()) {
                                if (best[p1 + 1][p2 + 1][nv] < 1 + cbest) {
                                    best[p1 + 1][p2 + 1][nv] = 1 + cbest;
                                    via[p1 + 1][p2 + 1][nv] = 3 + v;
                                }
                            }
                        }
                    }
        int cv = 0;
        for (int i = 1; i < virus.length(); ++i)
            if (best[s1.length()][s2.length()][i] > best[s1.length()][s2.length()][cv])
                cv = i;
        if (best[s1.length()][s2.length()][cv] == 0) {
            out.println(0);
            return;
        }
        String res = "";
        int p1 = s1.length();
        int p2 = s2.length();
        while (p1 > 0 && p2 > 0) {
            switch (via[p1][p2][cv]) {
                case 1:
                    --p1;
                    break;

                case 2:
                    --p2;
                    break;

                default:
                    cv = via[p1][p2][cv] - 3;
                    --p1;
                    --p2;
                    res = s1.charAt(p1) + res;
                    break;
            }
        }
        out.println(res);
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

    }