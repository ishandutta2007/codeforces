#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int tab[1000000];
long long int solve(long long int a,long long int b)
{

    int k=0;
    for(long long int i=1;i*i<=a;i++)
    {
        if(a%i==0) {tab[k]=i; k++;}

    }
    long long int ans=1000000000000000000;
    long long int x=a+b;
    int l=0;
    for(long long int i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(l+1<k && tab[l+1]<=i) l++;
            if(a/tab[l]<=x/i) ans=min(ans,2*(i+x/i));
        }
    }
    return ans;
}

int main()
{
    long long int a,b;
    cin>>a>>b;
    cout<<min(solve(a,b),solve(b,a));
    return 0;
}