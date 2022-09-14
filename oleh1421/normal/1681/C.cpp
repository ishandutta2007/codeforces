#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int Lg=20;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
pair<pair<int,int>,int> a[N];
int p[N];
bool used[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first.first;
    for (int i=1;i<=n;i++) cin>>a[i].first.second;
    for (int i=1;i<=n;i++) a[i].second=i;
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++){
        if (a[i-1].first.second>a[i].first.second){
            cout<<-1<<endl;
            return;
        }
    }
    for (int i=1;i<=n;i++) p[a[i].second]=i,used[i]=false;
    vector<pair<int,int> >ans;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        int x=i;
        vector<int>order;
        while (!used[x]){
            order.push_back(x);
            used[x]=true;
            x=p[x];
        }
        for (int i=(int)order.size()-2;i>=0;i--){
            ans.push_back({order[i],order[i+1]});
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;



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
3
1 5
2 6
3 4
*/