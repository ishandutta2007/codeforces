import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        ArrayList<Long> num = new ArrayList<>();
        num.add((long) 1);
        if (k == -1) num.add((long) -1);
        if (Math.abs(k) != 1) {
            long var = 1;
            while(var <= 1e15) {
                var *= k;
                num.add(var);
            }
        }

        long ans = 0;
        int temp[] = new int [n];
        for(int i = 0;i < n;i++) temp[i] = nextInt();
        long pref[] = new long [n];
        pref[0] = temp[0];
        for(int i = 1;i < n;i++) pref[i] = pref[i - 1] + temp[i];

        HashMap<Long, Integer> a = new HashMap<>();
        a.put((long) 0, 1);
        for(int i = 0;i < n;i++) {
            for(long j : num) {
                if (a.containsKey(pref[i] - j)) ans += a.get(pref[i] - j);
            }

            if (!a.containsKey(pref[i])) a.put(pref[i], 0);
            a.put(pref[i], a.get(pref[i]) + 1);
        }

        pw.println(ans);
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