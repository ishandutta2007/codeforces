import java.io.*;
import java.util.*;

public class Main {
    static int max(int a[]) {
        int ans = Integer.MIN_VALUE;
        for (int i : a) ans = Math.max(ans, i);
        return ans;
    }

    static int max(ArrayList<Integer> a) {
        int ans = Integer.MIN_VALUE;
        for (int i : a) ans = Math.max(ans, i);
        return ans;
    }

    static int min(int a[]) {
        int ans = Integer.MAX_VALUE;
        for (int i : a) ans = Math.min(ans, i);
        return ans;
    }

    static int min(ArrayList<Integer> a) {
        int ans = Integer.MAX_VALUE;
        for (int i : a) ans = Math.min(ans, i);
        return ans;
    }

    static int cnt(int a[], int num) {
        int ans = 0;
        for (int i : a) if (i == num) ans++;
        return ans;
    }

    static int cnt(ArrayList<Integer> a, int num) {
        int ans = 0;
        for (int i : a) if (i == num) ans++;
        return ans;
    }

    static int cnt(boolean a[]) {
        int ans = 0;
        for (int i = 0; i < a.length; i++) if (a[i]) ans++;
        return ans;
    }

    static void fill(int a[], int num) {
        for (int i = 0; i < a.length; i++) a[i] = num;
    }


    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        TreeMap<String, Integer> a = new TreeMap<>();
        for(int i = 0;i < n;i++) {
            String s = sc.next();
            if (!a.containsKey(s)) {
                pw.println("OK");
                a.put(s, 1);
            }else{
                pw.println(s + a.get(s));
                a.put(s, a.get(s) + 1);
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