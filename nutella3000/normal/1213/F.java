import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static int comp(ArrayList<Integer> o1, ArrayList<Integer> o2) {
        try {
            for (int i = 0; i < Math.min(o1.size(), o2.size()); i++) {
                if (o1.get(i).compareTo(o2.get(i)) < 0) return -1;//
                if (o1.get(i).compareTo(o2.get(i)) > 0) return 1;
            }
            return 0;
        }catch (Exception e) {
            while(true);
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int p[] = new int [n];
        int q[] = new int [n];
        int lower[] = new int [n];
        for(int i = 0;i < n;i++) p[i] = nextInt() - 1;

        for(int i = 0;i < n;i++) q[i] = nextInt() - 1;
        int rev_p[] = new int [n];
        for(int i = 0;i < n;i++) rev_p[p[i]] = i;
        for(int i = 1;i < n;i++) {
            lower[q[i]] = Math.max(lower[q[i - 1]], rev_p[q[i - 1]]);
        }
        int ans[] = new int [n];
        int num = 0;
        int last = -1;
        for(int i = 0;i < n;i++) {
            ans[p[i]] = num;
            last = Math.max(lower[p[i]], last);

            if (last <= i && i + 1 < n && num != k - 1) {
                num++;
            }
        }
        if (num < k - 1) pw.println("NO");
        else {
            pw.println("YES");
            for(int i = 0;i < n;i++) pw.print((char)(ans[i] + 'a'));
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}