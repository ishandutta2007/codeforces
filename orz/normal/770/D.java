import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by Admin on 11.03.2017.
 */
public class Brackets {

    public static void main(String[] args) {
        new Brackets().run();
    }

    private void run() {
        IO files = new IO();
        int n = files.nextInt();
        char[] c = files.next().toCharArray();
        int[] balance = new int[n];
        int maxBalance = 0;
        for (int i = 0; i < n - 1; i++) {
            balance[i + 1] = balance[i] + (c[i] == '[' ? 1 : -1);
            if (c[i] == ']') {
                maxBalance = Math.max(maxBalance, balance[i + 1]);
            }
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (c[i] == ']' && c[i - 1] == '[') {
                count++;
            }
        }

        char[][] table = new char[n + 3 * count][3 + maxBalance * 2];
        for (char[] aTable : table) {
            Arrays.fill(aTable, ' ');
        }
        int center = table[0].length / 2;
        int idx = 0;
        for (int i = 0; i < n; i++, idx++) {
            if (c[i] == '[') {
                int d = maxBalance - balance[i] + 1;
                for (int h = center - d + 1; h < center + d; h++) {
                    table[idx][h]= '|';
                }
                table[idx][center - d] = '+';
                table[idx][center + d] = '+';
                table[idx + 1][center - d] = '-';
                table[idx + 1][center + d] = '-';
                if (c[i + 1] == ']') {
                    idx += 3;
                }
            } else {
                int d = maxBalance - balance[i] + 2;
                for (int h = center - d + 1; h < center + d; h++) {
                    table[idx][h]= '|';
                }
                table[idx][center - d] = '+';
                table[idx][center + d] = '+';
                table[idx - 1][center - d] = '-';
                table[idx - 1][center + d] = '-';
            }
        }

        for (int i = 0; i < table[0].length; i++) {
            for (int j = 0; j < table.length; j++) {
                files.out.print(table[j][i]);
            }
            files.out.println();
        }
        files.out.close();
    }

    class IO {
        private BufferedReader in;
        private StringTokenizer st;
        PrintWriter out;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            try {
                return in.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}