#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int cifre[19];
    int broj=0;
    while(n>9)
    {
        cifre[broj]=n%10;
        n/=10;
        //printf("%i ",cifre[broj]);
        broj++;
    }
    cifre[broj]=n%10;
    n/=10;
    //printf("%i\n",cifre[broj]);
    broj++;
    int cifra_2=-1,cifra_5=-1,cifra_7=-1,cifra_0_1=-1,cifra_0_2=-1;
    for(int i=0;i<broj;i++)
    {
        if(cifre[i]==2&&cifra_2==-1)
        {
            cifra_2=i;
        }
        if(cifre[i]==5&&cifra_5==-1)
        {
            cifra_5=i;
        }
        if(cifre[i]==7&&cifra_7==-1)
        {
            cifra_7=i;
        }
        if(cifre[i]==0&&cifra_0_1==-1)
        {
            cifra_0_1=i;
        }
        else
        {
            if(cifra_0_2==-1&&cifre[i]==0)
            {
                cifra_0_2=i;
            }
        }
    }
    int minn=1000;
    if(cifra_0_1!=-1&&cifra_0_2!=-1)
    {
        minn=min(minn,cifra_0_1+cifra_0_2-1);
    }
    if(cifra_5!=-1&&cifra_7!=-1)
    {
        int extra=0;
        if(cifra_5==broj-1)
        {
            int tr=broj-2;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(cifra_7==broj-1)
        {
            int tr=broj-2;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(((cifra_5==broj-1&&cifra_7==broj-2)||(cifra_7==broj-1&&cifra_5==broj-2)))
        {
            int tr=broj-3;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(cifra_5<cifra_7)
        {
            minn=min(minn,cifra_5+cifra_7-1+extra);
        }
        else
        {
            minn=min(minn,cifra_5+cifra_7+extra);
        }
    }
    if(cifra_5!=-1&&cifra_0_1!=-1)
    {
        if(cifra_5>cifra_0_1)
        {
            int extra=0;
            if(cifra_5==broj-1)
            {
                int tr=broj-2;
                while(cifre[tr]==0&&cifra_0_1!=tr)
                {
                    extra++;
                    tr--;
                }
            }
            minn=min(minn,cifra_5+cifra_0_1-1+extra);
        }
        else
        {
            minn=min(minn,cifra_5+cifra_0_1);
        }
    }
    if(cifra_5!=-1&&cifra_2!=-1)
    {
        int extra=0;
        if(cifra_5==broj-1)
        {
            int tr=broj-2;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(cifra_2==broj-1)
        {
            int tr=broj-2;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(((cifra_5==broj-1&&cifra_2==broj-2)||(cifra_2==broj-1&&cifra_5==broj-2)))
        {
            int tr=broj-3;
            while(cifre[tr]==0)
            {
                extra++;
                tr--;
            }
        }
        if(cifra_5<cifra_2)
        {
            minn=min(minn,cifra_5+cifra_2-1+extra);
        }
        else
        {
            minn=min(minn,cifra_5+cifra_2+extra);
        }
    }
    if(minn==1000)
    {
        printf("-1\n");
        return 0;
    }
    printf("%i\n",minn);
    return 0;
}