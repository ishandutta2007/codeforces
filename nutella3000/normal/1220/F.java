import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;

    static int[] pref(int a[]) {
        ArrayDeque<Integer> id = new ArrayDeque<>();
        ArrayDeque<Integer> h = new ArrayDeque<>();
        int res[] = new int [a.length];
        for(int i = 0;i < a.length;i++) {
            while(!id.isEmpty() && a[id.getLast()] > a[i]) {
                id.pollLast();
                int q = h.pollLast();
                if (!h.isEmpty()) {
                    q = Math.max(q, h.pollLast());
                    h.add(q);
                }
            }
            if (!id.isEmpty()) {
                int temp = h.pollLast();
                h.add(temp + 1);
            }


            res[i] = h.size() + 1;
            if (i != 0) res[i] = res[i - 1];

            if (i != 0) res[i] = Math.max(res[i], (h.isEmpty() ? res[i - 1] + 1 : h.peekLast()));

            id.add(i);
            h.add(h.size() + 1);
        }

        return res;
    }

    static int[] reverse(int b[]) {
        int res[] = new int [b.length];
        for(int i = 0;i < b.length;i++) res[i] = b[b.length - i - 1];
        return res;
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        if (n == 1) {
             pw.println(1 + " " + 0);
            return;
        }

        int temp[] = new int [n];
        for(int i = 0;i < n;i++) temp[i] = sc.nextInt();
        int a[] = new int [n - 1];
        int temp1 = 0;

        int id_one = 0;
        for(int i = 0;i < n;i++) if (temp[i] == 1)id_one = i;
        for(int i = id_one + 1;i < n;i++) a[temp1++] = temp[i];
        for(int i = 0;i < id_one;i++) a[temp1++] = temp[i];

        int pref[] = pref(a);
        int suf[] = reverse(pref(reverse(a)));


        int min_id = -1;
        int min = suf[0];

        for(int i = 0;i < pref.length;i++) {
            int num = pref[i];
            if (i != pref.length - 1) num = Math.max(num, suf[i + 1]);

            if (num < min) {
                min = num;
                min_id = i;
            }
        }

        int sec = (id_one + 1 + min_id + 1) % n;

        pw.print(min + 1 + " " + sec);
    }




    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}