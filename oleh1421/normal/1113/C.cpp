#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[300001];
map<int,int>mp0;
map<int,int>mp1;
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    mp0[0]=1;
    ll res=0ll;
    for (int i=1;i<=n;i++) {
        sum^=a[i];
        if (i%2==0) res+=mp0[sum]*1ll;
        else res+=mp1[sum];
        if (i%2==0) mp0[sum]++;
        else mp1[sum]++;
    }
    cout<<res;

    return 0;
}