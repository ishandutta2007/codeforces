import java.io.*;
import java.util.*;

public class Main {

    static boolean pal(int i) {
     String q=Integer.toString(i/60);
     if (q.length()==1) q="0"+q;
     String q1=Integer.toString(i-(i/60)*60);
     if (q1.length()==1) q1="0"+q1;
     q=q+q1;
     if (q.charAt(0)==q.charAt(3)&q.charAt(1)==q.charAt(2)) return true;
     return false;
    }
    
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        String s1="";
        s1+=s.charAt(0);
        s1+=s.charAt(1);
        int h=Integer.parseInt(s1);
        s1="";
        s1+=s.charAt(3);
        s1+=s.charAt(4);
        int m=Integer.parseInt(s1);
        int t=h*60+m;
        for (int i=t+1;i<=24*60*2;i++)
            if (pal(i%(24*60))) 
            {
               i%=24*60; 
               String q=Integer.toString(i/60);
               if (q.length()==1) q="0"+q;
               q=q+":";
               String q1=Integer.toString(i-(i/60)*60);
               if (q1.length()==1) q1="0"+q1;
               q=q+q1;System.out.println(q);return;
            }
        
    }
}