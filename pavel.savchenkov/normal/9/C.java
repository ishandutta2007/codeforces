import java.io.*;
import java.util.*;

public class Main {
     


    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        String s=in.nextLine();
        String s1="";
        int n=0;
        int k;
        
        for (int i=0;i<=s.length()-1;i++)
            if (s.charAt(i)>'1') {
                for (int j=i;j<=s.length()-1;j++)
                    s1+='1';
                break;
            } else s1+=s.charAt(i);
        
        s=s1;
        n=0;
        for (int i=s.length()-1;i>=0;i--) {
            k=0;
            if (s.charAt(i)=='1') k=1;
            n+=k*Math.pow(2, s.length()-i-1);
        }    
            
            System.out.println(n);
    }

}