#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int l,r;

bool czy(int t)
{
    if(t<10) return true;
    if(t%10==t/10) return true;
    return false;
}

int len(long long int x)
{
    int res=0;
    while(x>0)
    {
        x/=10;
        res++;
    }
    return res;
}

long long int solve(long long int x)
{
    long long int res=0;
    for(int i=1;i<=min(x,(long long int)100);i++)
    {
        if(czy(i)) res++;
    }
    if(x<100) return res;
    for(int i=3;i<len(x);i++)
    {
        long long int akt=9;
        for(int j=0;j<i-2;j++) akt*=10;
        res+=akt;
    }
    // liczby len=len(x);
    vector<int> liczba(20,0);
    int roz=len(x);
    long long int t = x;
    while(t>0)
    {
        liczba[roz]=t%10;
        t/=10;
        roz--;
    }
    roz=len(x);
    long long int add=0;
    add=(liczba[1]-1);
    for(int j=0;j<roz-2;j++) add*=10;
    res+=add;
    long long int mnoznik=1;
    for(int i=roz-1;i>=2;i--)
    {
        long long int akt=liczba[i];
        akt*=mnoznik;
        res+=akt;
        mnoznik*=10;
    }
    if(liczba[1]<=liczba[roz]) res++;
    return res;

}

int main()
{
    cin>>l>>r;
    cout<<solve(r)-solve(l-1);
    return 0;
}