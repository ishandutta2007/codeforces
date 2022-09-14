//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> line;
#define endl '\n'
const int N = 1500010;
const ll mod=998244353;
const ll inf=1e18;
int x[N],y[N],z[N];
int a[N];
int ans[N];
vector<int>Q[N];
void solve(){
    int n,m;cin>>n>>m;

    for (int i=1;i<=n;i++) ans[i]=0;
    for (int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>z[i];
        if (x[i]>y[i]) swap(x[i],y[i]);
    }
    for (int bt=0;bt<30;bt++){
        for (int i=1;i<=n;i++) a[i]=-1;
        for (int i=1;i<=m;i++){
            if (z[i]&(1<<bt)){
                if (x[i]==y[i]) a[x[i]]=1;
                else Q[y[i]].push_back(x[i]);
            } else {
                a[x[i]]=0;
                a[y[i]]=0;
            }
        }
        for (int i=1;i<=m;i++){
            if (z[i]&(1<<bt)){
                if (a[y[i]]==0) a[x[i]]=1;
            }
        }
        for (int i=1;i<=n;i++){
            if (a[i]!=-1) continue;
            for (int j:Q[i]){
                if (a[j]==0) a[i]=1;
            }
            if (a[i]==-1) a[i]=0;
        }
        for (int i=1;i<=n;i++) ans[i]|=(a[i]<<bt);
        for (int i=1;i<=n;i++) Q[i].clear();
    }
    for (int i=1;i<=m;i++){
        if ((ans[x[i]]|ans[y[i]])!=z[i]) exit(1);
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;





}
int main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;

    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 86

**/