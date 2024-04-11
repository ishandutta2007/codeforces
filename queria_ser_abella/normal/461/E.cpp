#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
#define inf (1ll<<61)
#define debug 
using namespace std;

ll dist[4][4];
int qnt[4][4];
char str[maxn];
int len;

set<ll> S[4][4];

ll dp[4][4][80];;

void add(ll &val,char ch){
    val *= 4;
    val += ch-'A';
}

void go(int t){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            S[i][j].clear();
    memset(qnt,0,sizeof(qnt));
    ll hash = 0;
    for(int i=1;i<t-1;i++)
        add(hash,str[i]);
    for(int i=0;i<len-t+1;i++){
        S[str[i]-'A'][str[i+t-1]-'A'].insert(hash);
        add(hash,str[i+t-1]);
        hash &= (1<<(2*t-4))-1;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            qnt[i][j] = S[i][j].size();
}

ll ans[4][4];
ll aux[4][4];

ll eval(ll t){
    t--;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            ans[i][j] = ((i == j) ? 1 : inf);
    for(int k=0;k<63;k++)
        if(t & (1ll<<k)){
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    aux[i][j] = inf;
                    for(int l=0;l<4;l++)
                        aux[i][j] = min(aux[i][j],ans[i][l]+dp[l][j][k]);
                }
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    ans[i][j] = aux[i][j];
        }
    ll r = inf, ii, jj;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            r = min(r,ans[i][j]);
    debug("eval %lld -> %lld\n",t,r);
    return r;
}

int main(){
    
    ll n;
    scanf("%lld %s",&n,str);
    len = strlen(str);
    
    int t = 1, foi = 0;
    while(!foi){
        t++;
        go(t);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(qnt[i][j] != (1<<(2*t-4)))
                    foi = 1;
    }
    t--;
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            dist[i][j] = inf;
    
    go(t+2);
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(qnt[i][j] != (1<<(2*t)))
                dist[i][j] = t+1;
    
    go(t+1);
    
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(qnt[i][j] != (1<<(2*t-2)))
                dist[i][j] = t;
                
    debug("t = %d\n",t);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            debug("d[%c][%c] = %lld\n",'A'+i,'A'+j,dist[i][j]);
    
    for(int k=0;k<80;k++)
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                if(k == 0){
                    dp[i][j][k] = dist[i][j];
                    continue;
                }
                dp[i][j][k] = inf;
                for(int l=0;l<4;l++)
                    dp[i][j][k] = min(dp[i][j][k],dp[i][l][k-1]+dp[l][j][k-1]);
            }
    
    ll lo = 1, hi = inf;
    while(lo < hi){
        ll mid = (lo+hi+1)/2;
        if(eval(mid) <= n)
            lo = mid;
        else
            hi = mid-1;
    }
    printf("%lld\n",hi);
}