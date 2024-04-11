import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        w a[] = new w[n];
        int b[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = new w(nextInt(), i + 1);
        }
        for(int i = 0;i < n;i++) b[i] = nextInt();
        Arrays.sort(a, new w());
        Arrays.sort(b);
        long sum = 0;
        for(int i = 0;i < n;i++) {
            sum += a[i].a - b[i];
        }
        if (sum != 0) pw.println("NO");
        else{
            ArrayList<Integer> ans1 = new ArrayList<>();
            ArrayList<Integer> ans2 = new ArrayList<>();
            ArrayList<Integer> ans3 = new ArrayList<>();
            int x[] = new int [n];
            int id[] = new int [n];
            for(int i = 0;i < n;i++) {
                x[i] = b[i] - a[i].a;
                id[i] = a[i].id;
            }
            boolean can = true;
            Deque<Integer> ind = new ArrayDeque<>();
            for(int i = 0;i < n;i++) {
                if (x[i] < 0) ind.add(i);
            }
            for(int i = 0;i < n;i++) {
                if (x[i] < 0) can = false;
                if (x[i] <= 0) continue;
                while(x[i] != 0) {
                    if (ind.isEmpty()) {
                        can = false;
                        break;
                    }
                    ans1.add(id[i]);
                    ans2.add(id[ind.getFirst()]);
                    int min = Math.min(x[i], -x[ind.getFirst()]);
                    ans3.add(min);
                    x[i] -= min;
                    x[ind.getFirst()] += min;
                    if (x[ind.getFirst()] == 0) {
                        ind.removeFirst();
                    }
                }
            }
            if (!can) {
                pw.println("NO");
            }else {
                pw.println("YES");
                pw.println(ans1.size());
                for (int i = 0; i < ans1.size(); i++) {
                    pw.println(ans1.get(i) + " " + ans2.get(i) + " " + ans3.get(i));
                }
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
class w implements Comparator<w>{
    int a, id;
    w(int a, int ind) {
        this.a =a;
        id = ind;
    }
    w() {}

    @Override
    public int compare(w w, w t1) {
        return Integer.compare(w.a, t1.a);
    }
}