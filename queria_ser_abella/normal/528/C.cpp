#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb insert
#define maxn 300300
#define ll long long
#define debug printf
using namespace std;

multiset<int> L[maxn];
int foi[maxn];
int par = 0;
vector<pii> r;
int c[maxn];
int ans;

void dfs(int x,int p){
    foi[x] = 1;
    while(L[x].size()){
        int u = *L[x].begin();
        L[x].erase(L[x].find(u));
        L[u].erase(L[u].find(x));
        dfs(u,x);
    }
    if(p != -1){
        if(par) swap(x,p);
        c[x]++;
        r.push_back(pii(x,p));
        par ^= 1;
    }
    else if(p == -1 && c[x]%2 == 1){
        ans++;
        r.push_back(pii(x,x));
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0,a,b;i<m;i++){
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    int u = -1;
    ans = m;
    for(int i=0;i<n;i++)
        if(L[i].size()%2 == 1){
            if(u+1){
                L[u].pb(i);
                L[i].pb(u);
                ans++;
                u = -1;
            }
            else u = i;
        }
    for(int i=0;i<n;i++)
        if(!foi[i])
            dfs(i,-1);
    printf("%d\n",ans);
    for(int i=0;i<r.size();i++)
        printf("%d %d\n",r[i].first+1,r[i].second+1);
    
}