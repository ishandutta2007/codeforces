import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        triple a[] = new triple[n];
        for(int i = 0;i < n;i++) a[i] = new triple();
        for(int i = 0;i < n;i++) a[i].p = sc.nextInt();
        for(int i = 0;i < n;i++) a[i].a = sc.nextInt();
        for(int i = 0;i < n;i++) a[i].b = sc.nextInt();
        Arrays.sort(a, new triple());
        ArrayList<Integer> id[] = new ArrayList[3];
        for(int i = 0;i < 3;i++) id[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            id[a[i].a - 1].add(i);
            id[a[i].b - 1].add(i);
        }
        int ind[] = new int [3];
        for(int m = sc.nextInt();m > 0;m--) {
            int v = sc.nextInt() - 1;
            while(ind[v] < id[v].size() && a[id[v].get(ind[v])].p == inf) ind[v]++;
            if (ind[v] == id[v].size()) pw.println(-1);
            else{
                pw.print(a[id[v].get(ind[v])].p + " ");
                a[id[v].get(ind[v])].p = inf;
            }
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

class triple implements Comparator<triple>{
    int p, a, b;
    triple(int p, int a, int b) {
        this.p = p;
        this.a = a;
        this.b = b;
    }

    triple() {}

    @Override
    public int compare(triple o1, triple o2) {
        return Integer.compare(o1.p, o2.p);
    }
}