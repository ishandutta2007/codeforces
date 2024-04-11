import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        long x = sc.nextLong();
        ArrayList<Long> a = new ArrayList<>();
        for(int i = 2;i <= Math.sqrt(x);i++) {
            long q = 1;
            while(x % i == 0) {
                q *= i;
                x /= i;
            }
            if (q != 1) a.add(q);
        }
        if (x != 1) a.add(x);

        long ans1 = -inf;
        long ans2 = (long) 1e15;

        for(int mask = 0;mask < (1 << a.size());mask++) {
            long one = 1;
            long two = 1;
            for(int i = 0;i < a.size();i++) {
                if ((mask & (1 << i)) == 0) one *= a.get(i);
                else two *= a.get(i);
            }
            if (Math.max(one, two) < ans2) {
                ans2 = Math.max(one, two);
                ans1 = Math.min(one, two);
            }
        }
        pw.println(ans1 + " " + ans2);
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

class edge {
    int to, cost, id;
    edge(int to, int cost, int id) {
        this.to = to;
        this.cost = cost;
        this.id = id;
    }

    edge() {}
}