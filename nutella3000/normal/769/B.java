import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = nextInt();
        w a[] = new w[n];
        for(int i = 0;i < n;i++) a[i] = new w(nextInt(), i);
        Arrays.sort(a, new w());
        ArrayList<Integer> one = new ArrayList<>();
        ArrayList<Integer> two = new ArrayList<>();

        int id = 0;
        int yy = 0;
        for(int i = 0;i < n;i++) if (a[i].id == 0) yy = i;

        if (a[yy].x == 0) {
            System.out.println(-1);
            return;
        }

        while(id < n && a[yy].x != 0) {
            if (id == yy) id++;
            else {
                one.add(1);
                two.add(a[id].id + 1);
                id++;
                a[yy].x--;
            }
        }


        for(int i = 0;i < n;i++) {
            while(a[i].x-- > 0) {
                if (id == n) break;
                if (id == yy) {
                    id++;
                    a[i].x++;
                    continue;
                }
                one.add(a[i].id + 1);
                two.add(a[id++].id + 1);
            }
        }
        if (one.size() != n - 1) pw.println(-1);
        else {
            pw.println(one.size());
            for (int i = 0; i < one.size(); i++) {
                pw.println(one.get(i) + " " + two.get(i));
            }
        }
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

class w implements Comparator<w>{
    int x, id;
    w(int x, int id) {
        this.x = x;
        this.id = id;
    }

    w() {}

    @Override
    public int compare(w w, w t1) {
        return -Integer.compare(w.x, t1.x);
    }
}