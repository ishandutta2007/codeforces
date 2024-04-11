import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int rows = in.nextInt();
            int cols = in.nextInt();
            List<Person> democratic = new ArrayList<>();
            List<Person> republican = new ArrayList<>();
            for (int i = 1; i <= n; ++i) {
                Person p = new Person(i);
                if (i % 2 != 0) {
                    democratic.add(p);
                } else {
                    republican.add(p);
                }
            }
            Seat[][] seats = new Seat[rows][cols];
            List<Seat> white = new ArrayList<>();
            List<Seat> black = new ArrayList<>();
            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    Seat s = new Seat(row, col);
                    seats[row][col] = s;
                    if ((row + col) % 2 == 0) {
                        white.add(s);
                    } else {
                        black.add(s);
                    }
                }
            }
            if (democratic.size() <= white.size() && republican.size() <= black.size()) {
                put(democratic, white);
                put(republican, black);
            } else if (democratic.size() <= black.size() && republican.size() <= white.size()) {
                put(democratic, black);
                put(republican, white);
            } else {
                out.println(-1);
                return;
            }
            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if (col > 0) {
                        out.print(" ");
                    }
                    Seat s = seats[row][col];
                    if (s.taken == null) {
                        out.print(0);
                    } else {
                        out.print(s.taken.index);
                    }
                }
                out.println();
            }
        }

        private void put(List<Person> people, List<Seat> seats) {
            for (int i = 0; i < people.size(); ++i) {
                Person p = people.get(i);
                Seat s = seats.get(i);
                if (s.taken != null) {
                    throw new RuntimeException();
                }
                s.taken = p;
            }
        }

        static class Person {
            int index;

            public Person(int index) {
                this.index = index;
            }

        }

        static class Seat {
            int row;
            int col;
            Person taken;

            public Seat(int row, int col) {
                this.row = row;
                this.col = col;
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

    }
}