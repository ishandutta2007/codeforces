import java.io.*;
import java.util.*;

public class Main {
    static int n,m;
    static double x;
    static boolean[] ok=new boolean[256];
    static char[][] a=new char[31][31];

    static void p(int i1,int j1) {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) { 
                    if ( Math.hypot(i1-i,j1-j)<=x ) ok[a[i][j]-32]=true;
            }
        
    }
    
    public static void main(String[] args) throws FileNotFoundException {
      Scanner in=new Scanner(System.in);
       n=in.nextInt();
       m=in.nextInt();
       x=in.nextDouble();
       boolean f=true;;
      String s=in.nextLine();      
      
      for (int i=1;i<=n;i++) {
          s=in.nextLine();
          for (int j=1;j<=m;j++) {
              a[i][j]=s.charAt(j-1);
              if (a[i][j]!='S') ok[s.charAt(j-1)]=true;
          }
      }
      
      int q=in.nextInt();
      s=in.nextLine();
      s=in.nextLine();
      in.close();
      
      
      for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++) 
           if (a[i][j]=='S') {p(i,j);f=false;}
      n=0;

      for (int i=0;i<=q-1;i++) {
          if (!ok[s.charAt(i)]) n++;
          if (s.charAt(i)>97) if (!ok[s.charAt(i)]) {System.out.println("-1");return;}
          if (s.charAt(i)<97) if (!ok[s.charAt(i)+32]|f) {System.out.println("-1");return;}
      }    
      
      System.out.println(n);
          
    }

}