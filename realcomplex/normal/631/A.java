import java.lang.*;
import java.io.*;
import java.util.*;

public class Prog {
    static void Solve(Scanner sc){
        int n = sc.nextInt();
        long a = 0,b = 0;
        long cur;
        for(int i = 0;i<n;i++){
            cur = sc.nextInt();
            a |= cur;
        }
        for(int i = 0;i<n;i++){
            cur = sc.nextInt();
            b |= cur;
        }
        System.out.println(a+b);
    }
    public static void main(String[] args) throws IOException{
       Scanner sc = new Scanner(System.in);
       Prog.Solve(sc);
    }
}