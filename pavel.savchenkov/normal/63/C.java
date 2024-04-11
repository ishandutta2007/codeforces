import java.io.*;
import java.util.*;

public class Main {
    static boolean[] w=new boolean[10000];
    
    static byte bi(int i,int x) {
        byte g=0;
        String s=Integer.toString(x);
        String s1=Integer.toString(i);
        if (s.length()==3) s='0'+s;
        if (s1.length()==3) s1='0'+s1;
        for (int j=1;j<=4;j++)
            if (s.charAt(j-1)==s1.charAt(j-1)) g++;
        return g;
    }
    
    static byte ko(int i,int x) {
        byte g=0;
        String s=Integer.toString(x);
        String s1=Integer.toString(i);
        if (s.length()==3) s='0'+s;
        if (s1.length()==3) s1='0'+s1;
        for (int j=1;j<=4;j++)
            for (int j1=1;j1<=4;j1++)
                if (s.charAt(j-1)==s1.charAt(j1-1)&j1!=j) {g++;break;}
        return g;
    }
    
    static boolean ok(int i) {
        String s=Integer.toString(i);
        if (s.length()==3) s="0"+s;
        for (int j=1;j<=4;j++)
            for (int j1=1;j1<=4;j1++)
                if (s.charAt(j-1)==s.charAt(j1-1)&j1!=j) return false;
        return true;
        
    }

    public static void main(String[] args) throws FileNotFoundException  {
       Scanner in=new Scanner(System.in);
       int n=in.nextInt();
       int a;
       int b;
       int c;
       
       
       for (int i=100;i<=9999;i++) w[i]=false;
       
           a=in.nextInt();
           b=in.nextInt();
           c=in.nextInt();
            for (int i1=100;i1<=9999;i1++)
                if (bi(i1,a)==b&ko(i1,a)==c) w[i1]=true;;
       
       for (int i=2;i<=n;i++) {
           a=in.nextInt();
           b=in.nextInt();
           c=in.nextInt();
            for (int i1=100;i1<=9999;i1++)
                if (!(bi(i1,a)==b&ko(i1,a)==c&w[i1])) w[i1]=false;
       }
       
       n=0; int m=0;
       for (int i=100;i<=9999;i++)
            if (w[i]&ok(i)) {n++;m=i;}
       
       if (n==0) System.out.println("Incorrect data"); else 
           if (n==1) {if (m%1000==m) System.out.println("0"+m); else System.out.println(m);} 
            else System.out.println("Need more data");
              
    }

}