import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
/*        Random random = new Random(4037214732111231L);
        while (true) {
            String seq = "";
            for (int i = 0; i < 10; ++i)
                seq = "LXR".charAt(random.nextInt(3)) + seq;
            String res1 = solve1(seq);
            String res2 = solve2(seq);
            if (!res1.equals(res2)) {
                throw new RuntimeException(seq + " " + res1 + " " + res2);
            }
            System.err.print(".");
        }*/
        String seq = nextToken();
        writer.println(solve1(seq));
        /*writer.println(solve2(seq));*/
    }

    int bestp;
    int bestq;

    private String solve2(String seq) {
        bestp = 0;
        bestq = 1;
        rec(seq, 0, 0, 0, 0, seq.charAt(0));
        int p = bestp;
        int q = bestq;
        String s = "" + ((long) p * 100000000 / q);
        while (s.length() < 7)
            s = "0" + s;
        String res = s.substring(0, s.length() - 6) + "." + s.substring(s.length() - 6);
        return res;
    }

    private void rec(String seq, int at, int p0, int p1, int q, char first) {
        if (at > seq.length()) {
            --q;
            int cp;
            int cq;
            if (q % 2 == 0) {
                cp = p0;
                cq = q;
            } else {
                cp = p0 + p1;
                cq = q + q;
            }
            if (cp * (long) bestq > cq * (long) bestp) {
                bestp = cp;
                bestq = cq;
            }
            return;
        }
        int min = 0;
        if (at < seq.length() && at > 0 && seq.charAt(at) == seq.charAt(at - 1) && seq.charAt(at) != 'X')
            min = 1;
        if (at == seq.length() && seq.charAt(at - 1) == first && first != 'X')
            min = 1;
        int max = min + 1;
        if (at < seq.length() && seq.charAt(at) == 'X')
            max = min;
        for (int am = min; am <= max; ++am) {
            int np0 = p0;
            int np1 = p1;
            if (at < seq.length() && seq.charAt(at) == 'L')
                if ((q + am) % 2 == 0)
                    ++np0;
                else
                    ++np1;
            if (at < seq.length() && seq.charAt(at) == 'R')
                if ((q + am) % 2 == 0)
                    ++np1;
                else
                    ++np0;
            if (at == 0 && am > 0)
                first = 'X';
            rec(seq, at + 1, np0, np1, q + am + 1, first);
        }
    }

    private String solve1(String seq) {
        char prev = ' ';
        int p = 0;
        int q = 0;
        int numConsecutiveExtras = 0;
        int maxCheapSavings = 0;
        boolean firstMustBe = false;
        boolean lastMustBe = false;
        boolean inFirst = seq.charAt(0) != 'X';
        for (int i = 0; i < seq.length(); ++i) {
            char ch = seq.charAt(i);
            if (ch == prev && ch != 'X') {
                ++q;
            }
            if (ch != 'X') {
                ++p;
                if (ch == 'L' && q % 2 != 0) {
                    ++q;
                    ++numConsecutiveExtras;
                } else if (ch == 'R' && q % 2 == 0) {
                    ++q;
                    ++numConsecutiveExtras;
                } else {
                    if (numConsecutiveExtras > 0 && numConsecutiveExtras % 2 == 0 && inFirst)
                        firstMustBe = true;
                    maxCheapSavings += numConsecutiveExtras / 2;
                    numConsecutiveExtras = 0;
                    inFirst = false;
                }
            }
            prev = ch;
            ++q;
        }
        if (q % 2 != 0) {
            ++q;
            ++numConsecutiveExtras;
            if (numConsecutiveExtras % 2 == 0)
                lastMustBe = true;
        }
        if (numConsecutiveExtras > 0 && numConsecutiveExtras % 2 == 0 && inFirst) {
            firstMustBe = true;
        }
        maxCheapSavings += numConsecutiveExtras / 2;
        numConsecutiveExtras = 0;
        if ((firstMustBe || seq.charAt(0) != 'R') && (lastMustBe || seq.charAt(0) != 'L') && seq.charAt(0) == seq.charAt(seq.length() - 1) && seq.charAt(0) != 'X') {
            --maxCheapSavings;
        }
        if (p * 2 >= q) {
            p -= maxCheapSavings;
            q -= 2 * maxCheapSavings;
        }
        String s = "" + ((long) p * 100000000 / q);
        while (s.length() < 7)
            s = "0" + s;
        String res = s.substring(0, s.length() - 6) + "." + s.substring(s.length() - 6);
        return res;
    }


    public static void main(String[] args) {
        new Template().run();
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