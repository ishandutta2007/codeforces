import java.io.*;
import java.util.*;

public class Main {
    static int[] d=new int[1001];
    static int[] w=new int[1001];
    static int n,p,k=0;
    static boolean[] bak=new boolean[1001];
    
    static void dfs(int v,int u,int min) {
        if (d[u]>0) {
         if (w[u]<min) dfs(v,d[u],w[u]); else dfs(v,d[u],min);  
        } else System.out.println(v+" "+u+" "+min);
        
    }
    
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
         n=in.nextInt();
         p=in.nextInt();
        for (int i=1;i<=p;i++)
        {
        int a=in.nextInt();
        int b=in.nextInt();
        int c=in.nextInt();
        d[a]=b;
        w[a]=c;
        bak[a]=true;
        k++;
        }
        for (int i=1;i<=n;i++)
            if (bak[d[i]]) {bak[d[i]]=false;k--;}
        
        System.out.println(k);
        for (int i=1;i<=n;i++)
            if (bak[i]) dfs(i,i,1000001); 
             
    }
}