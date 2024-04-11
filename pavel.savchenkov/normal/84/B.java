import java.io.*;
import java.util.*;

public class Main {

 
    public static void main(String[] args) throws FileNotFoundException {
     Scanner in=new Scanner(System.in);
     long n=in.nextInt();
     long[] d=new long[100001];
     long[] a=new long[100001];
     d[1]=0;
     long m=0;
     int k=1;
     
     for (int i=2;i<=n;i++) {
       d[i]=d[i-1]+i-1;  
     }
     
     a[1]=in.nextInt();
     for (int i=2;i<=n;i++) {
      a[i]=in.nextInt();
      if (a[i]==a[i-1]) 
          k++; else {m+=d[k];k=1;}    
     }
     in.close();
     System.out.print(m+n+d[k]);
    }

}