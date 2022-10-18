import java.io.*;
import java.util.*;
import java.text.*;

public class Main {
    static int p2,v2,p1,v1;
    static int j=0;
    static int[] l1=new int[1000000];
    
    static long d(int a1,int b1,int a2,int b2) {
     int a=Math.max(a1,a2);
     int b=Math.min(b1,b2);
     if (b<a) return 0;
     return b-a+1;
    }
    
    static void dfs(int x) {
        if (x>Math.max(p2,v2)) return;
        if (x>=Math.min(p1,v1)) {j++;l1[j]=x;}
        if (x/100000000==0)  {dfs(x*10+7);
        dfs(x*10+4);}
    }
    
    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
        p1=in.nextInt();
        p2=in.nextInt();
        v1=in.nextInt();
        v2=in.nextInt();
       int k=in.nextInt();
       double n=0;
       dfs(4);
       dfs(7);
       int[] l=new int[j+2];
       for (int i=1;i<=j;i++) l[i]=l1[i];
       l[j+1]=1000000000;
       Arrays.sort(l);
       int g;
       
       if (p1>v1) 
       {
        g=p1; p1=v1; v1=g;
        g=p2; p2=v2; v2=g;
       }
       
      NumberFormat nf = NumberFormat.getInstance();
      nf.setMaximumFractionDigits(20);
      
       for (int a=1;a<=j-k+1;a++)
       {
           int b=a+k-1;
           n+=d(l[a-1]+1,l[a],p1,p2)*d(l[b],l[b+1]-1,v1,v2);
           n+=d(l[a-1]+1,l[a],v1,v2)*d(l[b],l[b+1]-1,p1,p2);
           if (a==b&d(l[a],l[a],v1,v2)>0&d(l[a],l[a],p1,p2)>0) n--;
       }
      n/=(p2-p1+1);
      n/=(v2-v1+1);
      if (n>1) n=1;
      System.out.println(nf.format(n));

    }
}