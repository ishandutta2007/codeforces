
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
       Scanner cin = new Scanner(System.in);
       int n = cin.nextInt();
       int sk[] = new int[n];
       int max = 0;
       int p = 0;
       int min = 1000000;
       int v = 0;
       for(int j = 0;j<n;j++){
           sk[j] = cin.nextInt();
           if(sk[j] > max){
               max = sk[j];
               p = j;
           }
           if(sk[j] <= min){
               min = sk[j];
               v = j;
           }
       }
       int am = 0;
       if(p<v){
           System.out.println(p+(n-(v+1)));
       }
       else if(p == v){
           System.out.println("0");
       }
       else{
           System.out.println((p+(n-(v+1))) - 1);
       }
    }
    
}