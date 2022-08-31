import java.util.List;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.SortedSet;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.util.Collection;
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

    static Segment tmp = new Segment();
    static Segment tmp2 = new Segment();

    static class Segment implements Comparable<Segment> {
        int left;
        int right;
        int maxGen;
        TreeSet<Segment> children = new TreeSet<Segment>();
        Segment assignedTo;

        public int compareTo(Segment o) {
            return left - o.left;
        }

        Segment getAssigment() {
            if (assignedTo == null) return this;
            assignedTo = assignedTo.getAssigment();
            return assignedTo;
        }

        public void mergeInside(int x) {
            tmp.left = x;
            NavigableSet<Segment> before = children.headSet(tmp, false);
            if (!before.isEmpty()) {
                Segment c = before.last();
                if (c.right > x) {
                    c.mergeInside(x);
                    children.remove(c);
                    merge(this, c);
                }
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Segment[] s = new Segment[n];
        int cnt = 0;
        TreeSet<Segment> topLevel = new TreeSet<Segment>();
        List<Segment> td = new ArrayList<Segment>();
        int maxlen = 0;
        for (int i = 0; i < n; ++i) {
            int kind = in.nextInt();
            if (kind == 1) {
                int x = in.nextInt();
                int y = in.nextInt();
                if (y - x <= maxlen) throw new RuntimeException();
                maxlen = y - x;
                tmp.left = x;
                NavigableSet<Segment> before = topLevel.headSet(tmp, false);
                Segment containingX = null;
                if (!before.isEmpty()) {
                    containingX = before.last();
                    if (containingX.right <= x) {
                        containingX = null;
                    }
                }
                tmp.left = y;
                before = topLevel.headSet(tmp, false);
                Segment containingY = null;
                if (!before.isEmpty()) {
                    containingY = before.last();
                    if (containingY.right <= y) {
                        containingY = null;
                    }
                }
                Segment cur = new Segment();
                cur.left = x;
                cur.right = y;
                cur.maxGen = i;
                if (containingX != null)
                    merge(cur, containingX);
                if (containingY != null)
                    merge(cur, containingY);
                tmp2.left = cur.left - 1;
                NavigableSet<Segment> toDelete = before.tailSet(tmp2, false);
                td.clear();
                td.addAll(toDelete);
                for (Segment u : td) {
                    topLevel.remove(u);
                    if (u != containingX && u != containingY)
                        cur.children.add(u);
                }
                cur.mergeInside(x);
                cur.mergeInside(y);
                topLevel.add(cur);
                s[cnt++] = cur;
            } else {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                Segment sa = s[a].getAssigment();
                Segment sb = s[b].getAssigment();
                if ((sa.left >= sb.left && sa.right <= sb.right) && (sa.maxGen <= sb.maxGen)) {
                    out.println("YES");
                } else {
                    out.println("NO");
                }
            }
        }
    }

    private static void merge(Segment cur, Segment other) {
        cur.left = Math.min(cur.left, other.left);
        cur.right = Math.max(cur.right, other.right);
        other.assignedTo = cur;
        if (cur.children.size() > other.children.size()) {
            for (Segment s : other.children)
                cur.children.add(s);
        } else {
            TreeSet<Segment> tmp = cur.children;
            cur.children = other.children;
            for (Segment s : tmp)
                cur.children.add(s);
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