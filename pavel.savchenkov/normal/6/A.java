import java.io.*;
import java.util.*;


public class Main {
    static String s="IMPOSSIBLE";
  
    static void ok(int a,int b,int c) {
     int[] w=new int[4];
     int max=1,n=0;
     w[1]=a; w[2]=b; w[3]=c;
     for (int i=1;i<=3;i++)
         if (w[i]>w[max]) max=i;
     for (int i=1;i<=3;i++)
         if (i!=max) n+=w[i];
     if (n==w[max]&s.equals("IMPOSSIBLE")) s="SEGMENT";
     if (n>w[max]) s="TRIANGLE";
    }
    
    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int a=in.nextInt();
      int b=in.nextInt();
      int c=in.nextInt();
      int d=in.nextInt();
      ok(a,b,c);
      ok(a,b,d);
      ok(b,c,d);
      ok(c,a,d);
      System.out.println(s);
      in.close();
    }

}