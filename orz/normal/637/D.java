import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created by asus on 13.03.2016.
 */
public class D_Jumper {

    public static void main(String[] args) {
        new D_Jumper().run();
    }

    private void run() {
        IO files = new IO();
        int n = files.nextInt(), m = files.nextInt(), s = files.nextInt(), d = files.nextInt();

        int[] bars = new int[n];
        for (int i = 0; i < n; i++) {
            bars[i] = files.nextInt();
        }
        Arrays.sort(bars);

        if (bars[0] <= s) {
            files.println("IMPOSSIBLE");
            files.close();
            return;
        }

        boolean[] allowed = new boolean[n];
        for (int i = 1; i < n; i++) {
            if (bars[i] - bars[i - 1] >= s + 2) {
                allowed[i - 1] = true;
            }
        }

        ArrayList<Action> actions = new ArrayList<>();
        int i = 0;
        while (i < n) {
            int begin = bars[i] - 1, end;
            actions.add(new Action(0, begin));
            while (i < n && !allowed[i]) {
                i++;
            }
            if (i < n) {
                end = bars[i] + 1;
            } else {
                end = bars[n - 1] + 1;
            }
            actions.add(new Action(1, end));
            if (end - begin > d) {
                files.println("IMPOSSIBLE");
                files.close();
                return;
            }
            i++;
            while (i < n && allowed[i]) {
                actions.add(new Action(0, bars[i] - 1));
                actions.add(new Action(1, bars[i] + 1));
                i++;
            }
        }
        actions.add(new Action(0, m));

        int prev = 0;
        for (Action action : actions) {
            if (action.end - prev > 0) {
                files.print(action.type == 0 ? "RUN " : "JUMP ");
                files.println(action.end - prev);
            }
            prev = action.end;
        }
        files.close();
    }

    private class Action {
        int type, end;

        public Action(int type, int end) {
            this.type = type;
            this.end = end;
        }
    }

    private class IO {
        BufferedReader in;
        PrintWriter out;
        StringTokenizer st;

        public IO(String name) {
            try {
                in = new BufferedReader(new FileReader(name + ".in"));
                out = new PrintWriter(name + ".out");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public IO() {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }

        String nextLine() {
            String s = null;
            while (s == null) {
                try {
                    s = in.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return s;
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

        int nextInt() {
            return Integer.parseInt(next());
        }

        void print(Object s) {
            out.print(s);
        }

        void println(Object s) {
            out.println(s);
        }

        void close() {
            out.close();
        }
    }

}