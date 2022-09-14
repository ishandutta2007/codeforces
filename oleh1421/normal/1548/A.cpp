//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000001;
const ll mod=1000000007;
const int N=1000010;
int cnt[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cnt[i]=0;
    int res=n;
    for (int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        if (u>v) swap(u,v);
        res-=(cnt[u]==0);
        cnt[u]++;
    }
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int type;cin>>type;
        if (type==1){
            int u,v;cin>>u>>v;
            if (u>v) swap(u,v);
            res-=(cnt[u]==0);
            cnt[u]++;
        } else if (type==2){
            int u,v;cin>>u>>v;
            if (u>v) swap(u,v);
            cnt[u]--;
            res+=(cnt[u]==0);

        } else {
            cout<<res<<endl;
        }
    }

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}