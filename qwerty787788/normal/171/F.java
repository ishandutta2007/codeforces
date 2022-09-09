import java.io.*;
import java.util.*;

public class FirstApril {
    FastScanner in;
    PrintWriter out;

    void solve() {
     
        int max = (int) 1e6;
        boolean[] isPrime = new boolean[max];
        Arrays.fill(isPrime, true);
        for (int i = 2; i < max; i++) 
            if (isPrime[i])
                for (int j = 2; j * i < max; j++)
                    isPrime[j * i] = false;
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 10; i < max; i++) {
            if (isPrime[i]) {
                String s = Integer.toString(i);
                String rev = new StringBuffer(s).reverse().toString();
                int x = Integer.parseInt(rev);
                if (isPrime[x] && x != i) {
                    ans.add(i);
                }
            }
        }
        out.println(ans.get(in.nextInt() - 1));
        
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new FirstApril().runIO();
    }
}