//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
const ll mod=1000000007;
int l[N],r[N];
ll a[N],b[N];
int dsu[N];
vector<int>A[N],B[N];
int n,m;
set<int>st;
bool used[N];
void del(int pos){
    st.erase(pos);
    a[pos]=0;
    int L=pos,R=pos;
    for (int r:A[pos]) {
        if (a[r]==0) R=max(R,r);
    }
    for (int l:B[pos]) {
        if (a[l]==0) L=min(L,l);
    }
    while (!st.empty()){
        auto it=st.lower_bound(L);
        if (it==st.end() || (*it)>R) break;
        int to=(*it);
        del(to);
    }
}
void solve(int Case){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=m;i++) cin>>l[i]>>r[i];
    for (int i=1;i<=n;i++) a[i]-=b[i];
    for (int i=1;i<=n;i++) a[i]+=a[i-1];
    if (a[n]){
        cout<<"NO\n";
        return;
    }
//    for (int i=0;i<=n;i++) cout<<a[i]<<" ";
//    cout<<endl;

    for (int i=0;i<=n;i++){
        A[i].clear();
        B[i].clear();
    }
    st.clear();
    for (int i=1;i<=m;i++){
        A[l[i]-1].push_back(r[i]);
        B[r[i]].push_back(l[i]-1);
    }

    for (int i=0;i<=n;i++) st.insert(i);
    for (int i=0;i<=n;i++){
        if (a[i]==0 && st.find(i)!=st.end()){
            del(i);
        }
    }
    if (!st.empty()) cout<<"NO\n";
    else cout<<"YES\n";


}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/