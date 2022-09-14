#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000010;
const ll inf=1e18;
const ll mod=998244353;
ll a[N];
vector<pair<pair<int,int>,pair<int,int> > >A[62];
vector<pair<pair<int,int>,pair<int,int> > >B[62];
int l[N],r[N];
vector<pair<pair<int,int>,int> >add[N];
struct node{
    int mx;
    int cnt;
    node(){
    }
    node(int x){
        mx=x;
        cnt=1;
    }
};
node Merge(node A,node B){
    if (A.mx>B.mx) return A;
    if (A.mx<B.mx) return B;
    A.cnt+=B.cnt;
    return A;
}
node t[N*4];
int w[N*4];
void push(int v){
    t[v+v].mx+=w[v];
    t[v+v+1].mx+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void build(int v,int l,int r){
    t[v].mx=w[v]=0;
    t[v].cnt=r-l+1;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v].mx+=x;
        w[v]+=x;
        return;
    }
    int m=(l+r)/2;
    push(v);
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        l[i]=0;
        for (int j=i-1;j>=1;j=l[j]){
            if (a[j]>a[i]){
                l[i]=j;
                break;
            }
        }
    }
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        for (int j=i+1;j<=n;j=r[j]){
            if (a[j]>=a[i]){
                r[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        A[__builtin_popcountll(a[i])].push_back({{l[i]+1,i},{i,r[i]-1}});
    }


    for (int i=1;i<=n;i++){
        l[i]=0;
        for (int j=i-1;j>=1;j=l[j]){
            if (a[j]<a[i]){
                l[i]=j;
                break;
            }
        }
    }
    for (int i=n;i>=1;i--){
        r[i]=n+1;
        for (int j=i+1;j<=n;j=r[j]){
            if (a[j]<=a[i]){
                r[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        B[__builtin_popcountll(a[i])].push_back({{l[i]+1,i},{i,r[i]-1}});
    }
    ll res=0ll;
    build(1,1,n);
    for (int bt=0;bt<60;bt++){
        for (auto cur:A[bt]){
            add[cur.first.first].push_back({cur.second,1});
            add[cur.first.second+1].push_back({cur.second,-1});
        }
        for (auto cur:B[bt]){
            add[cur.first.first].push_back({cur.second,1});
            add[cur.first.second+1].push_back({cur.second,-1});
        }
        for (int i=1;i<=n+1;i++){
            for (auto cur:add[i]){
                upd(1,1,n,cur.first.first,cur.first.second,cur.second);
            }
            if (t[1].mx==2){
                res+=t[1].cnt;
            }
        }
        for (int i=0;i<=n+1;i++) add[i].clear();
    }
    cout<<res<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/