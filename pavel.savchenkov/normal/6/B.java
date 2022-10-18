import java.io.*;
import java.util.*;


public class Main {
    static char[][] a=new char[101][101];
    static boolean[][] mark=new boolean[101][101];
    static boolean[] q=new boolean[100];  
    
    static int ok(int i,int j,char c,int n,int m) {
        int k=0;
        if (i-1>=1) 
            if (a[i-1][j]!=c&a[i-1][j]!='.'&!mark[i-1][j]&!q[a[i-1][j]]) {k++;mark[i-1][j]=true;q[a[i-1][j]]=true;}
        if (i+1<=n) 
            if (a[i+1][j]!=c&a[i+1][j]!='.'&!mark[i+1][j]&!q[a[i+1][j]]) {k++;mark[i+1][j]=true;q[a[i+1][j]]=true;}
        if (j+1<=m) 
            if (a[i][j+1]!=c&a[i][j+1]!='.'&!mark[i][j+1]&!q[a[i][j+1]]) {k++;mark[i][j+1]=true;q[a[i][j+1]]=true;}
         if (j-1>=1) 
            if (a[i][j-1]!=c&a[i][j-1]!='.'&!mark[i][j-1]&!q[a[i][j-1]]) {k++;mark[i][j-1]=true;q[a[i][j-1]]=true;}
        
        return k;
        
    }

    public static void main(String[] args) throws FileNotFoundException {
       Scanner in=new Scanner(System.in);
       int n=in.nextInt();
       int m=in.nextInt();
       String s=in.nextLine();
       char c=s.charAt(1);
       int k=0;
       for (int i=1;i<=n;i++) {
           s=in.nextLine();
           for (int j=1;j<=m;j++)
               a[i][j]=s.charAt(j-1);
       }
       in.close();
       
       for (int i=1;i<=n;i++)
           for (int j=1;j<=m;j++)
               if (a[i][j]==c) k+=ok(i,j,c,n,m);
       
       System.out.println(k);
       
    }

}