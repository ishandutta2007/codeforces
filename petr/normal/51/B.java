import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Tables implements Runnable {
    String data;
    int pos;
    List<Integer> res = new ArrayList<Integer>();

    private void solve() throws IOException {
        StringBuilder b = new StringBuilder();
        while (true) {
            try {
                String s = nextToken();
                b.append(s);
            } catch (NullPointerException e) {
                break;
            }
        }
        b.append("$$$$$$$$$");
        data = b.toString();
        pos = 0;
        parseTable();
        check("$");
        Collections.sort(res);
        boolean first = true;
        for (int x : res) {
            if (first) first = false; else writer.print(" ");
            writer.print(x);
        }
        writer.println();
    }

    void eat(String s) {
        if (!data.substring(pos, pos + s.length()).equals(s))
            throw new RuntimeException();
        pos += s.length();
    }

    boolean check(String s) {
        return data.substring(pos, pos + s.length()).equals(s);
    }

    private void parseTable() {
        eat("<table>");
        int total = 0;
        while (check("<tr>")) {
            total += parseRow();
        }
        res.add(total);
        eat("</table>");
    }

    private int parseRow() {
        eat("<tr>");
        int total = 0;
        while (check("<td>")) {
            total += parseCell();
        }
        eat("</tr>");
        return total;
    }

    private int parseCell() {
        eat("<td>");
        if (check("<table>")) {
            parseTable();
        }
        eat("</td>");
        return 1;
    }

    public static void main(String[] args) {
        new Tables().run();
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