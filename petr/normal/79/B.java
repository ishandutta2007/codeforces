import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Field implements Runnable {
    static class Cell implements Comparable<Cell> {
        int row;
        int col;

        Cell(int row, int col) {
            this.row = row;
            this.col = col;
        }

        public int compareTo(Cell cell) {
            if (row != cell.row)
                return row - cell.row;
            else
                return col - cell.col;
        }
    }

    private void solve() throws IOException {
        int height = nextInt();
        int width = nextInt();
        int numBad = nextInt();
        int numTests = nextInt();
        Cell[] bad = new Cell[numBad];
        for (int i = 0; i < numBad; ++i) {
            int row = nextInt();
            int col = nextInt();
            bad[i] = new Cell(row, col);
        }
        Arrays.sort(bad);
        for (int i = 0; i < numTests; ++i) {
            int row = nextInt();
            int col = nextInt();
            Cell cur = new Cell(row, col);
            writer.println(eval(height, width, bad, cur));
        }
    }

    private String eval(int height, int width, Cell[] bad, Cell cur) {
        int numBad = 0;
        for (int i = 0; i < bad.length; ++i) {
            int z = cur.compareTo(bad[i]);
            if (z > 0) ++numBad;
            if (z == 0) return "Waste";
        }
        int index = (cur.row - 1) * width + cur.col - 1 - numBad;
        if (index % 3 == 0) return "Carrots"; else if (index % 3 == 1) return "Kiwis"; else return "Grapes";
    }

    public static void main(String[] args) {
        new Field().run();
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