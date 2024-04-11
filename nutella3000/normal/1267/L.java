import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int left[], right[];

    static void gfs(int a[]) {
        Deque<Integer> o1 = new ArrayDeque<>();
        Deque<Integer> o2 = new ArrayDeque<>();

        for (int i = 0; i < a.length; i++) {
            while (!o1.isEmpty() && a[o1.getLast()] >= a[i]) o1.pollLast();
            while (!o2.isEmpty() && a[o2.getLast()] >= a[a.length - i - 1]) o2.pollLast();

            if (o1.isEmpty()) left[i] = 0;
            else left[i] = o1.getLast() + 1;

            if (o2.isEmpty()) right[a.length - i - 1] = a.length - 1;
            else right[a.length - i - 1] = o2.getLast() - 1;

            o1.add(i);
            o2.add(a.length - i - 1);
        }

    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int k = sc.nextInt() - 1;
        int a[] = new int[26];
        char temp[] = sc.next().toCharArray();
        for (char i : temp) a[i - 'a']++;

        char ans[][] = new char[n][l];
        int start[] = new int [n];
        int id = 0;
        int let = 0;
        int last_let = 25;

        while (true) {
            while(k - id + 1 <= a[let]) {
                if (start[k] == l) break;

                for(int i = id;i <= k;i++) {
                    ans[i][start[i]++] = (char) (let + 'a');
                    a[let]--;
                }
            }

            if (start[k] == l) break;

            int new_id = id + a[let];

            for (int i = id; i < new_id; i++) ans[i][start[i]++] = (char) (let + 'a');
            a[let] = 0;

            for (int i = new_id - 1; i >= id; i--) {
                for (int j = start[i]; j < l; j++) {
                    while (a[last_let] == 0) last_let--;
                    ans[i][j] = (char) (last_let + 'a');
                    a[last_let]--;
                }
            }

            id = new_id;
            let++;
        }

        for(int i = n - 1;i > k;i--) {
            for(int j = start[i];j < l;j++) {
                while (a[last_let] == 0) last_let--;
                ans[i][j] = (char) (last_let + 'a');
                a[last_let]--;
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < l;j++) pw.print(ans[i][j]);
            pw.println();
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

class pair implements Comparator<pair> {
    int x, id;

    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }

    pair() {
    }

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}