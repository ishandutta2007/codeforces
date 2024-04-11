import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        long p = nextInt();
        long ans[] = new long [n];
        int t[] = new int [n];
        for(int i = 0;i < n;i++) t[i] = nextInt();
        long v_t = 0;

        Deque<Integer> deq = new ArrayDeque<>();
        Deque<Integer> low_id = new ArrayDeque<>();
        TreeSet<Integer> not = new TreeSet<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(t[o1], t[o2]) * 2 + Integer.compare(o1, o2);
            }
        });
        for(int i = 0;i < n;i++) not.add(i);

        TreeSet<Integer> want = new TreeSet<>();

        while(!deq.isEmpty() || !want.isEmpty() || !not.isEmpty()) {

            if (deq.isEmpty()) {
                v_t = t[not.first()];
                int v = not.pollFirst();
                deq.add(v);
                low_id.add(v);

                /*while(!not.isEmpty() && t[not.first()] == v_t) {
                    want.add(not.pollFirst());
                }*/

            }

            //

            v_t += p;

            ans[deq.getFirst()] = v_t;

            while(!not.isEmpty() && t[not.first()] < v_t) {
                int v = not.pollFirst();
                if (low_id.isEmpty() || low_id.getFirst() > v) {
                    low_id.clear();
                    low_id.add(v);
                    deq.add(v);
                }else{
                    want.add(v);
                }
            }

            if (low_id.getFirst().equals(deq.getFirst()))
                low_id.pollFirst();

            deq.pollFirst();

            while(!not.isEmpty() && t[not.first()] == v_t) {
                int v = not.pollFirst();
                want.add(v);
            }

            if (!want.isEmpty() && (low_id.isEmpty() || low_id.getFirst() > want.first())) {
                int v = want.pollFirst();
                low_id.clear();
                low_id.add(v);
                deq.add(v);
            }

        }

        for(long i : ans) pw.print(i + " ");
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