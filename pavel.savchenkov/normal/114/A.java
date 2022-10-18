import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        long k=in.nextLong();
        long l=in.nextLong();
        long k1=1;
        for (int i=1;i<=100;i++) {
         if (k1==l) {System.out.println("YES"); System.out.println(i-2);return;}
         k1*=k;
         if (k1>l) break;
        }
        System.out.println("NO");
        
        
    }
}