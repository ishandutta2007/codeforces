import java.io.*;
import java.util.*;

public class Main {
    

    
    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
       int x,y=0,m;
        while (n%4!=0&n!=0) {  
         n-=7;
         y++;
        }
        
        if (n<0) {System.out.println("-1");System.exit(0);}
        
        if (n==0) x=0; else x=n/4;
        m=x/7;
        x-=m*7;
        y+=m*4;
        {
               for (int i=1;i<=x;i++)
                   System.out.print("4");
               for (int i=1;i<=y;i++)
                   System.out.print("7");              
           }
       
              
    }
}