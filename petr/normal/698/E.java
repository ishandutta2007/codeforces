import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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

    static class TaskE {
        static final int MAX_YEAR = 50000;
        static final int[] DAYS_IN_MONTH = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int second = in.nextInt();
            int minute = in.nextInt();
            int hour = in.nextInt();
            int dayOfWeek = in.nextInt();
            if (dayOfWeek > 0) --dayOfWeek;
            int date = in.nextInt();
            if (date > 0) --date;
            int month = in.nextInt();
            if (month > 0) --month;
            int[] matchingSeconds = new int[24 * 60 * 60];
            {
                int ptr = 0;
                int secondId = 0;
                for (int h = 0; h < 24; ++h) {
                    for (int m = 0; m < 60; ++m) {
                        for (int s = 0; s < 60; ++s) {
                            boolean ok = true;
                            if (hour >= 0 && hour != h) ok = false;
                            if (minute >= 0 && minute != m) ok = false;
                            if (second >= 0 && second != s) ok = false;
                            if (ok) {
                                matchingSeconds[ptr++] = secondId;
                            }
                            ++secondId;
                        }
                    }
                }
                matchingSeconds = Arrays.copyOf(matchingSeconds, ptr);
            }
            int[][] matchingDays = new int[14][];
            for (int yt = 0; yt < 14; ++yt) {
                int[] cur = new int[400];
                int ptr = 0;
                int dw = yt % 7;
                int curDay = 0;
                boolean leap = yt >= 7;
                for (int m = 0; m < 12; ++m) {
                    int max = DAYS_IN_MONTH[m];
                    if (leap && m == 1) ++max;
                    for (int d = 0; d < max; ++d) {
                        boolean ok = false;
                        if (date < 0 && dayOfWeek < 0) ok = true;
                        if (date >= 0 && d == date) ok = true;
                        if (dayOfWeek >= 0 && dw == dayOfWeek) ok = true;
                        if (month >= 0 && month != m) ok = false;
                        if (ok) {
                            cur[ptr++] = curDay;
                        }
                        ++curDay;
                        dw = (dw + 1) % 7;
                    }
                }
                matchingDays[yt] = Arrays.copyOf(cur, ptr);
            }
            int[] yearType = new int[MAX_YEAR];
            long[] yearStart = new long[MAX_YEAR];
            int jan1st = 3;
            long curStart = 0;
            for (int year = 1970; year < MAX_YEAR; ++year) {
                boolean isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
                yearType[year] = (isLeap ? 7 : 0) + jan1st;
                yearStart[year] = curStart;
                if (isLeap) {
                    jan1st = (jan1st + 366) % 7;
                    curStart += 366L * 24 * 60 * 60;
                } else {
                    jan1st = (jan1st + 365) % 7;
                    curStart += 365L * 24 * 60 * 60;
                }
            }
            if (curStart < 1e12) throw new RuntimeException();
            int numTests = in.nextInt();
            outer:
            for (int testId = 0; testId < numTests; ++testId) {
                long t = in.nextLong() + 1;
                int year = 1970;
                while (yearStart[year + 1] <= t) ++year;
                t -= yearStart[year];
                int day = 0;
                while ((day + 1) * 24L * 60 * 60 <= t) ++day;
                t -= day * 24L * 60 * 60;
                for (int d : matchingDays[yearType[year]]) {
                    if (d == day) {
                        for (int s : matchingSeconds) {
                            if (s >= t) {
                                out.println(yearStart[year] + d * 24L * 60 * 60 + s);
                                continue outer;
                            }
                        }
                    } else if (d > day) {
                        out.println(yearStart[year] + d * 24L * 60 * 60 + matchingSeconds[0]);
                        continue outer;
                    }
                }
                ++year;
                while (matchingDays[yearType[year]].length == 0) ++year;
                out.println(yearStart[year] + matchingDays[yearType[year]][0] * 24L * 60 * 60 + matchingSeconds[0]);
            }
        }

    }

    static class InputReader {
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}