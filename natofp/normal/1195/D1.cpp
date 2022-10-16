#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=1e5;
int n;
vector<int> a(nax);
int mod=998244353;
long long int res=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        long long int t=a[i];
        long long int waga=1;
        while(t>0)
        {
            long long int dig=t%10;
            t/=10;
            long long int akt=waga*11*dig;
            akt%=mod;
            akt*=(n);
            akt%=mod;
            res+=akt;
            if(res>=mod) res-=mod;
            waga*=100;
            waga%=mod;
        }
    }
    cout<<res;
    return 0;
}