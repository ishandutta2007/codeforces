import java.io.IOException;
import java.io.InputStreamReader;
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
    static class Fenwick {
        int[] a;
        
        public Fenwick(int n) {
            a = new int[n];
        }
        
        void add(int at, int by) {
            while (at < a.length) {
                a[at] += by;
                at |= (at + 1);
            }
        }
        
        int get(int l, int r) {
            return iget(r) - iget(l - 1);
        }

        private int iget(int r) {
            int sum = 0;
            while (r >= 0) {
                sum += a[r];
                r = (r & (r + 1)) - 1;
            }
            return sum;
        }
    }
    
    static class Maxes {
        int[] mx;
        int n;
        
        public Maxes(int n) {
            this.n = n;
            mx = new int[4 * n + 10];
            Arrays.fill(mx, -1);
        }
        
        void update(int at, int by) {
            internalUpdate(0, 0, n - 1, at, by);
        }

        private void internalUpdate(int root, int rl, int rr, int at, int by) {
            mx[root] = Math.max(mx[root], by);
            if (rl == rr) return;
            int rm = (rl + rr) / 2;
            if (at <= rm)
                internalUpdate(root * 2 + 1, rl, rm, at, by);
            else
                internalUpdate(root * 2 + 2, rm + 1, rr, at, by);
        }
        
        int get(int l, int r) {
            return internalGet(0, 0, n - 1, l, r);
        }

        private int internalGet(int root, int rl, int rr, int l, int r) {
            if (l > r) return -1;
            if (rl == l && rr == r) return mx[root];
            int rm = (rl + rr) / 2;
            return Math.max(internalGet(root * 2 + 1, rl, rm, l, Math.min(r, rm)), internalGet(root * 2 + 2, rm + 1, rr, Math.max(l, rm + 1), r));
        }
    }
    
    static class Person implements Comparable<Person> {
        int r;
        int a;
        int inGroup = 0;

        public int compareTo(Person person) {
            return r - person.r;
        }
    }
    
    static class Pair implements Comparable<Pair> {
        int leaderStart;
        int x;
        int y;
        int aMin;
        int aMax;
        int id;

        public int compareTo(Pair pair) {
            return leaderStart - pair.leaderStart;
        }
    }
    
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        Random random = new Random(4865431L + System.currentTimeMillis());
        int n = in.nextInt();
        int k = in.nextInt();
        Person[] pers = new Person[n];
        for (int i = 0; i < n; ++i) pers[i] = new Person();
        for (int i = 0; i < n; ++i) pers[i].r = in.nextInt();
        for (int i = 0; i < n; ++i) pers[i].a = in.nextInt();
        int q = in.nextInt();
        Pair[] p = new Pair[q];
        for (int i = 0; i < q; ++i) {
            Pair pair = new Pair();
            pair.x = in.nextInt() - 1;
            pair.y = in.nextInt() - 1;
            pair.aMin = Math.max(pers[pair.x].a, pers[pair.y].a) - k;
            pair.aMax = Math.min(pers[pair.x].a, pers[pair.y].a) + k;
            pair.leaderStart = Math.max(pers[pair.x].r, pers[pair.y].r);
            pair.id = i;
            p[i] = pair;
        }
        for (int i = 0; i < q; ++i) {
            int j = i + random.nextInt(q - i);
            Pair tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
        }
        Arrays.sort(p);
        int[] ages = new int[n];
        for (int i = 0; i < n; ++i) {
            ages[i] = pers[i].a;
        }
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            int tmp = ages[i];
            ages[i] = ages[j];
            ages[j] = tmp;
        }
        Arrays.sort(ages);
        int numAges = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || ages[i] > ages[i - 1]) {
                ages[numAges++] = ages[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            int left = -1;
            int right = numAges;
            int need = pers[i].a;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (ages[middle] == need) {
                    pers[i].a = middle;
                    break;
                }
                if (ages[middle] > need)
                    right = middle;
                else
                    left = middle;
            }
            if (right - left == 1) throw new RuntimeException();
        }
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            Person tmp = pers[i];
            pers[i] = pers[j];
            pers[j] = tmp;
        }
        Arrays.sort(pers);
        Fenwick fenwick = new Fenwick(numAges);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && pers[j].r == pers[i].r) ++j;
            for (int kk = i; kk < j; ++kk) {
                fenwick.add(pers[kk].a, 1);
            }
            for (int kk = i; kk < j; ++kk) {
                int needLeft = ages[pers[kk].a] - k;
                int needRight = needLeft + 2 * k;
                int left = -1;
                int right = numAges;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (ages[middle] >= needLeft) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }
                needLeft = right;
                left = -1;
                right = numAges;
                while (right - left > 1) {
                    int middle = (left + right) / 2;
                    if (ages[middle] > needRight) {
                        right = middle;
                    } else {
                        left = middle;
                    }
                }
                needRight = left;
                if (needLeft <= needRight) {
                    pers[kk].inGroup = fenwick.get(needLeft, needRight);
                }
            }
            i = j;
        }
        fenwick = null;
        Maxes maxes = new Maxes(numAges);
        int[] answers = new int[q];
        Arrays.fill(answers, -1);
        int ptr = pers.length - 1;
        for (int qi = q - 1; qi >= 0; --qi) {
            int bound = p[qi].leaderStart;
            while (ptr >= 0 && pers[ptr].r >= bound) {
                maxes.update(pers[ptr].a, pers[ptr].inGroup);
                --ptr;
            }
            int needLeft = p[qi].aMin;
            int needRight = p[qi].aMax;
            int left = -1;
            int right = numAges;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (ages[middle] >= needLeft) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            needLeft = right;
            left = -1;
            right = numAges;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (ages[middle] > needRight) {
                    right = middle;
                } else {
                    left = middle;
                }
            }
            needRight = left;
            answers[p[qi].id] = maxes.get(needLeft, needRight);
        }
        for (int x : answers) out.println(x);
	}
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

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