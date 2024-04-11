#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    char c[n];
    scanf("%s",c);
    if(n==1)
    {
        if(c[0]=='0')
        {
            printf("No");
        }
        else
        {
            printf("Yes");
        }
        return 0;
    }
    if(n==2)
    {
        if(c[0]=='0'&&c[1]=='0')
        {
            printf("No");
        }
        else
        {
            if(c[0]=='1'&&c[1]=='1')
            {
                printf("No");
            }
            else
            {
                printf("Yes");
            }
        }
        return 0;
    }
    bool test=false;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='0')
        {
            if(i==0)
            {
                if(c[i+1]=='0')
                {
                    test=true;
                }
            }
            else
            {
                if(i==n-1)
                {
                    if(c[i-1]=='0')
                    {
                        test=true;
                    }
                }
                else
                {
                    if(c[i-1]=='0'&&c[i+1]=='0')
                    {
                        test=true;
                    }
                }
            }
        }
        else
        {
            if(i==0)
            {
                if(c[i+1]=='1')
                {
                    test=true;
                }
            }
            else
            {
                if(i==n-1)
                {
                    if(c[i-1]=='1')
                    {
                        test=true;
                    }
                }
                else
                {
                    if(c[i-1]=='1'||c[i+1]=='1')
                    {
                        test=true;
                    }
                }
            }
        }
    }
    if(test)
    {
        printf("No");
    }
    else
        printf("Yes");
    return 0;
}