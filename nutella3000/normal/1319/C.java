import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        sc = new Fast_Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int next[] = new int[n];
        for(int i = 0;i < n;i++) next[i] = i;

        char h[] = sc.next().toCharArray();
        TreeMap<Integer, Integer> a = new TreeMap<>();

        for(int i = 0;i < n;i++) {
            a.put(i, h[i] - 'a');
        }

        int ans = 0;

        for(int i = 25;i >= 0;i--) {
            for(int j = 0;j < n;j++) {
                if (!a.containsKey(j) || !a.get(j).equals(i)) continue;
                if ((a.higherKey(j) != null && a.higherEntry(j).getValue()== i - 1)  ||
                        (a.lowerKey(j) != null && a.lowerEntry(j).getValue() == i - 1)) {
                    ans++;
                    a.remove(j);
                }
            }

            for(int j = n- 1;j >= 0;j--) {
                if (!a.containsKey(j) || !a.get(j).equals(i)) continue;
                if ((a.higherKey(j) != null && a.higherEntry(j).getValue()== i - 1)  ||
                        (a.lowerKey(j) != null && a.lowerEntry(j).getValue() == i - 1)) {
                    ans++;
                    a.remove(j);
                }
            }
        }

        pw.println(ans);

        pw.close();
    }


    static Fast_Scanner sc;
    static PrintWriter pw;

    static class Fast_Scanner {
        static BufferedReader br;
        static StringTokenizer st = new StringTokenizer("");

        Fast_Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Fast_Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        Double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }


}