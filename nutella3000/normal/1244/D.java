import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int c[][] = new int [3][n];
        for(int i = 0;i < 3;i++) {
            for(int j = 0;j < n;j++) {
                c[i][j] = sc.nextInt();
            }
        }
        ArrayList<Integer> gr[] = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
        for(int i = 0;i < n;i++) {
            if (gr[i].size() >= 3) {
                System.out.println(-1);
                return;
            }
        }

        int num[] = new int [n];
        int v1 = gr[0].get(0);
        int prev = 0;

        while(v1 != -1) {
            num[v1] = (num[prev] + 1) % 3;
            if (gr[v1].get(0) != prev) {
                prev = v1;
                v1 = gr[v1].get(0);
            }
            else if (gr[v1].size() == 2) {
                prev = v1;
                v1 = gr[v1].get(1);
            }
            else v1 = -1;
        }

        if (gr[0].size() == 2) v1 = gr[0].get(1);

        prev = 0;
        while(v1 != -1) {
            num[v1] = (num[prev] - 1 + 3) % 3;
            if (gr[v1].get(0) != prev) {
                prev = v1;
                v1 = gr[v1].get(0);
            }
            else if (gr[v1].size() == 2) {
                prev = v1;
                v1 = gr[v1].get(1);
            }
            else v1 = -1;
        }


        int p[][] = new int [][]{{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

        int id = 0;
        long ans = (long)1e18;
        for(int i = 0;i < 6;i++) {
            long new_ans = 0;
            for(int j = 0;j < n;j++) {
                new_ans += c[p[i][num[j]]][j];
            }
            if (ans > new_ans) {
                ans = new_ans;
                id = i;
            }
        }

        pw.println(ans);
        for(int i = 0;i < n;i++) {
            pw.print(p[id][num[i]] + 1 + " ");
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

class pair {
    long a, b;
    pair(long a, long b) {
        this.a = a;
        this.b = b;
    }
}