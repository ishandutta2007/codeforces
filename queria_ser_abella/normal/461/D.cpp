#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007
#define debug
using namespace std;

vector<pii> L[maxn];
int fix[maxn];
int foi[maxn];
int val[maxn];
int ok = 1;

void dfs(int v){
    foi[v] = 1;
    for(int i=0;i<(int)L[v].size();i++){
        int u = L[v][i].first, x = L[v][i].second;
        if(fix[u] && (val[v]^val[u]) != x)
            ok = 0;
        if(!foi[u]){
            fix[u] = 1;
            val[u] = val[v]^x;
            dfs(u);
        }
    }
}

void add(int l,int r,int d){
    debug("add %d %d %d\n",l,r,d);
    if(l <= 1){
        if(fix[r] && val[r] != d)
            ok = 0;
        fix[r] = 1;
        val[r] = d;
        return;
    }
    L[r].pb(pii(l-2,d));
    L[l-2].pb(pii(r,d));
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int r,c;
        char ch;
        scanf("%d%d %c",&r,&c,&ch);
        r--, c--;
        int tl = c;
        int tr = n-1-c;
        int T = r;
        if(T <= tl && T <= tr){
            add(c-T,c+T,ch=='o');
            continue;
        }
        if(tr <= tl){
            T -= tr;
            int a = c-tr, b = c+tr;
            tl = a;
            if(T <= tl){
                a -= T;
                b -= T;
            }
            else {
                T -= tl;
                a -= tl;
                b -= tl;
                a += T;
                b -= T;
            }
            add(a,b,ch=='o');
        }
        else {
            T -= tl;
            int a = c-tl, b = c+tl;
            tr = n-1-b;
            if(T <= tr){
                a += T;
                b += T;
            }
            else {
                T -= tr;
                a += tr;
                b += tr;
                b -= T;
                a += T;
            }
            add(a,b,ch=='o');
        }
    }
      
    int ans = 0;
    for(int i=0;i<n;i++)
        if(fix[i] && !foi[i]){
            dfs(i);
        }
    
    for(int i=0;i<n;i++)
        if(!foi[i]){
            fix[i] = 1;
            dfs(i);
            ans++;
        }
        
    int t = 1;
    while(ans--){
        t = (2*t)%mod;
    }
    if(!ok) t = 0;
    printf("%d\n",t);
    
}