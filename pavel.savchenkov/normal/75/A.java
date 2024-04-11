import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       String a="";
       String b="";
       String c="";
       String a1="";
       String b1="";
       String c1="";
       int c2=0,c3;
       int a2=in.nextInt();
       int b2=in.nextInt();
       c2=a2+b2;
       
       a=Integer.toString(a2);
       b=Integer.toString(b2);
       c=Integer.toString(c2);
       
       for (int i=1;i<=a.length();i++) {
           if (a.charAt(i-1)!='0') a1+=a.charAt(i-1);
       }
       for (int i=1;i<=b.length();i++) {
           if (b.charAt(i-1)!='0') b1+=b.charAt(i-1);
       }
       
       for (int i=1;i<=c.length();i++) {
           if (c.charAt(i-1)!='0') c1+=c.charAt(i-1);
       }
       
        a2=Integer.parseInt(a1);
        b2=Integer.parseInt(b1);
        c2=Integer.parseInt(c1);
        if (a2+b2==c2) System.out.println("YES"); else System.out.println("NO");
    }

}