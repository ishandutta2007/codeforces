import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        double h=0;
        double m=0;
        String s=in.nextLine();
        String s1="";
        for (int i=0;i<=1;i++)
            s1+=s.charAt(i);
        h=Integer.parseInt(s1);
        s1="";
        for (int i=3;i<=4;i++) 
            s1+=s.charAt(i);
        m=Integer.parseInt(s1);
        h=h%12;
        m=m%60;
        in.close();
        h+=m/60;
        System.out.println(30*h+" "+6*m);
    }

}