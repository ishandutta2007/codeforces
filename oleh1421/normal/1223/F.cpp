#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int long long
int a[300001];
map<int,int>cnt;
int p[300003];
const int mod=3282920201ll;
void solve(){
    cnt.clear();
    cnt[0]=1;
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    vector<int>v;
    ll res=0ll;
    int v_hash=0;
    int cur=1ll;
    for (int i=1;i<=n;i++){
        if (!v.empty() && v.back()==a[i]) {
            v_hash-=p[v.size()]*a[i];
            v.pop_back();
        }
        else {
            v.push_back(a[i]);
            v_hash+=p[v.size()]*a[i];
        }
        res+=cnt[v_hash]++;
    }
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p[0]=1ll;
    for (int i=1;i<=300000;i++) p[i]=(p[i-1]*311111ll)%mod;
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
}