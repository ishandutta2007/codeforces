import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n, p, cur, tot = 0;
            n = in.nextInt();
            n--;
            p = in.nextInt();
            cur = 1;
            while (n > 0) {
                n--;
                int tmp = in.nextInt();
                if (tmp == p) {
                    cur++;
                } else {
                    if (tot == 0 || cur == tot) {
                        tot = cur;
                        cur = 1;
                        p = tmp;
                    } else {
                        out.println("NO");
                        return;
                    }
                }
            }
            if (tot > 0 && tot != cur) {
                out.println("NO");
            } else {
                out.println("YES");
            }
        }

    }
}