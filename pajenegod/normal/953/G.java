
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];
        for(int ar_i = 0; ar_i < n; ar_i++){
            ar[ar_i] = in.nextInt();
        }
        
        int odd = 0;
        int even = 0;
        for (int i=0;i<n;i++)
        {
            if (ar[i]%2==1)
            {
                odd += 1;
            } else {
                even += 1;
            }
        }
        int count = 0;
        while (odd>0 && even>0)
        {
            count+=1;
            odd-=1;
            even-=1;
        }
        while (odd>=3)
        {
            odd-=3;
            count +=1;
        }
        
        System.out.println(count);
    }
}