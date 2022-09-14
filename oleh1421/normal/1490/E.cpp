//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
pair<ll,int> a[N];
bool ok[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for (int i=0;i<=n;i++) ok[i]=false;
    ok[n]=true;
    ll sum=0ll;
    for (int i=1;i<n;i++){
        sum+=a[i].first;
        if (sum>=a[i+1].first) ok[i]=true;
    }
    vector<int>ans;
    for (int i=n;i>=1;i--){
        if (!ok[i]) break;
        ans.push_back(a[i].second);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
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
/*
1
3 3
1 -3 4
1 5 2
*/