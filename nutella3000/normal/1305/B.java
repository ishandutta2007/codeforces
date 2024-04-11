import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char h[] = sc.next().toCharArray();
        int n = h.length;
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        int cnt = 0;

        for(int i = 0;i < n;i++) if (h[i] == ')') cnt++;
        for(int i = 0;i < n;i++) {
            if (h[i] == ')') {
                if (a.size() >= cnt) {
                    b.add(i);
                }
                cnt--;
            }else{
                a.add(i);
            }
        }


        cnt = a.size() - b.size();



        while(cnt != 0) {
            cnt--;
            a.remove(a.size() - 1);
        }

        if (a.size() == 0) pw.println(0);
        else {
            pw.println(1);
            pw.println(a.size() + b.size());

            int id1 = 0;
            int id2 = 0;
            while(id1 < a.size() || id2 < b.size()) {
                if (id1 == a.size() || (id2 != b.size() && b.get(id2) < a.get(id1))) pw.print(b.get(id2++) + 1 + " ");
                else pw.print(a.get(id1++) + 1 + " ");
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

class pair {
    int a, t;
    pair(int a, int t) {
        this.a = a;
        this.t = t;
    }

    pair() {}

}