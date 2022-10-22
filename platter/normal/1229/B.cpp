#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;
vector<int> son[100000];
vector<int> adj[100000];
ll arr[100000];
const int mod=1e9+7;

ll gcd(ll a,ll b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);
}

long long ans(int v,set<P> s) {
    long long ret=0;
    for(auto curr:s) {
        ret+=gcd(curr.first,arr[v])*curr.second;
        ret%=mod;
    }
    set<P> ns;
    ns.insert(P(arr[v],1));
    ret+=arr[v];
    ret%=mod;
    for(auto curr:s) {
        ll val=gcd(curr.first,arr[v]);
        if ((*ns.lower_bound(P(val,-1))).first!=val) {
            ns.insert(P(val,curr.second));
        }
        else {
            int cnt=(*ns.lower_bound(P(val,-1))).second;
            ns.erase(P(val,cnt));
            ns.insert(P(val,cnt+curr.second));
        }
    }
    for(int i=0;i<son[v].size();i++) {
        ret+=ans(son[v][i],ns);
        ret%=mod;
    }
    return ret;
}

bool visited[100000];

void maketree(int v) {
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++) {
        int nt=adj[v][i];
        if (!visited[nt]) {
            son[v].push_back(nt);
            maketree(nt);
        }
    }
}

int main(void) {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    maketree(0);
    set<P> s;
    printf("%lld",ans(0,s));
}