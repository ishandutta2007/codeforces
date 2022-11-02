#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
#define maxn 100100
#define pii pair<int,int> 
#define debug 

int a[maxn];
int b[maxn];
int w[maxn];

set<pii> S[maxn];

main(){

    int n,m;
    int ans = 0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",a+i,b+i,w+i);
    for(int i=m-1;i>=0;i--){
        int u = 1;
        if(S[b[i]].size() > 0){
            set<pii> :: iterator bb = S[b[i]].lower_bound(pii(w[i]+1,-1));
            if(bb != S[b[i]].end())
                u = 1+bb->second;
        }
        debug("%d %d\n",i,u);
        pii ins (w[i],u);
        set<pii> :: iterator it = S[a[i]].lower_bound(pii(w[i],-1));
        if(it != S[a[i]].end() && it->second >= u) continue;
        while(1){
            set<pii> :: iterator bb = S[a[i]].lower_bound(pii(w[i],300300));
            if(bb == S[a[i]].begin()) break;
            bb--;
            if(bb->second > u) break;
            S[a[i]].erase(bb);
        }
        debug("%d ins %d %d\n",a[i],w[i],u);
        S[a[i]].insert(ins);
        ans = max(ans,u);
    }
    printf("%d\n",ans);
}