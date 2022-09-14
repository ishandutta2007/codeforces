#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const ll mod=1000000007;
const ll inf=(1ll<<60);
int dv2(int a,int b){
    a+=b;
    if (a<0) a--;
    return a/2;
}
ll k[N];
ll b[N];
int L[N];
int R[N];
int TOT=1;
int get_v(){
    TOT++;
    k[TOT]=b[TOT]=mod;
    return TOT;
}
ll val(ll kk,ll bb,ll x){
    if (kk==mod && bb==mod) return inf;
    return kk*x+bb;
}
void upd(int v,int l,int r,ll kk,ll bb){
    if (l>r) return;
    int m=dv2(l,r);
    int lef=(val(kk,bb,l)<val(k[v],b[v],l));
    int mid=(val(kk,bb,m)<val(k[v],b[v],m));
    if (mid){
        swap(k[v],kk);
        swap(b[v],bb);
    }
    if (l==r) return;
    if (k[v]==mod) return;
    if (lef!=mid){
        if (!L[v]){
            L[v]=get_v();
        }
        upd(L[v],l,m,kk,bb);
    } else {
        if (!R[v]){
            R[v]=get_v();
        }
        upd(R[v],m+1,r,kk,bb);
    }
}
ll get(int v,int l,int r,ll x){
    if (l==r) return val(k[v],b[v],x);
    if (!v) return inf;
    int m=dv2(l,r);
    if (x<=m) return min(val(k[v],b[v],x),get(L[v],l,m,x));
    else return min(val(k[v],b[v],x),get(R[v],m+1,r,x));
}
ll dp[N];
ll x[N];
ll y[N];
int sz[N];
vector<int>g[N];
void dfsinit(int v,int pr){
    sz[v]=1;
    for (int to:g[v]){
        if (to!=pr){
            dfsinit(to,v);
            sz[v]+=sz[to];
        }
    }
}
vector<int>el[N];
void dfs(int v,int pr,bool cl){
    dp[v]=inf;
    int mx_to=-1;
    int cur=0;
//    cout<<v<<" "<<pr<<" "<<cl<<endl;
    for (int to:g[v]){
        if (to!=pr){
            if (sz[to]>cur){
                cur=sz[to];
                mx_to=to;
            }
        }
    }
    if (mx_to==-1){
        dp[v]=0;
        el[v]={v};
    } else {
        for (int to:g[v]){
            if (to!=pr && to!=mx_to){
                dfs(to,v,1);
            }
        }
        dfs(mx_to,v,0);
        swap(el[v],el[mx_to]);
        el[v].push_back(v);
        for (int to:g[v]){
            if (to!=pr && to!=mx_to){
                for (int u:el[to]){
                    upd(1,-N,N,y[u],dp[u]);
                    el[v].push_back(u);
                }
            }
        }

        dp[v]=get(1,-N,N,x[v]);

    }
    upd(1,-N,N,y[v],dp[v]);
    if (cl){
        for (int i=1;i<=TOT;i++){
            k[i]=b[i]=L[i]=R[i]=0;
        }
        k[1]=b[1]=mod;
        TOT=1;
    }



}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    k[1]=b[1]=mod;
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=n;i++) cin>>y[i];
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfsinit(1,0);
    dfs(1,0,1);
    for (int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}