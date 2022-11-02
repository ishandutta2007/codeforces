import javax.smartcardio.ATR;
import java.io.*;
import java.util.*;

public class Main {
    public static boolean gl(char h) {
        if (h == 'a' || h == 'o' || h == 'u' || h == 'i' || h == 'e') {
        return true;
        }else{
        return false;
        }
    }
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int b[] = new int [n];
        TreeMap<Integer,Integer> c = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
            if (c.containsKey(b[i])) {
                c.put(b[i],c.get(b[i]) + 1);
            }else{
                c.put(b[i],1);
            }
        }
        Arrays.sort(b);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (c.higherKey(b[i]) != null) {
                if (c.higherEntry(b[i]).getValue() > 1) {
                    c.put(c.higherKey(b[i]),c.higherEntry(b[i]).getValue() - 1);
                }else{
                    c.remove(c.higherKey(b[i]));
                }
                ans++;
            }
        }
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}