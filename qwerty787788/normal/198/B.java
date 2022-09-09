import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Solution {
    FastScanner in;
    PrintWriter out;

    class to {
        int x;
        int y;
        int time;
        to(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }
    
    int n, k;
    String s1, s2;
    boolean[] was1;
    boolean[] was2;
    boolean ok;
    
    public void solve() throws IOException {
        n = in.nextInt();
        k = in.nextInt();
        ok = false;
        s1 = in.next();
        s2 = in.next();
        was1 = new boolean[n];
        was2 = new boolean[n];
        was1[0] = true;
        ArrayList<to> a = new ArrayList<Solution.to>();
        int now = 0;
        a.add(new to(0, 0, 0));
        while (now < a.size()) {
            to t = a.get(now);
            if (t.y + k >= n) {
                ok = true;
                break;
            }
            if (t.x == 0) {
                if (s1.charAt(t.y + 1) == '-') 
                    if (!was1[t.y + 1]) {
                        a.add(new to(t.x, t.y + 1, t.time + 1));
was1[t.y + 1] = true;                       
}
                if (t.y > 0 && t.y - 1 > t.time && s1.charAt(t.y - 1) == '-') 
                    if (!was1[t.y - 1]) {
                        a.add(new to(t.x, t.y - 1, t.time + 1));
was1[t.y - 1] = true;
}
                if (s2.charAt(t.y + k) == '-') 
                    if (!was2[t.y + k]) {
                        a.add(new to(1 - t.x, t.y + k, t.time + 1));
was2[t.y + k] = true;
}
            } else {
                if (s2.charAt(t.y + 1) == '-') 
                    if (!was2[t.y + 1]) {
                        a.add(new to(t.x, t.y + 1, t.time + 1));
was2[t.y + 1] = true;
}
                if (t.y > 0 && t.y - 1 > t.time && s2.charAt(t.y - 1) == '-') 
                    if (!was2[t.y - 1]) {
                        a.add(new to(t.x, t.y - 1, t.time + 1));
was2[t.y - 1] = true;
}
                if (s1.charAt(t.y + k) == '-') 
                    if (!was1[t.y + k]) {
                        a.add(new to(1 - t.x, t.y + k, t.time + 1));
was1[t.y + k] = true;
}
            }           
            now++;
        }
        if (ok) out.println("YES"); else 
            out.println("NO");
    }

    public void run() {
        try {
            //in = new FastScanner(new File("input.txt"));
            //out = new PrintWriter(new File("output.txt"));

            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    String s = br.readLine();
                    if (s == null) return s;
                    st = new StringTokenizer(s);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return null;
        }
    }

    public static void main(String[] arg) {
        new Solution().run();
    }
}