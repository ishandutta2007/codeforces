import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair();
        for(int i = 0;i < n;i++) a[i].a = sc.nextInt();
        for(int i = 0;i < n;i++) a[i].t = sc.nextInt();
        TreeMap<Integer, Integer> b = new TreeMap<>();
        Arrays.sort(a, new Comparator<pair>() {
            @Override
            public int compare(pair o1, pair o2) {
                return -Integer.compare(o1.t, o2.t);
            }
        });

        long ans = 0;
        for(pair i : a) {

            if (b.lowerKey(i.a + 1) != null) {
                int id = b.lowerKey(i.a + 1);

                while (b.higherKey(id) != null && b.higherKey(id) == b.get(id) + id) {
                    b.put(id, b.get(id) + b.higherEntry(id).getValue());
                    b.remove(b.higherKey(id));
                }

                if (b.get(id) + id < i.a) {
                    b.put(i.a, 1);
                }else {

                    ans += (long) (b.get(id) + id - i.a) * i.t;
                    b.put(id, b.get(id) + 1);
                }
            }else b.put(i.a, 1);

        }

        pw.println(ans);


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