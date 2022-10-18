import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      int[] a=new int[n+1];
      for (int i=1;i<=n;i++)
          a[i]=in.nextInt();
      Arrays.sort(a);
      for (int i=1;i<n;i++)
          if (a[i]<a[i+1]&2*a[i]>a[i+1]) {System.out.println("YES");System.exit(0);}
      System.out.println("NO");
      
    }
}