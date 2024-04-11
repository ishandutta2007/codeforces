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
    static class Tree {
        String name;
        int[] dest;
        int[] first;
        int[] next;
        int[] from;
        boolean[] killed;
        boolean[] fullyKilled;
        int[] kill;
        int nkill;
        int[] component;
        int ncomp;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Tree t1 = readTree(in, n);
        Tree t2 = readTree(in, n);
        t1.name = "Blue";
        t2.name = "Red";
        int[] qa = new int[n];
        int[] qb = new int[n];
        t1.nkill = 1;
        t1.kill[0] = in.nextInt() - 1;
        t1.killed[t1.kill[0]] = true;
        Random random = new Random(54713543151L);
        for (int step = 0;; ++step) {
            Tree cur;
            Tree other;
            if ((step & 1) == 0) {
                cur = t1;
                other = t2;
            } else {
                cur = t2;
                other = t1;
            }
            if (cur.nkill == 0) break;
            other.nkill = 0;
            for (int i = 0; i < cur.nkill; ++i) {
                int j = i + random.nextInt(cur.nkill - i);
                int tmp = cur.kill[i];
                cur.kill[i] = cur.kill[j];
                cur.kill[j] = tmp;
            }
            Arrays.sort(cur.kill, 0, cur.nkill);
            out.println(cur.name);
            for (int i = 0; i < cur.nkill; ++i) {
                if (i > 0) out.print(" ");
                out.print(cur.kill[i] + 1);
                int a = cur.dest[cur.kill[i] * 2];
                int b = cur.dest[cur.kill[i] * 2 + 1];
                cur.fullyKilled[cur.kill[i]] = true;
                if (cur.component[a] == cur.component[b]) {
                    int qta = 0;
                    int qha = 1;
                    int tailA = -2;
                    int tailB = -2;
                    int prevA = -1;
                    int prevB = -1;
                    qa[0] = a;
                    cur.from[a] = b;
                    cur.from[b] = a;
                    int qtb = 0;
                    int qhb = 1;
                    qb[0] = b;
                    while (qta < qha && qtb < qhb) {
                        {
                            int v = qa[qta];
                            if (tailA == -2) tailA = cur.first[v];
                            while (tailA >= 0 && cur.fullyKilled[tailA >> 1]) {
                                int nxt = cur.next[tailA];
                                if (prevA < 0) cur.first[v] = nxt; else cur.next[prevA] = nxt;
                                tailA = nxt;
                            }
                            if (tailA < 0) {
                                ++qta;
                                tailA = -2;
                                prevA = -1;
                            } else {
                                if (cur.dest[tailA] != cur.from[v]) {
                                    qa[qha++] = cur.dest[tailA];
                                    cur.from[cur.dest[tailA]] = v;
                                }
                                prevA = tailA;
                                tailA = cur.next[tailA];
                            }
                        }
                        {
                            int v = qb[qtb];
                            if (tailB == -2) tailB = cur.first[v];
                            while (tailB >= 0 && cur.fullyKilled[tailB >> 1]) {
                                int nxt = cur.next[tailB];
                                if (prevB < 0) cur.first[v] = nxt; else cur.next[prevB] = nxt;
                                tailB = nxt;
                            }
                            if (tailB < 0) {
                                ++qtb;
                                tailB = -2;
                                prevB = -1;
                            } else {
                                if (cur.dest[tailB] != cur.from[v]) {
                                    qb[qhb++] = cur.dest[tailB];
                                    cur.from[cur.dest[tailB]] = v;
                                }
                                prevB = tailB;
                                tailB = cur.next[tailB];
                            }
                        }
                    }
                    if (qta == qha) {
                        for (int j = 0; j < qha; ++j) {
                            int v = qa[j];
                            cur.component[v] = cur.ncomp;
                        }
                        for (int j = 0; j < qha; ++j) {
                            int v = qa[j];
                            int prevEdge = -1;
                            int curEdge = other.first[v];
                            while (curEdge >= 0) {
                                if (other.fullyKilled[curEdge >> 1]) {
                                    int nxt = other.next[curEdge];
                                    if (prevEdge < 0) other.first[v] = nxt; else other.next[prevEdge] = nxt;
                                    curEdge = nxt;
                                    continue;
                                }
                                if (cur.component[other.dest[curEdge]] != cur.component[v] && !other.killed[curEdge >> 1]) {
                                    other.killed[curEdge >> 1] = true;
                                    other.kill[other.nkill++] = curEdge >> 1;
                                }
                                prevEdge = curEdge;
                                curEdge = other.next[curEdge];
                            }
                        }
                    } else {
                        for (int j = 0; j < qhb; ++j) {
                            int v = qb[j];
                            cur.component[v] = cur.ncomp;
                        }
                        for (int j = 0; j < qhb; ++j) {
                            int v = qb[j];
                            int prevEdge = -1;
                            int curEdge = other.first[v];
                            while (curEdge >= 0) {
                                if (other.fullyKilled[curEdge >> 1]) {
                                    int nxt = other.next[curEdge];
                                    if (prevEdge < 0) other.first[v] = nxt; else other.next[prevEdge] = nxt;
                                    curEdge = nxt;
                                    continue;
                                }
                                if (cur.component[other.dest[curEdge]] != cur.component[v] && !other.killed[curEdge >> 1]) {
                                    other.killed[curEdge >> 1] = true;
                                    other.kill[other.nkill++] = curEdge >> 1;
                                }
                                prevEdge = curEdge;
                                curEdge = other.next[curEdge];
                            }
                        }
                    }
                    ++cur.ncomp;
                } else {
                    throw new RuntimeException();
                }
            }
            out.println();
        }
    }

    private Tree readTree(InputReader in, int n) {
        Tree t = new Tree();
        t.dest = new int[2 * (n - 1)];
        t.next = new int[2 * (n - 1)];
        t.first = new int[n];
        Arrays.fill(t.first, -1);
        for (int i = 0; i < n - 1; ++i) {
            int a = in.nextInt() - 1;
            t.dest[i * 2] = a;
            t.next[i * 2] = t.first[i + 1];
            t.first[i + 1] = i * 2;
            t.dest[i * 2 + 1] = i + 1;
            t.next[i * 2 + 1] = t.first[a];
            t.first[a] = i * 2 + 1;
        }
        t.killed = new boolean[n - 1];
        t.fullyKilled = new boolean[n - 1];
        t.from = new int[n];
        t.kill = new int[n - 1];
        t.component = new int[n];
        t.ncomp = 1;
        return t;
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