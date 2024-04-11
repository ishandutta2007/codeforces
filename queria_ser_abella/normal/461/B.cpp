#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
#define debug
#define pb push_back
#define mod 1000000007
using namespace std;

vector<int> L[maxn];
int cor[maxn];

int dp[2][maxn];

int tot[maxn];
int pref[maxn];
int suf[maxn];

int get(int up,int v){
    int &r = dp[up][v];
    if(r+1)
        return r;
    if(cor[v] && up == 0)
        return 0;
    if(L[v].size() == 0){
        if(!cor[v] && up) return 0;
        return 1;
    }
    int t = L[v].size();
    for(int i=0;i<t;i++)
        get(0,L[v][i]), get(1,L[v][i]);
        
    for(int i=0;i<t;i++)
        tot[i] = (get(0,L[v][i]) + get(1,L[v][i])) % mod;
    
    pref[0] = tot[0];
    for(int i=1;i<t;i++)
        pref[i] = ((ll)pref[i-1]*tot[i]) % mod;
    suf[t-1] = tot[t-1];
    for(int i=t-2;i>=0;i--)
        suf[i] = ((ll)suf[i+1]*tot[i]) % mod;
        
    r = 0;
    for(int i=0;i<t;i++){
        ll u = 1;
        if(i) u *= pref[i-1];
        if(i < t-1) u *= suf[i+1];
        u %= mod;
        r += ((ll)get(1,L[v][i])*u) % mod;
        r %= mod;
    }
    
    if(cor[v])
        r = pref[t-1];
    if(cor[v] == 0 && !up)
        r = pref[t-1];
    
    return r;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    for(int i=1,p;i<n;i++){
        scanf("%d",&p);
        L[p].pb(i);
    }
    for(int i=0;i<n;i++)
        scanf("%d",cor+i);
    printf("%d\n",get(1,0));
}