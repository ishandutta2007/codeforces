import java.io.*;
import java.math.BigInteger;
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

    static int first_entry(int a[], int num) {
        for(int i = 0;i < a.length;i++) {
            if (a[i] == num) return i;
        }
        return a.length;
    }

    static int first_entry(ArrayList<Integer> a, int num) {
        for(int i = 0;i < a.size();i++) {
            if (a.get(i) == num) return i;
        }
        return a.size();
    }

    static int first_entry(int a[], int num, int l) {
        for(int i = l;i < a.length;i++) {
            if (a[i] == num) return i;
        }
        return a.length;
    }

    static int first_entry(ArrayList<Integer> a, int num, int l) {
        for(int i = l;i < a.size();i++) {
            if (a.get(i) == num) return i;
        }
        return a.size();
    }

    static int last_entry(int a[], int num) {
        for(int i = a.length - 1;i >= 0;i--) {
            if (a[i] == num) return i;
        }
        return -1;
    }

    static int last_entry(ArrayList<Integer> a, int num) {
        for(int i = a.size() - 1;i >= 0;i--) {
            if (a.get(i) == num) return i;
        }
        return -1;
    }

    static void fill(int a[], int num) {
        for (int i = 0; i < a.length; i++) a[i] = num;
    }





    static int inf = (int) 1e9 + 7;



    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int k = sc.nextInt();
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 2;i <= Math.sqrt(n);i++) {
            while(n % i == 0) {
                if (k == 1) break;
                ans.add(i);
                k--;
                n /= i;
            }
            if (k == 1) break;
        }
        if (n != 1) {
            ans.add(n);
            k--;
        }

        if (k != 0) pw.println(-1);
        else {
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