import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt() - 1;
        }
        boolean[] z = new boolean[n];
        List<List<Integer>> c = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!z[i]) {
                int j = i;
                List<Integer> cc = new ArrayList<>();
                while (!z[j]) {
                    z[j] = true;
                    cc.add(j + 1);
                    j = p[j];
                }
                c.add(cc);
            }
        }
        Collections.sort(c, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
                return Integer.compare(o1.size(), o2.size());
            }
        });
        if (c.get(0).size() == 2) {
            for (int i = 1; i < c.size(); i++) {
                if (c.get(i).size() % 2 > 0) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
            out.println(c.get(0).get(0) + " " + c.get(0).get(1));
            for (int i = 1; i < c.size(); i++) {
                for (int j = 0; j < c.get(i).size(); j++) {
                    out.println(c.get(i).get(j) + " " + c.get(0).get(j % 2));
                }
            }
        } else if (c.get(0).size() == 1) {
            out.println("YES");
            for (int i = 1; i < c.size() ; i++) {
                for (int j = 0; j < c.get(i).size(); j++) {
                    out.println(c.get(i).get(j) + " " + c.get(0).get(0));
                }
            }
        } else {
            out.println("NO");
        }
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}