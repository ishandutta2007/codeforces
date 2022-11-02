#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
#define maxn 400400
#define mod 1000000007
#define pii pair<int,int> 
#define debug 
#define ll long long
#define pb push_back

long long val[maxn];
vector<int> L[maxn];

int even[maxn];
int odd[maxn];
int size[maxn];
int n;

int te[maxn];
int to[maxn];

long long ans = 0;

ll mul(ll a,ll b,ll c){
    a*=b;
    a%=mod;
    a*=c;
    a%=mod;
    return (a+mod)%mod;
}
ll mul(ll a,ll b){
    return mul(1,a,b);
}

void dfs(int x,int p=0){
    for(int i=0;i<L[x].size();i++){
        int v = L[x][i];
        if(v == p) continue;
        dfs(v,x);
        ans += mul(val[x],odd[v],n-size[v]);
        ans -= mul(val[x],even[v],n-size[v]);
        ans = (ans%mod+mod)%mod;
        even[x] += odd[v];
        odd[x] += even[v];
    }
    even[x]++;
    ans += mul(val[x],n);
    size[x] = even[x] + odd[x];
}

void dfs2(int x,int p=0){
    if(x == 0){
        te[x] = even[x];
        to[x] = odd[x];
    }
    else {
        te[x] = to[p];
        to[x] = te[p];
    }
    debug("at %d ev %d od %d te %d to %d\n",x,even[x],odd[x],te[x],to[x]);
    ans += mul(val[x],te[x]-even[x],size[x]);
    ans -= mul(val[x],to[x]-odd[x],size[x]);
    ans = (ans%mod+mod)%mod;
    for(int i=0;i<L[x].size();i++){
        int v = L[x][i];
        if(v != p)
            dfs2(v,x);
    }
}

main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",val+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    dfs(0);
    dfs2(0);
    printf("%I64d\n",ans);
}