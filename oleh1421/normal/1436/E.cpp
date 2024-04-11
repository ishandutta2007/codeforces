#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
int a[N];
vector<int>g[N];
vector<pair<int,int> >Q[N];
int last[N];
int t[N*4];
void upd(int v,int l,int r,int pos,int x){
    if (l==r){
        t[v]=x;
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
    t[v]=min(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 1000000001;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
bool ok[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n+1;i++){
        int last=0;
        for (int j:g[i]){
            v.push_back({i,{last+1,j-1}});
            last=j;
        }
        v.push_back({i,{last+1,n}});
    }
    for (auto cur:v){
        int i=cur.first;
        int L=cur.second.first;
        int R=cur.second.second;
        if (L>R) continue;
        Q[R].push_back({L,i});
    }
    for (int R=1;R<=n;R++){
        last[a[R]]=R;
        upd(1,1,n,a[R],R);
        for (auto cur:Q[R]){
            int L=cur.first;

            int i=cur.second;
            ok[i]|=(get(1,1,n,1,i-1)>=L);
        }
    }

    int res=1;
    while (ok[res]) res++;
    cout<<res<<endl;



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