
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, l[], r[];
    static long s;

    static boolean f(int mid) {
        long sum = 0;
        int cnt = 0;
        for(int i = 0;i < n;i++) {
            if (r[i] < mid) {
                cnt++;
                sum += l[i];
            }
            if (l[i] >= mid) {
                sum += l[i];
            }
        }
        ArrayList<pair> a = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            if (l[i] < mid && r[i] >= mid) a.add(new pair(l[i], r[i]));
        }
        Collections.sort(a, new pair());
        for(pair i : a) {
            if (cnt < n / 2) {
                sum += i.l;
                cnt++;
            }else sum += mid;
        }
        if (cnt > n / 2) return false;
        return sum <= s;
    }



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            n = sc.nextInt();
            s = sc.nextLong();
            l = new int[n];
            r = new int [n];
            for(int i = 0;i < n;i++) {
                l[i] = sc.nextInt();
                r[i] = sc.nextInt();
            }
            int left = -1;
            int right = inf;
            while(right - left > 1) {
                int mid = (left + right) / 2;
                if (f(mid)) left = mid;
                else right = mid;
            }
            pw.println(left);
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
    int l, r;
    pair(int l, int r) {
        this.l = l;
        this.r = r;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.l, o2.l);
    }
}