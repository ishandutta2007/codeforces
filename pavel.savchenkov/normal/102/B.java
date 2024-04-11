import java.io.*;
import java.util.*;

public class Main {
    
    static int sum(String s) {
     int a=0;
      for (int i=s.length();i>=1;i--) 
         a+=(int)s.charAt(i-1)-48;

     return a;
        
    }

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        int a;
        if (s.length()==1) {System.out.println("0");System.exit(0);};
        int k=0;
 
        while (1==1) {
         a=sum(s);
         k++;
         if (a<10) {System.out.println(k);break;}
         s=Integer.toString(a);
        }
        
    }
}