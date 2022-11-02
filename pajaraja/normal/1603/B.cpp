#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        if(x==y) {printf("%lld\n",x); continue;}
        if(y<x) printf("%lld\n",x+y);
        else
        {
            long long k=max(y/x-1,1LL);
            printf("%lld\n",(y+k*x)/2);
            long long n=(y+k*x)/2;
        }
    }
}