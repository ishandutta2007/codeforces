import java.util.*;
public class a 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        byte[] ch = new byte[201];
        int[] arr = new int[26];
        String s;
        int n,m,i,j,k,t,t1,u,v,a,b;
        t=sc.nextInt();

        for (t1=0;t1<t;t1++)
        {
            n=sc.nextInt();
            for (i=0;i<26;i++) arr[i]=0;
            s = sc.next();
            for (i=0;i<n;i++)
            {
                if ((i==0)||(s.charAt(i)!=s.charAt(i-1)))
                {
                    arr[s.charAt(i)-65]++;
                }
            }
            a=1;
            for (i=0;i<26;i++) if (arr[i]>=2) a=0;
            if (a==1) System.out.println("YES");
            if (a==0) System.out.println("NO");
        }
    }
}