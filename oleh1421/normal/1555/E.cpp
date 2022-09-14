//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=1000010;
int l[N],r[N],W[N];
int w[N*4],t[N*4];
void push(int v){
    t[v+v]+=w[v];
    t[v+v+1]+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=min(t[v+v],t[v+v+1]);
}
//int get(int v,int l,int r,int L,int R){
//    if (l>R || r<L) return;
//    if (l>=L && r<=R) return t[v];
//    push(v);
//    int m=(l+r)/2;
//    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
//}
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        int l,r,w;cin>>l>>r>>w;
        v.push_back({w,{l,r}});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        W[i+1]=v[i].first;
        l[i+1]=v[i].second.first;
        r[i+1]=v[i].second.second;
    }
    int res=1000000001;
    int j=1;
    W[0]=-1000000001;
    for (int i=1;i<=n;i++){
        upd(1,1,m-1,l[i],r[i]-1,1);
        while (t[1]>0){
            upd(1,1,m-1,l[j],r[j]-1,-1);
            j++;
        }
        res=min(res,W[i]-W[j-1]);
    }
    cout<<res<<endl;

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
/**
1
8 5
2 1 7 4
4 2
**/