import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int a[] = new int[4];
    static ArrayList<Integer> ans = new ArrayList<>();

    static void f1(int id) {
        while (a[id] != 0) {
            a[id]--;
            ans.add(id);
            if (id != 0 && a[id - 1] != 0) id--;
            else {
                if (id == 3) break;
                id++;
            }
        }
    }

    static void f2(int id) {
        while (a[id] != 0) {
            a[id]--;
            ans.add(id);
            if (id != 3 && a[id + 1] != 0) id++;
            else {
                if (id == 0) break;
                id--;
            }
        }
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        a = new int[4];
        int b[] = new int[4];
        for (int i = 0; i < 4; i++) {
            a[i] = sc.nextInt();
            b[i] = a[i];
        }

        boolean bad = false;

        for (int id = 0; id < 4; id++) {

            bad = false;
            for (int i = 0; i < 4; i++) a[i] = b[i];
            ans.clear();
            f1(id);

            for (int i = 0; i < 4; i++) if (a[i] != 0) bad = true;

            if (!bad) break;

            for (int i = 0; i < 4; i++) a[i] = b[i];
            ans.clear();
            bad = false;
            f2(id);

            for (int i = 0; i < 4; i++) if (a[i] != 0) bad = true;

            if (!bad) break;
        }


        if (bad) pw.println("NO");
        else {
            pw.println("YES");
            for (int i : ans) pw.print(i + " ");
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