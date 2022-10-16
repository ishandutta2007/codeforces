#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

bool czy(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

map<int,int> wyniki;
vector<int>primes;
void rob(int n)
{
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            wyniki[primes[i]]++;
            while(n%primes[i]==0) n/=primes[i];
        }
    }
    if(n>1) wyniki[n]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    int * a;
    a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int t=a[0];
    for(int i=1;i<n;i++)
    {
        t=gcd(t,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i]/=t;
    }

    for(int i=2;i<=4000;i++)
    {
        if(czy(i)) primes.push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        rob(a[i]);
    }
    int ans=0;
    map<int,int>::iterator it;
    it=wyniki.begin();
    while(it!=wyniki.end())
    {
        ans=max(ans,it->second);
        it++;
    }
    if(ans==0)
    {
        cout<<-1;
    }
    else cout<<n-ans;
    return 0;
}