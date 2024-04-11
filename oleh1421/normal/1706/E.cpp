#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=300100;
const int Q=3000100;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N],b[N];
int pos[N];
set<int>st[N];
int val[N];
int dsu[N];
int get(int x){
    if (x==dsu[x]) return x;
    return dsu[x]=get(dsu[x]);
}
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=val[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=n;i++){
        dsu[i]=i;
        val[i]=0;
        st[i].clear();
        st[i].insert(i);
    }
    for (int i=1;i<=m;i++){
        int x=get(a[i]);
        int y=get(b[i]);
        if (x==y) continue;
        if (st[x].size()>st[y].size()) swap(x,y);
        for (int v:st[x]){
            if (st[y].find(v+1)!=st[y].end()) val[v]=i;
            if (st[y].find(v-1)!=st[y].end()) val[v-1]=i;
        }
        for (int v:st[x]){
            st[y].insert(v);
        }
        st[x].clear();
        dsu[x]=y;

    }

    build(1,1,n-1);
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int mx=get(1,1,n-1,l,r-1);
        cout<<mx<<" ";
    }
    cout<<endl;





}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

5 5 5
1 2
1 3
2 4
3 4
3 5

1 4
3 4
2 2
2 5
3 5


**/