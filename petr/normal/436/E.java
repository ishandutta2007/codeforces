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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static class Box {
        int one;
        int two;
        int inZeroOne = -1;
        int inZeroTwo = -1;
        int inOneTwo = -1;
        int inOneZero = -1;
        int inTwoOne = -1;
        int state = 0;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int w = in.nextInt();
        Box[] boxes = new Box[n];
        for (int i = 0; i < n; ++i) {
            boxes[i] = new Box();
            boxes[i].one = in.nextInt();
            boxes[i].two = in.nextInt();
        }
        ZeroOneHeap zeroOne = new ZeroOneHeap(boxes);
        ZeroTwoHeap zeroTwo = new ZeroTwoHeap(boxes);
        OneTwoHeap oneTwo = new OneTwoHeap(boxes);
        OneZeroHeap oneZero = new OneZeroHeap(boxes);
        TwoOneHeap twoOne = new TwoOneHeap(boxes);
        for (Box b : boxes) {
            zeroOne.add(b);
            zeroTwo.add(b);
        }
        long res = 0;
        for (int i = 0; i < w; ++i) {
            Box bestZeroOne = zeroOne.peek();
            Box bestZeroTwo = zeroTwo.peek();
            Box bestOneTwo = oneTwo.peek();
            Box bestOneZero = oneZero.peek();
            Box bestTwoOne = twoOne.peek();

            long scoreZeroOne = (bestZeroOne == null ? Long.MAX_VALUE : bestZeroOne.one);
            long scoreOneTwo = (bestOneTwo == null ? Long.MAX_VALUE : bestOneTwo.two - bestOneTwo.one);
            long scoreMagic = (bestZeroTwo == null || bestOneZero == null ? Long.MAX_VALUE : bestZeroTwo.two - bestOneZero.one);
            long scoreMagic2 = (bestZeroTwo == null || bestTwoOne == null ? Long.MAX_VALUE : bestZeroTwo.two - (bestTwoOne.two - bestTwoOne.one));
            if (scoreZeroOne <= scoreOneTwo && scoreZeroOne <= scoreMagic && scoreZeroOne <= scoreMagic2) {
                bestZeroOne.state = 1;
                zeroOne.remove(bestZeroOne);
                zeroTwo.remove(bestZeroOne);
                oneTwo.add(bestZeroOne);
                oneZero.add(bestZeroOne);
                res += scoreZeroOne;
            } else if (scoreOneTwo <= scoreMagic && scoreOneTwo <= scoreMagic2) {
                bestOneTwo.state = 2;
                oneTwo.remove(bestOneTwo);
                oneZero.remove(bestOneTwo);
                twoOne.add(bestOneTwo);
                res += scoreOneTwo;
            } else if (scoreMagic <= scoreMagic2) {
                bestZeroTwo.state = 2;
                bestOneZero.state = 0;
                zeroOne.remove(bestZeroTwo);
                zeroTwo.remove(bestZeroTwo);
                oneTwo.remove(bestOneZero);
                oneZero.remove(bestOneZero);
                zeroOne.add(bestOneZero);
                zeroTwo.add(bestOneZero);
                res += scoreMagic;
            } else {
                bestZeroTwo.state = 2;
                bestTwoOne.state = 1;
                zeroOne.remove(bestZeroTwo);
                zeroTwo.remove(bestZeroTwo);
                twoOne.add(bestZeroTwo);
                twoOne.remove(bestTwoOne);
                oneTwo.add(bestTwoOne);
                oneZero.add(bestTwoOne);
                res += scoreMagic2;

            }
        }
        out.println(res);
        for (int i = 0; i < n; ++i) {
            out.print(boxes[i].state);
        }
        out.println();
    }

    static class ZeroOneHeap {
        Box[] heap;
        int nheap;

        public ZeroOneHeap(Box[] boxes) {
            heap = new Box[boxes.length];
            nheap = 0;
        }

        void add(Box box) {
            box.inZeroOne = nheap;
            heap[nheap++] = box;
            heapUp(nheap - 1);
        }

        Box peek() {
            return nheap == 0 ? null : heap[0];
        }

        void remove(Box box) {
            int where = box.inZeroOne;
            heapSwap(where, nheap - 1);
            --nheap;
            if (nheap > where) {
                heapUp(where);
                heapDown(where);
            }
        }



        void heapUp(int at) {
            while (at > 0) {
                int i = (at - 1) / 2;
                if (heap[i].one <= heap[at].one) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapDown(int at) {
            while (true) {
                int i = at;
                if (2 * at + 1 < nheap && heap[2 * at + 1].one < heap[i].one) i = 2 * at + 1;
                if (2 * at + 2 < nheap && heap[2 * at + 2].one < heap[i].one) i = 2 * at + 2;
                if (i == at) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapSwap(int a, int b) {
            if (a >= nheap || b >= nheap) throw new RuntimeException();
            Box tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
            heap[a].inZeroOne = a;
            heap[b].inZeroOne = b;
        }
    }

    static class ZeroTwoHeap {
        Box[] heap;
        int nheap;

        public ZeroTwoHeap(Box[] boxes) {
            heap = new Box[boxes.length];
            nheap = 0;
        }

        void add(Box box) {
            box.inZeroTwo = nheap;
            heap[nheap++] = box;
            heapUp(nheap - 1);
        }

        Box peek() {
            return nheap == 0 ? null : heap[0];
        }

        void remove(Box box) {
            int where = box.inZeroTwo;
            heapSwap(where, nheap - 1);
            --nheap;
            if (nheap > where) {
                heapUp(where);
                heapDown(where);
            }
        }


        void heapUp(int at) {
            while (at > 0) {
                int i = (at - 1) / 2;
                if (heap[i].two <= heap[at].two) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapDown(int at) {
            while (true) {
                int i = at;
                if (2 * at + 1 < nheap && heap[2 * at + 1].two < heap[i].two) i = 2 * at + 1;
                if (2 * at + 2 < nheap && heap[2 * at + 2].two < heap[i].two) i = 2 * at + 2;
                if (i == at) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapSwap(int a, int b) {
            if (a >= nheap || b >= nheap) throw new RuntimeException();
            Box tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
            heap[a].inZeroTwo = a;
            heap[b].inZeroTwo = b;
        }
    }

    static class OneZeroHeap {
        Box[] heap;
        int nheap;

        public OneZeroHeap(Box[] boxes) {
            heap = new Box[boxes.length];
            nheap = 0;
        }

        void add(Box box) {
            box.inOneZero = nheap;
            heap[nheap++] = box;
            heapUp(nheap - 1);
        }

        Box peek() {
            return nheap == 0 ? null : heap[0];
        }

        void remove(Box box) {
            int where = box.inOneZero;
            heapSwap(where, nheap - 1);
            --nheap;
            if (nheap > where) {
                heapUp(where);
                heapDown(where);
            }
        }

        void heapUp(int at) {
            while (at > 0) {
                int i = (at - 1) / 2;
                if (heap[i].one >= heap[at].one) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapDown(int at) {
            while (true) {
                int i = at;
                if (2 * at + 1 < nheap && heap[2 * at + 1].one > heap[i].one) i = 2 * at + 1;
                if (2 * at + 2 < nheap && heap[2 * at + 2].one > heap[i].one) i = 2 * at + 2;
                if (i == at) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapSwap(int a, int b) {
            if (a >= nheap || b >= nheap) throw new RuntimeException();
            Box tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
            heap[a].inOneZero = a;
            heap[b].inOneZero = b;
        }
    }

    static class OneTwoHeap {
        Box[] heap;
        int nheap;

        public OneTwoHeap(Box[] boxes) {
            heap = new Box[boxes.length];
            nheap = 0;
        }

        void remove(Box box) {
            int where = box.inOneTwo;
            heapSwap(where, nheap - 1);
            --nheap;
            if (nheap > where) {
                heapUp(where);
                heapDown(where);
            }
        }

        void add(Box box) {
            box.inOneTwo = nheap;
            heap[nheap++] = box;
            heapUp(nheap - 1);
        }

        Box peek() {
            return nheap == 0 ? null : heap[0];
        }

        void heapUp(int at) {
            while (at > 0) {
                int i = (at - 1) / 2;
                if (heap[i].two - heap[i].one <= heap[at].two - heap[at].one) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapDown(int at) {
            while (true) {
                int i = at;
                if (2 * at + 1 < nheap && heap[2 * at + 1].two - heap[2 * at + 1].one < heap[i].two - heap[i].one) i = 2 * at + 1;
                if (2 * at + 2 < nheap && heap[2 * at + 2].two - heap[2 * at + 2].one < heap[i].two - heap[i].one) i = 2 * at + 2;
                if (i == at) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapSwap(int a, int b) {
            if (a >= nheap || b >= nheap) throw new RuntimeException();
            Box tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
            heap[a].inOneTwo = a;
            heap[b].inOneTwo = b;

        }
    }

    static class TwoOneHeap {
        Box[] heap;
        int nheap;

        public TwoOneHeap(Box[] boxes) {
            heap = new Box[boxes.length];
            nheap = 0;
        }

        void remove(Box box) {
            int where = box.inTwoOne;
            heapSwap(where, nheap - 1);
            --nheap;
            if (nheap > where) {
                heapUp(where);
                heapDown(where);
            }
        }

        void add(Box box) {
            box.inTwoOne = nheap;
            heap[nheap++] = box;
            heapUp(nheap - 1);
        }

        Box peek() {
            return nheap == 0 ? null : heap[0];
        }

        void heapUp(int at) {
            while (at > 0) {
                int i = (at - 1) / 2;
                if (heap[i].two - heap[i].one >= heap[at].two - heap[at].one) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapDown(int at) {
            while (true) {
                int i = at;
                if (2 * at + 1 < nheap && heap[2 * at + 1].two - heap[2 * at + 1].one > heap[i].two - heap[i].one) i = 2 * at + 1;
                if (2 * at + 2 < nheap && heap[2 * at + 2].two - heap[2 * at + 2].one > heap[i].two - heap[i].one) i = 2 * at + 2;
                if (i == at) break;
                heapSwap(at, i);
                at = i;
            }
        }

        private void heapSwap(int a, int b) {
            if (a >= nheap || b >= nheap) throw new RuntimeException();
            Box tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
            heap[a].inTwoOne = a;
            heap[b].inTwoOne = b;

        }
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