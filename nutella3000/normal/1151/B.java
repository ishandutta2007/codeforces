import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) a[i][j] = sc.nextInt();
        }
        boolean can = false;
        for(int i = 1;i < 1024;i*= 2) {
            int ans[] = new int [n];
            int cnt_ = 0;
            for(int j = 0;j < n;j++) {
                boolean one = false;
                boolean zero = false;
                for(int g = 0;g < m;g++) {
                    if ((a[j][g] & i) == 0) zero = true;
                    else one = true;
                }
                ans[j] = a[j][0];
                if (one) cnt_++;
                if (one && zero && !can) {
                    can = true;
                    ans[j] = -1;
                }
            }
            if (cnt_ % 2 == 1) can = true;
            if (can) {
                int sum = 0;
                pw.println("TAK");
                for(int j = 0;j < n;j++) {
                    if (ans[j] != -1 && (ans[j] & i) != 0) sum++;
                }
                for(int j = 0;j < n;j++) {
                    if (ans[j] != -1) pw.print(1 + " ");
                    else{
                        if (sum % 2 == 0) {
                            for(int g = 0;g < m;g++) {
                                if ((a[j][g] & i) != 0) {
                                    pw.print(g + 1 + " ");
                                    break;
                                }
                            }
                        }else{
                            for(int g = 0;g < m;g++) {
                                if ((a[j][g] & i) == 0) {
                                    pw.print(g + 1 + " ");
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        if (!can) pw.print("NIE");
        pw.close();
    }
    static int inf = (int)1e9 + 7;
    static PrintWriter pw = new PrintWriter(System.out);
}