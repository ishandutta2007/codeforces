#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const ll mod=998244353;
const int N=1000100;
const int L=30;
int p[N];
int a[N];
int up[N][L];
int in[N];
vector<int>g[N];
int ans[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i],in[p[i]]++;
    for (int i=1;i<=n;i++) cin>>a[i];
    int add=0;
    int d=0;
    for (int i=1;i<=n;i++){
        if (in[i]==0) add++;
        d=max(d,a[i]);
    }
    assert((d-n)%add==0);
    d=(d-n)/add;
//    cout<<d<<endl;


    for (int i=1;i<=n;i++){
        up[i][0]=p[i];
    }
    for (int j=1;j<L;j++){
        for (int i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    for (int i=1;i<=n;i++){
        p[i]=i;
        for (int j=0;j<L;j++){
            if (d&(1<<j)) p[i]=up[p[i]][j];
        }
//        cout<<p[i]<<" "<<i<<endl;
        g[p[i]].push_back(i);
    }
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(i);
    for (int i=1;i<=n;i++){
        if (!g[i].empty()){
            int mn=g[i][0];

            for (int x:g[i]) mn=min(mn,x);
            ans[mn]=a[i];
            st.erase(a[i]);
//            cout<<endl;
//            cout<<a[i]<<endl;
//            sort(g[i].begin(),g[i].end());
//            for (int x:g[i]) cout<<x<<" ";
//            cout<<endl;
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i]) continue;
        auto it=st.lower_bound(a[p[i]]);
        if (it==st.end()) exit(1);
        ans[i]=(*it);
        st.erase(it);
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;




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
//2121
//121
//2
//
//1 2

/**

R,S

RSAxT
SxART
xSART


**/