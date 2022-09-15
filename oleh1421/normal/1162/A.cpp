#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[10001];
int main()
{
    int n,h,m;cin>>n>>h>>m;
    for (int i=1;i<=n;i++) a[i]=h;
    while (m--){
        int l,r,x;cin>>l>>r>>x;
        for (int i=l;i<=r;i++) a[i]=min(a[i],x);
    }
    int res=0;
    for (int i=1;i<=n;i++) res+=a[i]*a[i];
    cout<<res;
    return 0;
}