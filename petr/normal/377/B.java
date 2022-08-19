import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
    static class Bug {
        int difficulty;
        int index;

        Bug(int difficulty, int index) {
            this.difficulty = difficulty;
            this.index = index;
        }
    }

    static class Student {
        int ability;
        int cost;
        int index;

        Student(int ability, int cost, int index) {
            this.ability = ability;
            this.cost = cost;
            this.index = index;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        Bug[] a = new Bug[m];
        for (int i = 0; i < m; ++i) a[i] = new Bug(in.nextInt(), i);
        Arrays.sort(a, new Comparator<Bug>() {
            @Override
            public int compare(Bug o1, Bug o2) {
                return o2.difficulty - o1.difficulty;
            }
        });
        Student[] b = new Student[n];
        for (int i = 0; i < n; ++i) b[i] = new Student(in.nextInt(), 0, i);
        for (int i = 0; i < n; ++i) b[i].cost = in.nextInt();
        Arrays.sort(b, new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                return o2.ability - o1.ability;
            }
        });
        int left = 0;
        int right = a.length + 1;
        TreeSet<Student> available = new TreeSet<Student>(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                int z = o1.cost - o2.cost;
                if (z != 0) return z;
                return o1.index - o2.index;
            }
        });
        outer: while (right - left > 1) {
            int days = (left + right) / 2;
            int bPtr = 0;
            long spent = 0;
            available.clear();
            for (int bugId = 0; bugId < a.length; bugId += days) {
                int need = a[bugId].difficulty;
                while (bPtr < b.length && b[bPtr].ability >= need) {
                    available.add(b[bPtr++]);
                }
                if (available.isEmpty()) {
                    left = days;
                    continue outer;
                }
                Student cur = available.pollFirst();
                spent += cur.cost;
                if (spent > s) {
                    left = days;
                    continue outer;
                }
            }
            right = days;
        }
        if (right > a.length) {
            out.println("NO");
        } else {
            out.println("YES");
            int[] res = new int[a.length];
            int days = right;
            int bPtr = 0;
            long spent = 0;
            available.clear();
            for (int bugId = 0; bugId < a.length; bugId += days) {
                int need = a[bugId].difficulty;
                while (bPtr < b.length && b[bPtr].ability >= need) {
                    available.add(b[bPtr++]);
                }
                Student cur = available.pollFirst();
                for (int i = bugId; i < a.length && i < bugId + days; ++i)
                    res[a[i].index] = cur.index + 1;
            }
            for (int i = 0; i < res.length; ++i) {
                if (i > 0) out.print(" ");
                out.print(res[i]);
            }
            out.println();
        }
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