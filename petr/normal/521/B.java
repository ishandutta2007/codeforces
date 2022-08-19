import java.util.TreeSet;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.List;
import java.io.BufferedReader;
import java.util.Map;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.SortedSet;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Cube implements Comparable<Cube> {
        int number;
        int x;
        int y;
        List<Cube> dependsOn = new ArrayList<>(1);
        List<Cube> dependents = new ArrayList<>(1);
        int numMusts = 0;

        public int compareTo(Cube o) {
            int z = numMusts - o.numMusts;
            if (z != 0) return z;
            return number - o.number;
        }
    }

    static final long MODULO = (long) (1e9 + 9);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int m = in.nextInt();
        Cube[] cubes = new Cube[m];
        Map<Long, Cube> coordToCube = new HashMap<>();
        for (int i = 0; i < m; ++i) {
            cubes[i] = new Cube();
            cubes[i].number = i;
            cubes[i].x = in.nextInt();
            cubes[i].y = in.nextInt();
            long coord = cubes[i].x * (long) 3e9 + cubes[i].y;
            coordToCube.put(coord, cubes[i]);
        }
        for (Cube cube : cubes) {
            if (cube.y > 0) {
                for (int dx = -1; dx <= 1; ++dx) {
                    long ncoord = (cube.x + dx) * (long) 3e9 + (cube.y - 1);
                    Cube under = coordToCube.get(ncoord);
                    if (under != null) {
                        cube.dependsOn.add(under);
                        under.dependents.add(cube);
                    }
                }
                if (cube.dependsOn.isEmpty()) throw new RuntimeException();
                if (cube.dependsOn.size() == 1) {
                    ++cube.dependsOn.get(0).numMusts;
                }
            }
        }
        TreeSet<Cube> all = new TreeSet<>();
        for (Cube cube : cubes) {
            all.add(cube);
        }
        long res = 0;
        Cube specialTail = new Cube();
        specialTail.numMusts = 0;
        specialTail.number = m;
        for (int i = 0; i < m; ++i) {
            Cube toRemove;
            if (i % 2 == 0) {
                toRemove = all.headSet(specialTail).last();
            } else {
                toRemove = all.first();
            }
            if (toRemove.numMusts != 0) throw new RuntimeException();
            all.remove(toRemove);
            res = (res * m + toRemove.number) % MODULO;
            for (Cube upper : toRemove.dependents) {
                upper.dependsOn.remove(toRemove);
                if (upper.dependsOn.size() == 1) {
                    Cube newMust = upper.dependsOn.get(0);
                    all.remove(newMust);
                    ++newMust.numMusts;
                    all.add(newMust);
                }
            }
            for (Cube lower : toRemove.dependsOn) {
                lower.dependents.remove(toRemove);
                if (toRemove.dependsOn.size() == 1) {
                    all.remove(lower);
                    --lower.numMusts;
                    all.add(lower);
                }
            }
        }
        out.println(res);
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