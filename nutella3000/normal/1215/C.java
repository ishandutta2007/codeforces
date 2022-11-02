import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        char a[] = sc.next().toCharArray();
        char b[] = sc.next().toCharArray();
        ArrayList<Integer> id1 = new ArrayList<>(), id2 = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            if (a[i] == 'a' && b[i] == 'b') id1.add(i);
            if (a[i] == 'b' && b[i] == 'a') id2.add(i);
        }

        ArrayList<Integer> left = new ArrayList<>(), right = new ArrayList<>();

        while(id1.size() >= 2) {
            int q1 = id1.get(id1.size() - 1);
            int q2 = id1.get(id1.size() - 2);
            id1.remove(id1.size() - 1);
            id1.remove(id1.size() - 1);

            left.add(q1);
            right.add(q2);
        }

        while(id2.size() >= 2) {
            int q1 = id2.get(id2.size() - 1);
            int q2 = id2.get(id2.size() - 2);
            id2.remove(id2.size() - 1);
            id2.remove(id2.size() - 1);

            left.add(q1);
            right.add(q2);
        }

        if (id1.size() != id2.size()) pw.println(-1);
        else{
            if (id1.size() == 1) {
                int q1 = id1.get(0);
                int q2 = id2.get(0);

                left.add(q1);
                right.add(q1);
                left.add(q1);
                right.add(q2);
            }

            pw.println(left.size());

            for(int i = 0;i < left.size();i++) {
                pw.println((left.get(i) + 1) + " " + (right.get(i) + 1));
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

class edge {
    int to, id;
    edge(int to, int id) {
        this.to = to;
        this.id = id;
    }

    edge() {}
}