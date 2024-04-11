import java.util.*;
import java.io.*;
import java.util.regex.*;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int n=s.nextInt();
        int k=s.nextInt();
        s.nextLine();
        String a=s.nextLine();
        int[] pre=new int[n+1];
        pre[0]=-1;
        int now=-1;
        for(int i=1;i<=n;i++){
            while(now>=0&&a.charAt(i-1)!=a.charAt(now))
                now=pre[now];
            now++;
            pre[i]=now;
        }
        System.out.print(a);
        for(int i=1;i<k;i++)
            System.out.print(a.substring(pre[n]));
    }
}