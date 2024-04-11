import java.util.*;
import java.io.*;

public class Main {

    static boolean check(int i){
        while(i!=0){
            if((i%10!=1)&&(i%10!=0))
                return false;
            i/=10;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] dp = new int[n + 1];
        int[] pr = new int[n + 1];
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++)
            if (check(i)) {
               // System.out.println(i);
                a.add(i);
            }
        dp[0]=0;
        for(int i=1;i<=n;i++) {
            dp[i] = 1000000000;
            for (int j : a)
                if (j <= i) {
                    if (dp[i - j] + 1 < dp[i]) {
                        dp[i] = dp[i - j] + 1;
                        pr[i] = j;
                    }
                }
        }
        System.out.println(dp[n]);
        for(int i=n;i!=0;i-=pr[i]){
            System.out.print(pr[i]);
            System.out.print(' ');
        }

    }
}