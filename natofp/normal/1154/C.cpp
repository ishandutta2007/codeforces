#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long int a,b,c;

long long int ile(int start)
{
    long long int res=0;
    long long int x,y,z;
    x=a;
    y=b;
    z=c;
    for(int i=start;i<=7;i++)
    {
        if(i%7==0 || i%7==1 || i%7==4)
        {
            x--;
            if(x<0) return res;
            res++;
        }
        else if(i%7==2 || i%7==6)
        {
            y--;
            if(y<0) return res;
            res++;
        }
        else
        {
            z--;
            if(z<0) return res;
            res++;
        }
    }
    long long int jak=x/3;
    jak=min(jak,y/2);
    jak=min(jak,z/2);
    res+=jak*7;
    x-=jak*3;
    y-=jak*2;
    z-=jak*2;
    for(int i=1;i<=7;i++)
    {
        if(i%7==0 || i%7==1 || i%7==4)
        {
            x--;
            if(x<0) return res;
            res++;
        }
        else if(i%7==2 || i%7==6)
        {
            y--;
            if(y<0) return res;
            res++;
        }
        else
        {
            z--;
            if(z<0) return res;
            res++;
        }
    }
}

int main()
{
    long long int res=0;
    cin>>a>>b>>c;
    for(int i=1;i<=7;i++)
    {
        res=max(res,ile(i));
    }
    cout<<res<<endl;

    return 0;
}