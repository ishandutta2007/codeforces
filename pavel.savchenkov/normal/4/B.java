import java.io.*;
import java.util.*;

public class Main {

   
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int d=in.nextInt();
        int s=in.nextInt();
        int[] min=new int[d+1];
        int[] max=new int[d+1];
        int s1=0,s2=0;
        for (int i=1;i<=d;i++) {
            min[i]=in.nextInt();
            max[i]=in.nextInt();
            s1+=min[i];
            s2+=max[i];
        }
        if (s<s1|s>s2) {System.out.println("NO");return;}
        s=s-s1;
        System.out.println("YES");
        for (int i=1;i<=d;i++)
            if (s!=0) {
                System.out.print( Math.min(max[i],min[i]+s)+" " );
                s-=Math.min(max[i]-min[i],s);
            } else System.out.print(min[i]+" ");


        
    }

}