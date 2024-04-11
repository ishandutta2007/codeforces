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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int k = in.nextInt();
        long x = in.nextLong();
        int n = in.nextInt();
        int m = in.nextInt();
        char[] s1 = new char[n];
        Arrays.fill(s1, 'Z');
        char[] s2 = new char[m];
        Arrays.fill(s2, 'Z');
        for (int a = 0; a < 2; ++a) {
            if (a == 1) {
                s1[0] = 'C';
            }
            for (int b = 0; b < 2 && a + b <= s1.length; ++b) {
                if (b == 1) {
                    s1[s1.length - 1] = 'A';
                }
                for (int c = 0; c < 2; ++c) {
                    if (c == 1) {
                        s2[0] = 'C';
                    }
                    for (int d = 0; d < 2 && c + d <= s2.length; ++d) {
                        if (d == 1) {
                            s2[s2.length - 1] = 'A';
                        }
                        for (int e = 0; a + b + 2 * e <= s1.length; ++e) {
                            if (e > 0) {
                                s1[a + (e - 1) * 2] = 'A';
                                s1[a + (e - 1) * 2 + 1] = 'C';
                            }
                            for (int f = 0; c + d + 2 * f <= s2.length; ++f) {
                                if (f > 0) {
                                    s2[c + (f - 1) * 2] = 'A';
                                    s2[c + (f - 1) * 2 + 1] = 'C';
                                }
                                if (eval(a, b, c, d, e, f, k) == x) {
                                    out.println(new String(s1));
                                    out.println(new String(s2));
                                    return;
                                }
                            }
                            for (int f = 0; c + d + 2 * f <= s2.length; ++f) {
                                if (f > 0) {
                                    s2[c + (f - 1) * 2] = 'Z';
                                    s2[c + (f - 1) * 2 + 1] = 'Z';
                                }
                            }
                        }
                        for (int e = 0; a + b + 2 * e <= s1.length; ++e) {
                            if (e > 0) {
                                s1[a + (e - 1) * 2] = 'Z';
                                s1[a + (e - 1) * 2 + 1] = 'Z';
                            }
                        }
                        if (d == 1) {
                            s2[s2.length - 1] = 'Z';
                        }
                    }
                    if (c == 1) {
                        s2[0] = 'Z';
                    }
                }
                if (b == 1) {
                    s1[s1.length - 1] = 'Z';
                }
            }
            if (a == 1) {
                s1[0] = 'Z';
            }
        }
        out.println("Happy new year!");
    }

    private long eval(long a, long b, long c, long d, long e, long f, int k) {
        for (int i = 3; i <= k; ++i) {
            long na = a;
            long nb = d;
            long ne = e + f + (b + c == 2 ? 1 : 0);
            if (ne > 1e18) ne = (long) 1e18;
            a = c;
            b = d;
            e = f;
            c = na;
            d = nb;
            f = ne;
        }
        return f;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }