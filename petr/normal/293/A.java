import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {


    public void solve(int testNumber, InputReader in, PrintWriter out) {
        /*int[][][][] cache = new int[11][11][11][11];
        for (int sum = 0; sum <= 10; ++sum) {
            for (int a = 0; a <= 10; ++a) // 00
                for (int b = 0; b <= 10; ++b) // 01
                    for (int c = 0; c <= 10; ++c) { // 10
                        int d = sum - a - b - c; // 11
                        if (d >= 0 && d <= 10) {
                            cache[a][b][c][d] = -100;
                            if (a > 0)
                                cache[a][b][c][d] = Math.max(cache[a][b][c][d], -cache[a - 1][c][b][d]);
                            if (b > 0)
                                cache[a][b][c][d] = Math.max(cache[a][b][c][d] ,-cache[a][c][b - 1][d]);
                            if (c > 0)
                                cache[a][b][c][d] = Math.max(cache[a][b][c][d], 1 - cache[a][c - 1][b][d]);
                            if (d > 0)
                                cache[a][b][c][d] = Math.max(cache[a][b][c][d], 1 - cache[a][c][b][d - 1]);
                            if (a == 0 && b == 0 && c == 0 && d == 0) cache[a][b][c][d] = 0;
                            if (cache[a][b][c][d] != solveStupid(a, b, c, d))
                                System.out.println(a + " " + b + " " +c + " " + d + "   "+  cache[a][b][c][d]);
                        }
                    }
        } */
        int n = in.nextInt();
        String s = in.next();
        String t = in.next();
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (s.charAt(i) == '0' && t.charAt(i) == '0')
                ++a;
            if (s.charAt(i) == '0' && t.charAt(i) == '1')
                ++b;
            if (s.charAt(i) == '1' && t.charAt(i) == '0')
                ++c;
            if (s.charAt(i) == '1' && t.charAt(i) == '1')
                ++d;
        }
        int sgn = 1;
        int res = 0;
        while (true) {
            if (d > 0) {
                res += sgn;
                --d;
                int tmp = b;
                b = c;
                c = tmp;
                sgn = -sgn;
                continue;
            } else if (c > 0) {
                res += sgn;
                --c;
                int tmp = b;
                b = c;
                c = tmp;
                sgn = -sgn;
            } else if (b > 0) {
                --b;
                int tmp = b;
                b = c;
                c = tmp;
                sgn = -sgn;
            } else if (a > 0) {
                --a;
                int tmp = b;
                b = c;
                c = tmp;
                sgn = -sgn;
            } else break;
        }
        if (res > 0) out.println("First"); else if (res < 0) out.println("Second"); else out.println("Draw");
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