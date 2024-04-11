import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        long n=s.nextLong();
        long m=s.nextLong();
        long k=s.nextLong();
        if(k<n){
            System.out.print(k+1);
            System.out.print(' ');
            System.out.print(1);
            return;
        }
        k-=n;
        Long x=k%(m-1);
        Long y=k/(m-1);
        if(y%2==0){
            System.out.print(n-y);
            System.out.print(' ');
            System.out.print(x+2);
            return;
        }
        else{
            System.out.print(n-y);
            System.out.print(' ');
            System.out.print(m-x);
            return;
        }


    }
}