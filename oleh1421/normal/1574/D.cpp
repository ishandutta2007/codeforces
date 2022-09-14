//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=200100;
const ll mod=998244353;
const ll inf=2000000000000000000;
ll a[11][N];
int c[N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>c[i];
        for (int j=1;j<=c[i];j++) cin>>a[i][j];
    }
    set<pair<ll,vector<int> > >used;
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        pair<ll,vector<int> > F={0,{}};
        for (int i=1;i<=n;i++){
            int x;cin>>x;
            F.first-=a[i][x];
            F.second.push_back(x);
        }
        used.insert(F);
    }
    set<pair<ll,vector<int> > >used1;
    set<pair<ll,vector<int> > >st;
    pair<ll,vector<int> > F={0,{}};
    for (int i=1;i<=n;i++){
        F.first-=a[i][c[i]];
        F.second.push_back(c[i]);
    }
    st.insert(F);
    while (!st.empty()){
        auto cur=(*st.begin());
        st.erase(st.begin());
        if (used.find(cur)==used.end()){
            for (int i:cur.second) cout<<i<<" ";
            cout<<endl;
            return;
        }
        for (int i=0;i<n;i++){
            if (cur.second[i]==1) continue;
            auto nxt=cur;
            nxt.first+=a[i+1][nxt.second[i]];
            nxt.second[i]--;
            nxt.first-=a[i+1][nxt.second[i]];
            if (used1.find(nxt)==used1.end()){
                st.insert(nxt);
                used1.insert(cur);
            }
        }
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3