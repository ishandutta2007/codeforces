
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int m[] = new int [n];
            int p[] = new int [n];
            for(int i = 0;i < n;i++) {
                m[i] = sc.nextInt();
                p[i] = sc.nextInt();
            }

            int pref[] = new int [n];
            ArrayList<Integer> cost[] = new ArrayList[n];
            for(int i = 0;i < n;i++) cost[i] = new ArrayList<>();
            TreeMap<Integer, Integer> a = new TreeMap<>();

            for(int i = 0;i < n;i++) pref[m[i]]++;
            for(int i = 1;i < n;i++) pref[i] += pref[i - 1];
            for(int i = 0;i < n;i++) pref[i] -= i + 1;

            for(int i = 0;i < n;i++) cost[m[i]].add(p[i]);

            int cnt = 0;
            long ans = 0;
            for(int i = n - 1;i >= 0;i--) {
                while (pref[i] < -cnt) {
                    cnt++;
                    ans += a.firstKey();
                    a.put(a.firstKey(), a.firstEntry().getValue() - 1);
                    if (a.firstEntry().getValue() == 0) a.pollFirstEntry();
                }

                for(int j : cost[i]) {
                    if (!a.containsKey(j)) a.put(j, 0);
                    a.put(j, a.get(j) + 1);
                }
            }

            pw.println(ans);

        }
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

class pair implements Comparator<pair>{
    int m, p;
    pair(int x, int y) {
        m = x;
        p = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.m, o2.m) * 2 + Integer.compare(o1.p, o2.p);
    }
}