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
        int n = in.nextInt();
        int m = in.nextInt();
        int[] src = new int[m + 10];
        int[] next = new int[m + 10];
        int[] firstIncoming = new int[n + 10];
        int[] numOutgoing = new int[n + 10];
        int[] answer = new int[n + 10];
        Arrays.fill(answer, -1);
        Arrays.fill(firstIncoming, -1);
        for (int i = 0; i < m; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            ++numOutgoing[u];
            next[i] = firstIncoming[v];
            src[i] = u;
            firstIncoming[v] = i;
        }
        int s = in.nextInt() - 1;
        int t = in.nextInt() - 1;
        int[] ready = new int[n + 10];
        int numReady = 0;
        int[] cur = new int[n + 10];
        int numCur = 1;
        cur[0] = t;
        answer[t] = 0;
        int[] nxt = new int[n + 10];
        while (numCur > 0) {
            for (int i = 0; i < numCur; ++i) {
                int tmp = firstIncoming[cur[i]];
                while (tmp >= 0) {
                    if (answer[src[tmp]] < 0) {
                        --numOutgoing[src[tmp]];
                        if (numOutgoing[src[tmp]] == 0) {
                            ready[numReady++] = src[tmp];
                        }
                    }
                    tmp = next[tmp];
                }
            }
            while (numReady > 0) {
                cur[numCur++] = ready[--numReady];
                answer[cur[numCur - 1]] = answer[cur[0]];
                int tmp = firstIncoming[cur[numCur - 1]];
                while (tmp >= 0) {
                    if (answer[src[tmp]] < 0) {
                        --numOutgoing[src[tmp]];
                        if (numOutgoing[src[tmp]] == 0) {
                            ready[numReady++] = src[tmp];
                        }
                    }
                    tmp = next[tmp];
                }
            }
            int numNxt = 0;
            for (int i = 0; i < numCur; ++i) {
                int tmp = firstIncoming[cur[i]];
                while (tmp >= 0) {
                    if (answer[src[tmp]] < 0) {
                        answer[src[tmp]] = answer[cur[0]] + 1;
                        nxt[numNxt++] = src[tmp];
                    }
                    tmp = next[tmp];
                }
            }
            int[] ta = cur;
            cur = nxt;
            nxt = ta;
            numCur = numNxt;
        }
        out.println(answer[s]);
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