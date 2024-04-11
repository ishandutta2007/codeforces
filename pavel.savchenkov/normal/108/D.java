import java.io.*;
import java.util.*;
import java.text.*;

public class Main {

                        
    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      n--;
      int m=in.nextInt();
      int h=in.nextInt();
      double[] a=new double[150];
      double[] b=new double[150];
      long k=0,s=0;
      for (int i=1;i<=m;i++)
          if (i==h) k=in.nextInt()-1; else s+=in.nextInt();
      
      int j=0;
      for (long i=s-n+1;i<=s-n+k;i++)
                 {j++;a[j]=i;}
      j=0;
      for (long i=s+1;i<=s+k;i++)
                 {j++;b[j]=i;}      
      double q=1;
      for (int i=1;i<=101;i++)
          if (b[i]>0) q*=a[i]/b[i]; else break;
      if (k==0) q=1;
      NumberFormat nf = NumberFormat.getInstance();
      nf.setMaximumFractionDigits(20);
      
      if (s+k<n)  System.out.println("-1"); else System.out.println(nf.format(1-q));
      
    }
}