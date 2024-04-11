#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int llint;
typedef pair < llint,llint> pii;

const llint N = 1e6 + 500;
const llint INF = 0x3f3f3f3f;
const llint MAX = 1e8;

llint n,m,x,y,w,s;
llint group[N],cnt = 1,bio[N][5],dp[N];
llint cost[N];
vector < pii > g[N];
vector < llint > r[N];
vector < llint > v[N];
vector < llint > trok;
map < pii , llint > maap;
vector < llint > prf;
stack < llint > st;

pii mp(llint A,llint B){
	return A < B ? make_pair(A,B) : make_pair(B,A);
}

void trk(){
    trok.push_back(0);
    prf.push_back(0LL);
    int sm = 1;int ad = 1;
    llint dos = 0;
    while(sm <= MAX){
        trok.push_back(sm);
        dos += sm;
        prf.push_back(dos);
        sm += ++ad;
    }
}

void dfs(llint x){
    bio[x][0] = 1;
    for(int i = 0;i<g[x].size();i++)
        if(!bio[g[x][i].first][0])
            dfs(g[x][i].first);
    st.push(x);
}

void kosaraju(llint x){
    group[x] = cnt;
    bio[x][1] = 1;
    for(int i = 0;i<r[x].size();i++)
        if(!bio[r[x][i]][1])
            kosaraju(r[x][i]);
}

void gruphandler(int x){
    bio[x][2] = 1;
    for(int i = 0;i<g[x].size();i++){
        if(group[g[x][i].first] != group[x]){
            v[group[x]].push_back(group[g[x][i].first]);
            maap[mp(group[x],group[g[x][i].first])] = max(maap[mp(group[x],group[g[x][i].first])],g[x][i].second);
        }
        else{
            cost[group[x]] += 
            g[x][i].second * (upper_bound(trok.begin(),trok.end(),g[x][i].second) - trok.begin()) - prf[upper_bound(trok.begin(),trok.end(),g[x][i].second) - 1 -trok.begin()];
        }
        if(!bio[g[x][i].first][2])
            gruphandler(g[x][i].first);

    }
}

llint f(llint x){
    if(dp[x] != -1) return dp[x];
    sort(v[x].begin(),v[x].end());
    v[x].erase(unique(v[x].begin(),v[x].end()),v[x].end());
    dp[x] = 0;
    for(int i = 0;i<v[x].size();i++){
        dp[x] = max(dp[x],f(v[x][i]) + maap[mp(v[x][i],x)]);
    }
    dp[x] += cost[x];
    return dp[x];
}

int main(){
    trk();
    memset(dp,-1,sizeof(dp));
    scanf("%I64d%I64d",&n,&m);
    for(int i = 0;i<m;i++){
        scanf("%I64d%I64d%I64d",&x,&y,&w);
        g[x].push_back(make_pair(y,w));
        r[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)
        if(!bio[i][0])dfs(i);
    while(!st.empty()){
        int x = st.top();
        st.pop();
        if(bio[x][1]) continue;
        kosaraju(x);
        cnt++;
    }
    for(int i = 1;i<=n;i++)
        if(!bio[i][2])
            gruphandler(i);
    scanf("%I64d",&s);
    printf("%I64d\n",f(group[s]));
}