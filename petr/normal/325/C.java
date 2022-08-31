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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static final int MAX_SUM = (int) 1e5;
    static final int TOO_BIG = 314000000;
    private int numTransformations;
    private int numTypes;
    private int[] dest;
    private int[] countByDest;
    private int[] diamonds;
    private int[] first;
    private int[] id;
    private int[] src;
    private int[] minCost;
    private int[] curMinSum;
    private int[] curDeadChildren;
    private int[] heap;
    private int[] heapAt;
    private int[] nextSameSrc;
    private int[] firstBySrc;
    int numHeap;
    private int[] maxCost;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        numTransformations = in.nextInt();
        numTypes = in.nextInt();
        dest = new int[numTransformations];
        diamonds = new int[numTransformations];
        first = new int[numTransformations + 1];
        id = new int[MAX_SUM];
        src = new int[MAX_SUM];
        int cnt = 0;
        for (int i = 0; i < numTransformations; ++i) {
            first[i] = cnt;
            dest[i] = in.nextInt() - 1;
            int len = in.nextInt();
            for (int j = 0; j < len; ++j) {
                int cur = in.nextInt();
                if (cur < 0) ++diamonds[i]; else {
                    --cur;
                    id[cnt] = i;
                    src[cnt] = cur;
                    ++cnt;
                }
            }
        }
        first[numTransformations] = cnt;

        minCost = new int[numTypes];
        Arrays.fill(minCost, -1);
        curMinSum = diamonds.clone();
        curDeadChildren = new int[numTransformations];

        nextSameSrc = new int[cnt];
        firstBySrc = new int[numTypes];
        Arrays.fill(firstBySrc, -1);
        for (int i = 0; i < cnt; ++i) {
            nextSameSrc[i] = firstBySrc[src[i]];
            firstBySrc[src[i]] = i;
        }

        heap = new int[numTransformations];
        heapAt = new int[numTransformations];
        numHeap = 0;
        for (int i = 0; i < numTransformations; ++i)
            if (first[i + 1] - first[i] == curDeadChildren[i]) {
                heap[numHeap++] = i;
                heapAt[i] = numHeap - 1;
                heapUp(numHeap - 1);
            }
        while (numHeap > 0) {
            int cur = heap[0];
            swap(0, numHeap - 1);
            --numHeap;
            if (numHeap > 1) heapDown(0);
            heapAt[cur] = -1;
            if (minCost[dest[cur]] >= 0) {
                continue;
            }
            minCost[dest[cur]] = curMinSum[cur];
            int at = firstBySrc[dest[cur]];
            while (at >= 0) {
                curMinSum[id[at]] += curMinSum[cur];
                if (curMinSum[id[at]] >= TOO_BIG) {
                    curMinSum[id[at]] = TOO_BIG;
                }
                ++curDeadChildren[id[at]];
                int delta = curDeadChildren[id[at]] - (first[id[at] + 1] - first[id[at]]);
                if (delta >= 0) {
                    if (delta > 0) throw new RuntimeException();
                    heap[numHeap++] = id[at];
                    heapAt[id[at]] = numHeap - 1;
                    heapUp(numHeap - 1);
                }
                at = nextSameSrc[at];
            }
        }

        maxCost = new int[numTypes];
        curMinSum = diamonds.clone();
        Arrays.fill(curDeadChildren, 0);
        countByDest = new int[numTypes];
        for (int i = 0; i < numTransformations; ++i) {
            boolean nice = true;
            for (int j = first[i]; j < first[i + 1]; ++j)
                if (minCost[src[j]] < 0)
                    nice = false;
            if (nice)
                ++countByDest[dest[i]];
        }
        numHeap = 0;
        for (int i = 0; i < numTypes; ++i)
            if (minCost[i] >= 0 && countByDest[i] == 0) {
                heap[numHeap++] = i;
            }
        for (int i = 0; i < numTransformations; ++i)
            if (first[i + 1] - first[i] == curDeadChildren[i] && minCost[dest[i]] >= 0) {
                maxCost[dest[i]] = Math.max(maxCost[dest[i]], curMinSum[i]);
                if (maxCost[dest[i]] >= TOO_BIG) {
                    maxCost[dest[i]] = TOO_BIG;
                }
                --countByDest[dest[i]];
                if (countByDest[dest[i]] == 0) {
                    heap[numHeap++] = dest[i];
                }
            }
        while (numHeap > 0) {
            int cur = heap[--numHeap];
            int at = firstBySrc[cur];
            while (at >= 0) {
                if (minCost[dest[id[at]]] >= 0) {
                    curMinSum[id[at]] += maxCost[cur];
                    if (curMinSum[id[at]] >= TOO_BIG) {
                        curMinSum[id[at]] = TOO_BIG;
                    }
                    ++curDeadChildren[id[at]];
                    int delta = curDeadChildren[id[at]] - (first[id[at] + 1] - first[id[at]]);
                    if (delta >= 0) {
                        if (delta > 0) throw new RuntimeException();
                        maxCost[dest[id[at]]] = Math.max(maxCost[dest[id[at]]], curMinSum[id[at]]);
                        --countByDest[dest[id[at]]];
                        if (countByDest[dest[id[at]]] <= 0) {
                            if (countByDest[dest[id[at]]] < 0) throw new RuntimeException();
                            heap[numHeap++] = dest[id[at]];
                        }
                    }
                }
                at = nextSameSrc[at];
            }
        }

        //stupid();

        for (int i = 0; i < numTypes; ++i) {
            if (minCost[i] < 0) {
                out.println("-1 -1");
            } else {
                out.print(minCost[i]);
                out.print(" ");
                if (countByDest[i] > 0) {
                    out.println(-2);
                } else {
                    out.println(maxCost[i]);
                }
            }
        }
    }

    private void heapDown(int at) {
        while (true) {
            int i = at;
            if (2 * at + 1 < numHeap && curMinSum[heap[2 * at + 1]] < curMinSum[heap[i]]) {
                i = 2 * at + 1;
            }
            if (2 * at + 2 < numHeap && curMinSum[heap[2 * at + 2]] < curMinSum[heap[i]]) {
                i = 2 * at + 2;
            }
            if (i == at) break;
            swap(at, i);
            at = i;
        }
    }

    private void heapUp(int at) {
        while (at > 0) {
            int i = (at - 1) / 2;
            if (curMinSum[heap[i]] > curMinSum[heap[at]]) {
                swap(at, i);
                at = i;
            } else break;
        }
    }

    private void swap(int a, int b) {
        int tmp = heap[a];
        heap[a] = heap[b];
        heap[b] = tmp;
        heapAt[heap[a]] = a;
        heapAt[heap[b]] = b;
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