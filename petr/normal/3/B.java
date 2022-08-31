import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Lorry implements Runnable {
    static class Thing implements Comparable<Thing> {
        public int id;
        public int capacity;

        Thing(int id, int capacity) {
            this.id = id;
            this.capacity = capacity;
        }

        public int compareTo(Thing thing) {
            return thing.capacity - capacity;
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int v = nextInt();
        List<Thing> ones = new ArrayList<Thing>();
        List<Thing> twos = new ArrayList<Thing>();
        for (int i = 0; i < n; ++i) {
            int t = nextInt();
            int p = nextInt();
            if (t == 1) {
                ones.add(new Thing(i + 1, p));
            } else {
                twos.add(new Thing(i + 1, p));
            }
        }
        Collections.sort(ones);
        Collections.sort(twos);
        int best = -1;
        int by2 = -1;
        int by1 = -1;
        int ofTwos = 0;
        int numOnes = ones.size();
        int ofOnes = 0;
        for (Thing t : ones)
            ofOnes += t.capacity;
        for (int numTwos = 0; numTwos <= twos.size() && 2 * numTwos <= v; ++numTwos) {
            if (numTwos > 0)
                ofTwos += twos.get(numTwos - 1).capacity;
            while (numOnes + 2 * numTwos > v) {
                --numOnes;
                ofOnes -= ones.get(numOnes).capacity;
            }
            if (ofTwos + ofOnes > best) {
                best = ofTwos + ofOnes;
                by2 = numTwos;
                by1 = numOnes;
            }
        }
        writer.println(best);
        boolean first = true;
        for (int i = 0; i < by2; ++i) {
            if (first)
                first = false;
            else
                writer.print(" ");
            writer.print(twos.get(i).id);
        }
        for (int i = 0; i < by1; ++i) {
            if (first)
                first = false;
            else
                writer.print(" ");
            writer.print(ones.get(i).id);
        }
        writer.println();
    }


    public static void main(String[] args) {
        new Lorry().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}