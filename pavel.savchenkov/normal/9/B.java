import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws FileNotFoundException {
        Scanner in=new Scanner(/*new FileReader("input.txt"));*/System.in);
        int n=in.nextInt();
        double vb=in.nextInt();
        double vs=in.nextInt();
        double[] x=new double[n+1];
        int xu,yu;
        double min=Integer.MAX_VALUE,t;
        int mint=n;
        for (int i=1;i<=n;i++) {
            x[i]=in.nextInt();
        }
        xu=in.nextInt();
        yu=in.nextInt();
        in.close();
        
        for (int i=2;i<=n;i++) {
            t=(x[i]/vb)+(Math.hypot(x[i]-xu,yu)/vs);
            if (t<=min) {min=t; mint=i;}
        }
        System.out.println(mint);
    }

}