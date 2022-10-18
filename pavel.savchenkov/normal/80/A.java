import java.io.*;
import java.util.*;

public class Main {
    static boolean pr(int a) {
        for (int i=2;i<=Math.round(Math.sqrt(a));i++)
            if (a%i==0) return false;
        return true;
    }
  
    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     int n=in.nextInt();
     int m=in.nextInt();
     if (!pr(m)) {System.out.println("NO");System.exit(0);}
     for (int i=n+1;i<=m-1;i++) 
         if (pr(i)) {System.out.println("NO");System.exit(0);}
     System.out.println("YES");
    }

}