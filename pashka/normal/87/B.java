import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by IntelliJ IDEA.
 * User: pashka
 * Date: 05.06.2011
 * Time: 14:02:47
 * To change this template use File | Settings | File Templates.
 */
public class B {
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;


    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private void solve() throws IOException {
        int n = nextInt();
        Map<String, Integer> var = new HashMap<String, Integer>();
        for (int i = 0; i < n; i++) {
            String op = next();
            if (op.equals("typedef")) {
                List<String> s = new ArrayList<String>();
                while (st.hasMoreTokens()) s.add(st.nextToken());
                String a = "";
                for (int j = 0; j < s.size() - 1; j++) {
                    a += s.get(j);
                }
                String b = s.get(s.size() - 1);
                int l = 0;
                while (a.charAt(l) == '&') l++;
                int r = 0;
                while (a.charAt(a.length() - r - 1) == '*') r++;
                String aa = a.substring(l, a.length() - r);
                Integer c;
                if (aa.equals("errtype")) {
                    c = -1;
                } else if (aa.equals("void")) {
                    c = 0;
                } else {
                    c = var.get(aa);
                }
                if (c == null) c = -1;
                if (c >= 0){
                    c = c + r - l;
                }
                var.put(b, c);
            } else {
                List<String> s = new ArrayList<String>();
                while (st.hasMoreTokens()) s.add(st.nextToken());
                String a = "";
                for (int j = 0; j < s.size(); j++) {
                    a += s.get(j);
                }
                int l = 0;
                while (a.charAt(l) == '&') l++;
                int r = 0;
                while (a.charAt(a.length() - r - 1) == '*') r++;
                String aa = a.substring(l, a.length() - r);
                Integer c;
                if (aa.equals("errtype")) {
                    c = -1;
                } else if (aa.equals("void")) {
                    c = 0;
                } else {
                    c = var.get(aa);
                }
                if (c == null) c = -1;
                if (c >= 0){
                    c = c + r - l;
                }
                if (c < 0) {
                    out.println("errtype");
                } else {
                    out.print("void");
                    for (int j = 0; j < c; j++) out.print("*");
                    out.println();
                }
            }

        }

        //To change body of created methods use File | Settings | File Templates.
    }
}