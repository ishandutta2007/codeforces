import java.util.*;
import java.io.*;
import java.math.*;

public class Main
{
    static String s[]=new String[5005];
    static int x[]=new int[5005];
    static int y[]=new int[2005];
    static boolean vis[]=new boolean[5005];
    public static void main(String[] args)
    {
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        for(int i=1;i<=n;i++)
        {
            s[i]=cin.next();
            x[i]=cin.nextInt();
        }
        for(int i=1;i<=n;i++)
            if(s[i].equals("sell"))y[x[i]]=i;
        BigInteger res=BigInteger.ZERO;
        for(int i=2000;i>=0;i--)
        {
            if(y[i]==0)continue;
            BigInteger tmp=BigInteger.ONE;
            for(int j=0;j<i;j++)
                tmp=tmp.multiply(BigInteger.valueOf(2));
            for(int j=y[i]-1;j>0 && vis[j]==false;j--)
                if(s[j].equals("win") && x[j]==i)
                {
                    for(int k=j;k<=y[i];k++)
                        vis[k]=true;
                    res=res.add(tmp);
                    break;
                }
        }
        System.out.println(res);
    }
}