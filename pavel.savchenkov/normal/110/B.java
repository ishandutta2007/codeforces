import java.io.*;
import java.util.*;

public class Main {
    

    
    public static void main(String[] args) {
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      char[] d={'a','b','c','d'};
      for (int i=0;i<n;i++)
       System.out.print(d[i%4]);       
    }
}