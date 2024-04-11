#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = (1<<20);
const ll mod=998244353;
const ll inf=1e18;
vector<int>g[N];
int x[11];
int ans[11];
int n,q;
int d[N];
bool used[N];
int sz[N];
int mxto[N];
vector<int>order;
void dfs0(int v,int pr){
    sz[v]=1;
    mxto[v]=0;
    order.push_back(v);
    for (int to:g[v]){
        if (used[to] || to==pr) continue;
        dfs0(to,v);
        sz[v]+=sz[to];
        mxto[v]=max(mxto[v],sz[to]);
    }
}
int h[N];
vector<pair<int,int> >u;
void dfs(int v,int pr,int val){
    h[v]=val;
    u.push_back({h[v],d[v]});
    for (int to:g[v]){
        if (to==pr || used[to]) continue;
        dfs(to,v,val+1);
    }
}
struct BIT{
    int t[N];
    BIT(){
        for (int i=0;i<N;i++) t[i]=-N;
    }
    vector<int>used;
    void upd(int pos,int x){
        pos=N-pos-1;
        used.push_back(pos);
        for (;pos<N;pos|=pos+1) t[pos]=max(t[pos],x);
    }
    int get(int pos){
        pos=N-pos-1;
        int res=-N;
        for (;pos>=0;pos&=pos+1,pos--) res=max(res,t[pos]);
        return res;
    }
    void clr(){
        for (int pos:used){
            for (;pos<N;pos|=pos+1) t[pos]=-N;
        }
        used.clear();
    }
};
BIT T;
void rec(int root,int depth){
    dfs0(root,0);
    int tot=sz[root];
    int centroid=root;
    for (int v:order){
        mxto[v]=max(mxto[v],tot-sz[v]);
    }
    for (int v:order){
        if (mxto[centroid]>mxto[v]) centroid=v;
    }
//    cout<<"C "<<centroid<<endl;
//    for (int v:order) cout<<v<<" ";
//    cout<<endl;
    order.clear();
    int mxa=0;
    int mxb=-N;
    for (int to:g[centroid]){
        if (!used[to]){
            dfs(to,centroid,1);
        }
        for (auto [a,b]:u){
//            cout<<a<<" "<<b<<endl;
            for (int i=1;i<=q;i++){
                ans[i]=max(ans[i],min(a,b+d[centroid]+x[i]));
                while (ans[i]+1-a<=mxa && mxb+x[i]+b>=ans[i]+1 && T.get(ans[i]+1-a)+x[i]+b>=ans[i]+1) ans[i]++;
            }
        }
        for (auto [a,b]:u){
            T.upd(a,b);
            mxa=max(mxa,a);
            mxb=max(mxb,b);
        }
        u.clear();
    }
    T.clr();


    used[centroid]=true;
    for (int to:g[centroid]){
        if (!used[to]){
            rec(to,depth+1);
        }

    }

}
void solve(){
    cin>>n;
    for (int i=2;i<=n;i++){
        int pr;cin>>pr;
        g[pr].push_back(i);
        g[i].push_back(pr);
    }
    cin>>q;
    for (int i=1;i<=q;i++) cin>>x[i];
    queue<int>dq;
    for (int i=1;i<=n;i++){
        d[i]=-1;
        if (g[i].size()==1){
            dq.push(i);
            d[i]=0;
        }
    }
    while (!dq.empty()){
        int v=dq.front();
        dq.pop();
        for (int to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                dq.push(to);
            }
        }
    }
    rec(1,0);
    for (int i=1;i<=q;i++) cout<<ans[i]<<" ";
    cout<<endl;





}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}