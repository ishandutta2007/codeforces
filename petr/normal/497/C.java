import java.util.Arrays;
import java.util.TreeSet;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Comparator;
import java.io.IOException;
import java.util.SortedSet;
import java.util.Set;
import java.util.StringTokenizer;

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
    static class Aria {
        int left;
        int right;
        int index;
    }

    static class Singer {
        int left;
        int right;
        int capacity;
        int id;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int numArias = in.nextInt();
        Aria[] arias = new Aria[numArias];
        for (int i = 0; i < numArias; ++i) {
            arias[i] = new Aria();
            arias[i].left = in.nextInt();
            arias[i].right = in.nextInt();
            arias[i].index = i;
        }
        int numSingers = in.nextInt();
        Singer[] singers = new Singer[numSingers];
        for (int i = 0; i < numSingers; ++i) {
            singers[i] = new Singer();
            singers[i].left = in.nextInt();
            singers[i].right = in.nextInt();
            singers[i].capacity = in.nextInt();
            if (singers[i].capacity <= 0) throw new RuntimeException();
            singers[i].id = i + 1;
        }
        Arrays.sort(arias, new Comparator<Aria>() {
            public int compare(Aria o1, Aria o2) {
                return o1.left - o2.left;
            }
        });
        Arrays.sort(singers, new Comparator<Singer>() {
            public int compare(Singer o1, Singer o2) {
                return o1.left - o2.left;
            }
        });
        int singerPtr = 0;
        TreeSet<Singer> available = new TreeSet<>(new Comparator<Singer>() {
            public int compare(Singer o1, Singer o2) {
                int z = o1.right - o2.right;
                if (z == 0)
                    z = o1.id - o2.id;
                return z;
            }
        });
        int[] performer = new int[numArias];
        for (Aria aria : arias) {
            while (singerPtr < singers.length && singers[singerPtr].left <= aria.left) {
                available.add(singers[singerPtr++]);
            }
            Singer tmp = new Singer();
            tmp.right = aria.right;
            tmp.id = -1;
            SortedSet<Singer> tail = available.tailSet(tmp);
            if (tail.isEmpty()) {
                out.println("NO");
                return;
            } else {
                Singer who = tail.first();
                performer[aria.index] = who.id;
                --who.capacity;
                if (who.capacity == 0) {
                    available.remove(who);
                }
            }
        }
        out.println("YES");
        for (int i = 0; i < numArias; ++i) {
            if (i > 0) out.print(" ");
            out.print(performer[i]);
        }
        out.println();
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