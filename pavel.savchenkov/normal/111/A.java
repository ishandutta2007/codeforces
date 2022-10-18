import java.io.*;
import java.util.*; 

public class Main {


    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      long n=in.nextLong();
      long x=in.nextLong();
      long y=in.nextLong();
      
      if ((y-n+1)*(y-n+1)+n-1>=x&(y-n+1)>0) { System.out.println(y-n+1);
      for (int i=1;i<=n-1;i++) System.out.println(1);}
      else System.out.println("-1");
    }
}