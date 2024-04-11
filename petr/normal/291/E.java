import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    public static final int MAX_DATA = 500000;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] nextSibling = new int[n];
        int[] firstChild = new int[n];
        Arrays.fill(firstChild, -1);
        Arrays.fill(nextSibling, -1);
        String[] label = new String[n];
        label[0] = "";
        for (int i = 1; i < n; ++i) {
            int parent = in.nextInt() - 1;
            nextSibling[i] = firstChild[parent];
            firstChild[parent] = i;
            label[i] = in.next();
        }
        String t = in.next();
        Random random = new Random(471543543153L + System.currentTimeMillis());
        long modulo1 = nextPrime(random.nextInt((int) 2e9));
        long modulo2 = nextPrime(random.nextInt((int) 2e9));
        long mul1 = random.nextInt((int) modulo1 - 3) + 2;
        long mul2 = random.nextInt((int) modulo2 - 3) + 2;
        long pow1 = 1;
        long pow2 = 1;
        long need1 = 0;
        long need2 = 0;
        for (int i = 0; i < t.length(); ++i) {
            pow1 = (pow1 * mul1) % modulo1;
            pow2 = (pow2 * mul2) % modulo2;
            need1 = (need1 * mul1 + t.charAt(i)) % modulo1;
            need2 = (need2 * mul2 + t.charAt(i)) % modulo2;
        }
        pow1 = (modulo1 - pow1) % modulo1;
        pow2 = (modulo2 - pow2) % modulo2;
        char[] stack = new char[MAX_DATA];
        int[] stackWhere = new int[MAX_DATA];
        int[] stackOffset = new int[MAX_DATA];
        int[] hash1 = new int[MAX_DATA];
        int[] hash2 = new int[MAX_DATA];
        int sp = 1;
        stack[0] = ' ';
        stackWhere[0] = 0;
        stackOffset[0] = 0;
        hash1[0] = 0;
        hash2[0] = 0;
        int res = 0;
        while (sp > 0) {
            int where = stackWhere[sp - 1];
            int offset = stackOffset[sp - 1];
            if (offset < label[where].length()) {
                stack[sp] = label[where].charAt(offset);
                stackWhere[sp] = where;
                stackOffset[sp] = offset + 1;
                long h1 = (hash1[sp - 1] * mul1 + stack[sp]) % modulo1;
                long h2 = (hash2[sp - 1] * mul2 + stack[sp]) % modulo2;
                if (sp - t.length() > 0) {
                    h1 = (h1 + pow1 * stack[sp - t.length()]) % modulo1;
                    h2 = (h2 + pow2 * stack[sp - t.length()]) % modulo2;
                }
                hash1[sp] = (int) h1;
                hash2[sp] = (int) h2;
                if (hash1[sp] == need1 && hash2[sp] == need2) {
                    ++res;
                }
                ++sp;
            } else {
                int dest = firstChild[where];
                if (dest < 0) {
                    while (sp > 0 && stackWhere[sp - 1] == where) --sp;
                } else {
                    firstChild[where] = nextSibling[dest];
                    where = dest;
                    offset = 0;
                    stack[sp] = label[where].charAt(offset);
                    stackWhere[sp] = where;
                    stackOffset[sp] = offset + 1;
                    long h1 = (hash1[sp - 1] * mul1 + stack[sp]) % modulo1;
                    long h2 = (hash2[sp - 1] * mul2 + stack[sp]) % modulo2;
                    if (sp - t.length() > 0) {
                        h1 = (h1 + pow1 * stack[sp - t.length()]) % modulo1;
                        h2 = (h2 + pow2 * stack[sp - t.length()]) % modulo2;
                    }
                    hash1[sp] = (int) h1;
                    hash2[sp] = (int) h2;
                    if (hash1[sp] == need1 && hash2[sp] == need2) {
                        ++res;
                    }
                    ++sp;
                }
            }
        }
        out.println(res);
    }

    private long nextPrime(long start) {
        while (!isPrime(start)) ++start;
        return start;
    }

    private boolean isPrime(long x) {
        for (long i = 2; i * i <= x; ++i)
            if (x % i == 0) return false;
        return true;
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