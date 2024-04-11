#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int inf=1000000001;
vector<pair<int,int> >g[N];
int a[N],b[N],c[N];
int h[N];
void dfs(int v,int pr){
    h[v]=h[pr]+1;
    for (auto cur:g[v]){
        int to=cur.first;
        if (to!=pr){
            dfs(to,v);
        }
    }
}
struct Solver{
    int type[N];
    int h[N];
    int root;
    int timer=0;
    int tin[N];
    int tout[N];
    int pos[N];
    void dfs1(int v,int pr,int xr){
        tin[v]=++timer;
        type[v]=xr;
        h[v]=h[pr]+1;
        pos[tin[v]]=v;
//        cout<<v<<" "<<type[v]<<" "<<h[v]<<endl;
        for (auto cur:g[v]){
            int to=cur.first;
            if (to!=pr){
                dfs1(to,v,xr^c[cur.second]);
            }
        }
        tout[v]=timer;
    }

    int t[N*4][2];
    int w[N*4];
    void build(int v,int l,int r){
        w[v]=0;
        if (l==r){
            t[v][type[pos[l]]]=h[pos[l]];
            t[v][type[pos[l]]^1]=-inf;
            return;
        }
        int m=(l+r)/2;
        build(v+v,l,m);
        build(v+v+1,m+1,r);
        t[v][0]=max(t[v+v][0],t[v+v+1][0]);
        t[v][1]=max(t[v+v][1],t[v+v+1][1]);
    }
    void push(int v){
        if (w[v]){
            swap(t[v+v][0],t[v+v][1]);
            swap(t[v+v+1][0],t[v+v+1][1]);
            w[v+v]^=1;
            w[v+v+1]^=1;
            w[v]=0;
        }
    }
    void upd(int v,int l,int r,int L,int R){
        if (l>R || r<L) return;
        if (l>=L && r<=R) {
            swap(t[v][0],t[v][1]);
            w[v]^=1;
            return;
        }
        push(v);
        int m=(l+r)/2;
        upd(v+v,l,m,L,R);
        upd(v+v+1,m+1,r,L,R);
        t[v][0]=max(t[v+v][0],t[v+v+1][0]);
        t[v][1]=max(t[v+v][1],t[v+v+1][1]);
    }
    void Init(){
        timer=0;
        h[0]=-1;
        dfs1(root,0,0);
        build(1,1,timer);
    }
    void Upd_edge(int ind){
        int v;
        if (h[a[ind]]>h[b[ind]]) v=a[ind];
        else v=b[ind];
        upd(1,1,timer,tin[v],tout[v]);
    }
    int Get_result(){
        return max(0,t[1][0]);
    }
};
Solver Sa,Sb;
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        g[a[i]].push_back({b[i],i});
        g[b[i]].push_back({a[i],i});
    }
    h[0]=-1;
    dfs(1,0);
    int a=1;
    for (int i=2;i<=n;i++){
        if (h[i]>h[a]) a=i;
    }
    dfs(a,0);
    int b=1;
    for (int i=2;i<=n;++i){
        if (h[i]>h[b]) b=i;
    }
    Sa.root=a;
    Sb.root=b;
//    cout<<a<<" "<<b<<endl;
    Sa.Init();
    Sb.Init();
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int ind;cin>>ind;
        Sa.Upd_edge(ind);
        Sb.Upd_edge(ind);
        cout<<max(Sa.Get_result(),Sb.Get_result())<<endl;
    }

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