#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int p[3000001];
int32_t main()
{
    ll n,k;cin>>n>>k;
    if (k<(n*(n+1)/2ll)){
        cout<<"-1";
        return 0;
    }
    ll last=k;
    k-=(n*(n+1)/2ll);
    for (int i=1;i<=n;i++) p[i]=i;
    int l=1;
    int r=n;
    while (l<r && k>0){
         r=min(r*1ll,l+k);
         swap(p[l],p[r]);
         k-=(r-l)*1ll;
         l++;
         r--;
    }
    cout<<last-k<<endl;
    for (int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}
/*
11 4
WBWBWBBWBWBWBBWWBWB

*/