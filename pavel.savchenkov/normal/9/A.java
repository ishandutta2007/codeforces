import java.io.*;
import java.util.*;

public class Main {
 static int nod(int a,int b) {
  if (b==0) return a; else return nod(b,a%b);
 }
 
 public static void main(String args[]) {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int b=in.nextInt();
  a=Math.max(a,b);
  a=7-a;
  b=6;
  int n=nod(a,6);
  if (n!=0) {a=a/n; b=b/n;}
  System.out.println(a+"/"+b);
  
}
}