import java.util.*;
import java.io.*;
import java.util.regex.*;
public class Main {
    public static void main(String[] args) {
        int []have=new int[49];
        long ans=0;
        Scanner s=new Scanner(System.in);
        long n=s.nextLong();
        for(long i=0;i<=100;i++) {
            for (long j = 0; j <= i; j++) {
                int f=1;
                if (have[(int)(4*j+9*(i-j))%49]==1)
                    f = 0;
                have[(int)(4*j+9*(i-j))%49]=1;
                if (n - i>= 0) {
                    ans += f * (n - i + 1);
                }
            }
        }
        System.out.println(ans);
    }
}