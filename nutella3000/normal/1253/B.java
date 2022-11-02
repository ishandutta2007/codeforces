import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        ArrayList<Integer> ans = new ArrayList<>();
        int l = 0;
        TreeSet<Integer> b = new TreeSet<>();
        TreeSet<Integer> c = new TreeSet<>();
        boolean bad = false;
        for(int i = 0;i < n;i++) {
            if (a[i] > 0) {
                c.add(a[i]);
                if (b.contains(a[i])) bad = true;
                b.add(a[i]);
            }
            if (a[i] < 0) {
                if (!c.contains(-a[i])) bad = true;
                else c.remove(-a[i]);
            }
            if (c.isEmpty()) {
                ans.add(i - l + 1);
                l = i + 1;
                b.clear();
            }
        }
        if (!c.isEmpty()) bad = true;
        
        if (bad) pw.println(-1);
        else{
            pw.println(ans.size());
            for(int i : ans) pw.print(i + " ");
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