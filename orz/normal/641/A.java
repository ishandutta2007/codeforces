/**
 * Created by  on 24.04.2016.
 */

import java.io.*;
import java.util.*;

public class Jumper {

    public static void main(String[] args) {
        new Jumper().run();
    }

    private void run() {
        IO std = new IO();
        int n = std.nextInt();
        int[] move = new int[n];
        char[] dir = std.next().toCharArray();
        for (int i = 0; i < n; i++) {
            if (dir[i] == '<') {
                move[i] = -1;
            } else {
                move[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            move[i] *= std.nextInt();
        }

        boolean[] visited = new boolean[n];
        int t = 0;
        while (!visited[t]) {
            visited[t] = true;
            if (t + move[t] < 0 || t + move[t] >= n) {
                std.print("FINITE");
                std.close();
                return;
            } else {
                t += move[t];
            }
        }

        std.print("INFINITE");
        std.close();
    }

    private class IO {
        BufferedReader in;
        PrintWriter out;
        StringTokenizer st;

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out, true);
        }

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public void print(Object o) {
            out.print(o);
        }

        public void println(Object o) {
            out.println(o);
        }

        public void close() {
            out.close();
        }
    }

}