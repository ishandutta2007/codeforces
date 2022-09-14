#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
vector<int>ALL;
ll pref[N];
int a[N];
void rec(int l,int r){
    if (pref[r]-pref[l-1]<=1000000000) ALL.push_back(pref[r]-pref[l-1]);
    if (a[l]==a[r]){
        return;
    }
    int mid=(a[l]+a[r])/2;
    int ind=upper_bound(a+l,a+r+1,mid)-a;
    rec(l,ind-1);
    rec(ind,r);
}
void solve(){
    ALL.clear();
    int n,m;cin>>n>>m;
    pref[0]=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];
    rec(1,n);
    sort(ALL.begin(),ALL.end());
    ALL.push_back(1000000001);
    for (int i=1;i<=m;i++){
        int x;cin>>x;
        if (*lower_bound(ALL.begin(),ALL.end(),x)==x) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}