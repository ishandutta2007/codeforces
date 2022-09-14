//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
const ll mod=998244353ll;
int a[N];
int b[N];
int p[N];
ll n,m,x,y,k;
ll get(vector<int>v,int l,int r){
    if (v.empty()) return 0;
//    sort(v.begin(),v.end());
    ll sz=v.size();
    int mx=0;
    for (auto i:v){
        mx=max(mx,i);
    }
    if (v.size()<k){
        if (mx>max(l,r)) return -1ll;
        return sz*y;
    }
    ll res=0ll;
    if (x<y*k){
        return (sz/k)*x+(sz%k)*y;
    } else {
        if (mx>max(l,r)) return x+(sz-k)*y;
        else return sz*y;
    }
}
void solve(){
    cin>>n>>m;
    cin>>x>>k>>y;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    int ind=1;
    for (int i=1;i<=n;i++){
        if (b[ind]==a[i]) {
            p[ind]=i;
            ind++;
        }
    }
    p[m+1]=n+1;
    if (ind<m){
        cout<<-1<<endl;
        return;
    }
    ll sum=0ll;
    for (int i=1;i<=m+1;i++){
        int l=p[i-1];
        int r=p[i];
        vector<int>v;
        for (int j=l+1;j<r;j++) v.push_back(a[j]);
        ll cur=get(v,a[l],a[r]);
        if (cur==-1){
            cout<<-1<<endl;
            return;
        }
        sum+=cur;
    }
//    vector
    cout<<sum<<endl;

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}