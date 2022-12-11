import java.lang.*;
import java.io.*;
import java.util.*;

public class Prog {
    static void Solve(Scanner sc){
        int t,s,x;
        t = sc.nextInt();
        s = sc.nextInt();
        x = sc.nextInt();
        if(x==t+1 || x<t){
            System.out.println("NO");
            return;
        }
        x-=t;
        if(x%s<=1){
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }
    }
    public static void main(String[] args) throws IOException{
       Scanner sc = new Scanner(System.in);
       Prog.Solve(sc);
    }
}