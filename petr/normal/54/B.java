import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Puzzle implements Runnable {
    private void solve() throws IOException {
        int height = nextInt();
        int width = nextInt();
        StringBuilder puzzleBuilder = new StringBuilder();
        for (int i = 0; i < height; ++i) puzzleBuilder.append(nextToken());
        String puzzle = puzzleBuilder.toString();
        int amount = 0;
        int bx = -1;
        int by = -1;
        for (int hblock = 1; hblock <= height; ++hblock) {
            if (height % hblock != 0)
                continue;
            for (int wblock = 1; wblock <= width; ++wblock) {
                if (width % wblock != 0)
                    continue;
                List<String> items = new ArrayList<String>();
                for (int r = 0; r < height; r += hblock)
                    for (int c = 0; c < width; c += wblock) {
                        items.add(getItem(puzzle, height, width, r, c, hblock, wblock));
                    }
                Collections.sort(items);
                boolean ok = true;
                for (int i = 0; i + 1 < items.size(); ++i) {
                    if (items.get(i).equals(items.get(i + 1)))
                        ok = false;
                }
                if (ok) {
                    ++amount;
                    if (bx < 0 || bx * by > hblock * wblock || (bx * by == hblock * wblock && bx > hblock)) {
                        bx = hblock;
                        by = wblock;
                    }
                }
            }
        }
        writer.println(amount);
        writer.println(bx + " " + by);
    }

    private String getItem(String puzzle, int height, int width, int r, int c, int hblock, int wblock) {
        StringBuilder resBuilder = new StringBuilder();
        for (int i = 0; i < hblock; ++i) {
            resBuilder.append(puzzle.substring((r + i) * width + c, (r + i) * width + c + wblock));
        }
        String res = resBuilder.toString();
        String rotated = res;
        rotated = rotate(rotated, hblock, wblock);
        if (hblock == wblock && res.compareTo(rotated) < 0)
            res = rotated;
        rotated = rotate(rotated, wblock, hblock);
        if (res.compareTo(rotated) < 0)
            res = rotated;
        rotated = rotate(rotated, hblock, wblock);
        if (hblock == wblock && res.compareTo(rotated) < 0)
            res = rotated;
        return res;
    }

    private String rotate(String what, int height, int width) {
        StringBuilder res = new StringBuilder();
        for (int r = 0; r < width; ++r)
            for (int c = 0; c < height; ++c) {
                res.append(what.charAt((height - 1 - c) * width + r));
            }
        return res.toString();
    }

    public static void main(String[] args) {
        new Puzzle().run();
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