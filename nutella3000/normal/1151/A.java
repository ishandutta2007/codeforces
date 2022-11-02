import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char a[] = sc.next().toCharArray();
        int ans = inf;
        for(int i = 0;i <= a.length - 4;i++) {
            int sum = 0;
            sum += Math.min((a[i] - 'A'), 26 - (a[i] - 'A'));
            int a1 = (a[i + 1] - 'C' + 26) % 26;
            int a2 = (a[i + 2] - 'T' + 26) % 26;
            int a3 = (a[i + 3] - 'G' + 26) % 26;
            sum += Math.min(a1, 26 - a1) + Math.min(a2, 26 - a2) + Math.min(a3, 26 - a3);
            ans = Math.min(ans, sum);
        }
        pw.print(ans);
        pw.close();
    }
    static int inf = (int)1e9 + 7;
    static PrintWriter pw = new PrintWriter(System.out);
}