#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,res;
int cnt[2000001],prime[2000001];
vector<int> a;
int main()
{
    cin>>n>>m; if (m==2) return cout<<0,0;
    for (i=1;i<=n;i++) 
    {
        cin>>k;
        if (k<=2e6) a.push_back(k);
    }
    sort(a.begin(),a.end());
    if ((a.size())and(a[0]==1)) return cout<<1,0;
    if (m>=2e6) return cout<<-1,0;
    for (i=1;i<=a.size();i++) cnt[a[i-1]]++;
    for (int i=2;i<=m;i++) prime[i]=1;
    for (i=2;i*i<=m;i++) if (prime[i])
    {
        for (j=i*i;j<=m;j+=i) prime[j]=0;
    }
    for (i=2;i<m;i++) if (prime[i])
    {
        res++;
        if (!cnt[i]) return cout<<-1,0;
    }
    cout<<res;
}