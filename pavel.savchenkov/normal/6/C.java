import java.io.*;
import java.util.*;


public class Main {


    public static void main(String[] args) {
       Scanner in=new Scanner(System.in);
       int n=in.nextInt();
       int a1=0,a2=0;
       int[] a=new int[n+1];
       for (int i=1;i<=n;i++) {
           a[i]=in.nextInt();
           a2+=a[i];
       }
       in.close();
       if (n==1) {System.out.println("1 0"); System.exit(0);}
       for (int i=1;i<=n;i++) {
           a1+=a[i-1];
           a2-=a[i];
           if (a1>a2) {System.out.println(i-1+" "+(n-i+1)); break;}
       }
       
    }

}