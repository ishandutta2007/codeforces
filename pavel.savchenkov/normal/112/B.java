import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        n/=2;
        int x=in.nextInt();
        int y=in.nextInt();
        if (x==n)
            if (y==n|y==n+1) {System.out.println("NO"); return;}
        if (x==n+1)
            if (y==n|y==n+1) {System.out.println("NO"); return;}
        System.out.println("YES");
        
        
    }
}