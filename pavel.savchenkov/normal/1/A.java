import java.io.*;
import java.util.*;

public class Main {
   

    public static void main(String[] args)  {
     Scanner in=new Scanner(System.in);
     long n=in.nextInt();
     long m=in.nextInt();
     long a=in.nextInt();
     long n1,m1;
     n1=n/a; if (n%a!=0) n1++;
     m1=m/a; if (m%a!=0) m1++;
     System.out.println(m1*n1);    
      
}
}