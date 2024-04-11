import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static int xr[] = new int[]{0, 1, 0, -1};
    static int yr[] = new int[]{1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int temp = nextInt();
        ArrayDeque<Integer> x[] = new ArrayDeque[n];
        ArrayDeque<Integer> y[] = new ArrayDeque[m];
        for (int i = 0; i < n; i++) x[i] = new ArrayDeque<>();
        for (int i = 0; i < m; i++) y[i] = new ArrayDeque<>();

        ArrayList<Integer> temp1[] = new ArrayList[n];
        ArrayList<Integer> temp2[] = new ArrayList[m];
        for(int i = 0;i < n;i++) temp1[i] = new ArrayList<>();
        for(int i = 0;i < m;i++) temp2[i] = new ArrayList<>();
        for (int i = 0; i < temp; i++) {
            int v_x = nextInt() - 1;
            int v_y = nextInt() - 1;
            temp1[v_x].add(v_y);
            temp2[v_y].add(v_x);
        }
        for (int i = 0; i < n; i++) Collections.sort(temp1[i]);
        for (int i = 0; i < m; i++) Collections.sort(temp2[i]);
        for(int i = 0;i < n;i++) for(int j : temp1[i]) x[i].add(j);
        for(int i = 0;i < m;i++) for(int j : temp2[i]) y[i].add(j);


        /*boolean bad[][] = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j : x[i]) bad[i][j] = true;
        }*/
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bad[i][j]) pw.print(1 + " ");
                else pw.print(0 + " ");
            }
            pw.println();
        }
        pw.flush();*/

        int v_x = 0;
        int v_y = -1;
        int x1 = 0;
        int x2 = n - 1;
        int y1 = -1;
        int y2 = m - 1;

        long num = 0;

        while (true) {

            while(!x[v_x].isEmpty() && x[v_x].getFirst() - 1 < v_y) {
                x[v_x].pollFirst();
            }
            if (!x[v_x].isEmpty() && x[v_x].getFirst() - 1 < y2) y2 = x[v_x].getFirst() - 1;
            if (y2 == v_y) break;

            num += y2 - v_y;
            v_y = y2;
            y1++;

            while(!y[v_y].isEmpty() && y[v_y].getFirst() - 1 < v_x) {
                y[v_y].pollFirst();
            }
            if (!y[v_y].isEmpty() && y[v_y].getFirst() - 1 < x2) x2 = y[v_y].getFirst() - 1;
            if (x2 == v_x) break;
            num += x2 - v_x;
            v_x = x2;
            x1++;

            while(!x[v_x].isEmpty() && x[v_x].getLast() + 1 > v_y) {
                x[v_x].pollLast();
            }
            if (!x[v_x].isEmpty() && x[v_x].getLast() + 1 > y1) y1 = x[v_x].getLast() + 1;
            if (v_y == y1) break;
            num += v_y - y1;
            v_y = y1;
            y2--;

            while(!y[v_y].isEmpty() && y[v_y].getLast() + 1 > v_x) {
                y[v_y].pollLast();
            }
            if (!y[v_y].isEmpty() && y[v_y].getLast() + 1 > x1) x1 = y[v_y].getLast() + 1;
            if (v_x == x1) break;
            num += v_x - x1;
            v_x = x1;
            x2--;
        }
        //pw.println(num);
        if ((long) n * m - num > temp) pw.println("No");
        else pw.println("Yes");

        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}

class point {
    int x, y;

    point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    point() {
    }
}