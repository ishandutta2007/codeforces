#include <bits/stdc++.h>
#define pii pair<ll,ll>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug
using namespace std;

ll dp[maxn];
vector<int> L[maxn];
vector<pii> road[maxn];
int prof[maxn];
int id[maxn];
set<pii> S[maxn];
ll lazy[maxn];

void dfs(int x,int p=-1){
    if(x && L[x].size() == 1){
        if(road[x].size() == 0){
            printf("-1\n");
            exit(0);
        }
        id[x] = x;
        for(int i=0;i<road[x].size();i++)
            S[x].insert(pii(road[x][i].second,road[x][i].first));
        dp[x] = S[x].begin()->first;
        debug("dp[%d] = %d\n",x,dp[x]);
        return;
    }
    vector<pii> v;
    int m = 0 ;
    ll s = 0;
    for(int i=0;i<L[x].size();i++){
        if(L[x][i] == p) continue;
        prof[L[x][i]] = 1 + prof[x];
        dfs(L[x][i],x);
        s += dp[L[x][i]];
        v.pb(pii(id[L[x][i]],dp[L[x][i]]));
        if(S[v[v.size()-1].first].size() > S[v[m].first].size())
            m = v.size()-1;
    }
    swap(v[0],v[m]);
    int l = v[0].first;
    debug("lazy += %lld - %lld\n",s,v[0].second);
    lazy[l] += s - v[0].second;
    for(int i=1;i<v.size();i++)
        for(set<pii> :: iterator it = S[v[i].first].begin(); it != S[v[i].first].end(); it++){
            pii A = *it;
            A.first += s - v[i].second + lazy[v[i].first] - lazy[l];
            debug("++ %lld\n",A.first);
            S[l].insert(A);
        }
    for(int i=0;i<road[x].size();i++){
        if(prof[road[x][i].first] > prof[x]) continue;
        debug("+ %d + %lld\n",road[x][i].second,s);
        S[l].insert(pii((ll)road[x][i].second+s-lazy[l],road[x][i].first));
    }    
    
    debug("x %d l %d\n",x,S[l].size());
    if(x == 0){
        if(S[l].size() == 0){
            printf("-1\n");
            exit(0);
        }
        dp[x] = S[l].begin()->first + lazy[l];
        return;
    }
    while(S[l].size() && prof[S[l].begin()->second] >= prof[x])
        S[l].erase(S[l].begin());
    debug("l %d\n",S[l].size());
    if(S[l].size() == 0){
        printf("-1\n");
        exit(0);
    }
    dp[x] = S[l].begin()->first + lazy[l];
    debug("dp[%d] = %d\n",x,dp[x]);
    id[x] = l;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 1){
        printf("0\n");
        return 0;
    }
    for(int i=0,a,b;i<n-1;i++){
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    for(int i=0,a,b,c;i<m;i++){
        scanf("%d%d%d",&a,&b,&c), a--, b--;
        if(a == b) continue;
        road[a].pb(pii(b,c));
        road[b].pb(pii(a,c));
    }
    dfs(0);
    printf("%lld\n",dp[0]);
}