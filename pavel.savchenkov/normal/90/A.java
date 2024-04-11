import java.io.*;
import java.util.*;

public class Main {

  
    public static void main(String[] args) {
     Scanner in=new Scanner(System.in);
     int r=in.nextInt();
     int g=in.nextInt();
     int b=in.nextInt();
     if (r!=0) {if (r%2==0) r=r/2; else r=r/2+1; r=30+3*(r-1);}
     if (g!=0) {if (g%2==0) g=g/2; else g=g/2+1; g=31+3*(g-1);}
     if (b!=0) {if (b%2==0) b=b/2; else b=b/2+1; b=32+3*(b-1);}
     r=Math.max(r,b);
     System.out.println(Math.max(g,r));
     
     
    }

}