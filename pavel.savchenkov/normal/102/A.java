import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      int m=in.nextInt();
      int[] w=new int[n+1];
      boolean[][] a=new boolean[n+1][n+1];
      int v,u;
      for (int i=1;i<=n;i++)
          w[i]=in.nextInt();
      for (int i=1;i<=m;i++) {
          v=in.nextInt();
          u=in.nextInt();
          a[v][u]=true;
          a[u][v]=true;
      }
      in.close();
      int min=100000000;
      for (int i=1;i<=n;i++)
          for (int j=1;j<=n;j++)
              for (int g=1;g<=n;g++)
                  if (a[i][j]&a[i][g]&a[j][g]&(w[i]+w[g]+w[j]<min)) min=w[i]+w[g]+w[j];
      if (min==100000000) System.out.println("-1"); else
          System.out.println(min);
      
    }
}