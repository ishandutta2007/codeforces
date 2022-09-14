#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=500010;
const ll mod=998244353;
int x[N],y[N];
ll get(vector<pair<int,int> >v){
    sort(v.begin(),v.end());
    ll cnt=1ll;
    ll cnt1=1ll;
    ll res=0ll;
    for (int i=1;i<v.size();i++){
        if (v[i].first==v[i-1].first) cnt++;
        else cnt=1;
        if (v[i]==v[i-1]) cnt1++;
        else cnt1=1;
        res+=cnt-cnt1;
    }
    return res;
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    set<int>st_x,st_y;
    for (int i=1;i<=n;i++) cin>>x[i],st_x.insert(x[i]);
    for (int i=1;i<=m;i++) cin>>y[i],st_y.insert(y[i]);
    vector<pair<int,int> >H,V;
    for (int i=1;i<=k;i++){
        int xp,yp;cin>>xp>>yp;
        if (st_x.find(xp)==st_x.end()) H.push_back({upper_bound(x+1,x+n+1,xp)-x,yp});
        if (st_y.find(yp)==st_y.end()) V.push_back({upper_bound(y+1,y+m+1,yp)-y,xp});
    }
    cout<<get(H)+get(V)<<endl;

}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4 - H
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8
**/