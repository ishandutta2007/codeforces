import java.util.*;
import java.io.*;
public class Java {
    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in),32768);
        int n = Integer.parseInt(f.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(f.readLine());
        TreeSet<Integer> ts = new TreeSet<Integer>();
        for(int i = 1; i <= 2*n; i++) ts.add(i);
        long ans = 0;
        for(int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = ts.ceiling(a);
            ts.remove(b);
            ans += b-a;
        }
        System.out.println(ans);
    }
}