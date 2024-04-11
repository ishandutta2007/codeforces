#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;


long long int geta(int ile,int n)
{
    long long int sum=0;
    long long int ans=0;
    int i=0;
    while(i<ile) {sum+=a[i]; i++;}
    ans=sum;
    for(i=ile;i<n;i++)
    {
        sum-=a[i-ile];
        sum+=a[i];
        ans=min(ans,sum);
    }
    return ans;


}

long long int getb(int ile,int n)
{
    long long int sum=0;
    long long int ans=0;
    int i=0;
    while(i<ile) {sum+=b[i]; i++;}
    ans=sum;
    for(i=ile;i<n;i++)
    {
        sum-=b[i-ile];
        sum+=b[i];
        ans=min(ans,sum);
    }
    return ans;


}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; a.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int x; cin>>x; b.push_back(x);
    }
    long long x; cin>>x;
    vector<long long int>dpa(n+1,0);
    vector<long long int>dpb(m+1,0);
    for(int i=1;i<=n;i++)
    {
        dpa[i]=geta(i,n);
    }
    for(int i=1;i<=m;i++)
    {
        dpb[i]=getb(i,m);
    }
    long long int ans=0;
    for(long long int i=1;i<=n;i++)
    {
        for(long long int j=1;j<=m;j++)
        {
            if(dpa[i]*dpb[j]<=x) ans=max(ans,i*j);
        }
    }
    cout<<ans;
    return 0;
}