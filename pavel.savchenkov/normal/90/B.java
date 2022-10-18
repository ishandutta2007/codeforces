import java.io.*;
import java.util.*;

public class Main {
    static char[][] a=new char[201][201];
    static int[] col=new int[300];
 //   static boolean[][] ok=new boolean[201][201];
    static int[][] str=new int[200][300];
    static int[][] stolb=new int[200][300];
 
 public static void main(String args[]) throws FileNotFoundException {
  Scanner in=new Scanner(/*new FileReader("input.txt"));*/System.in);
  int n=in.nextInt();
  int m=in.nextInt();
  String s=in.nextLine();
  for (int i=1;i<=n;i++) {
      s=in.nextLine();
      for (int j=1;j<=m;j++) {
          a[i][j]=s.charAt(j-1);
          str[i][a[i][j]]++;//; str[i][a[i][j]]=true; else str[i][a[i][j]]=false;
          stolb[j][a[i][j]]++;//stolb[j][a[i][j]]=true; else stolb[j][a[i][j]]=false;
          }
      }//
  
  for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
          if (str[i][a[i][j]]==1&stolb[j][a[i][j]]==1) System.out.print(a[i][j]);  
  }

  
}