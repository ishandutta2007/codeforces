import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     String s=in.nextLine();
     int k=in.nextInt();
     int n=0,min,m=1,f=0;
     boolean[] vis=new boolean[26];
     int[] a=new int[26];
     if (k>=s.length()) {System.out.println("0");System.out.println();System.exit(0);}
     for (int i=s.length();i>=1;i--) {
         a[s.charAt(i-1)-97]++;
         if (vis[s.charAt(i-1)-97]==false) {f++;vis[s.charAt(i-1)-97]=true;}
     }

     while (n<k) {
         
       min=100001;
       for (int i=0;i<=25;i++) 
           if (a[i]<min&a[i]>0) {min=a[i];m=i;}

       if (a[m]==0) break;
       if (n+a[m]<=k) {n+=a[m];a[m]=0;f--;}
       if (n+a[m]>k) break;
       
     }
     System.out.println(f);
     for (int i=1;i<=s.length();i++)
         if (a[s.charAt(i-1)-97]>0) System.out.print(s.charAt(i-1));  
     
     
    }
}