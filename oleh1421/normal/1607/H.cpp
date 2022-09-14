#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int a[N],b[N],m[N];
map<int,vector<int> >mp;
int x[N];
void solve(){
    mp.clear();
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i]>>m[i],mp[a[i]+b[i]-m[i]].push_back(i);
    int res=0;
    for (auto cur:mp){
        vector<pair<pair<int,int>,int> >v;
        for (int i:cur.second){
            v.push_back({{min(a[i],b[i]+a[i]-m[i]),max(0,a[i]-m[i])},i});
        }
        sort(v.begin(),v.end());
        int L=-1;
        for (int i=0;i<v.size();i++){
            if (v[i].first.second>L) {
                L=v[i].first.first;
                res++;
            }
            x[v[i].second]=L;
        }
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++){
        cout<<a[i]-x[i]<<" "<<m[i]-a[i]+x[i]<<endl;
    }
}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}