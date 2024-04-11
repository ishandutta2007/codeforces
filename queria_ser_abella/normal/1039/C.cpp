#include <bits/stdc++.h>
#define maxn 500500
#define mod 1000000007
#define pb push_back
#define debug 
#define pii pair<int,int>
typedef long long ll;
using namespace std;

ll p2(ll a){
    if(a == 0)
        return 1;
    ll r = p2(a/2);
    r = (r*r) % mod;
    if(a&1)
        r = (r*2) % mod;
    return r;
}

map<ll,int> mp;

vector<pii> E[maxn];

ll val[maxn];

int pai[maxn];
int last[maxn];
int uf = 1;
inline int find(int x){
    if(last[x] < uf){
        last[x] = uf;
        pai[x] = x;
    }
    return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}
inline void merge(int a,int b){
    a = find(a);
    b = find(b);
    last[a] = last[b] = uf;
    if(a == b) return;
    pai[a] = b;
}


int main(){
    
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=0;i<n;i++)
        scanf("%lld",val+i);
        
    int cur = 1;
        
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        ll xx = val[a] ^ val[b];
        if(mp[xx] == 0)
            mp[xx] = cur++;
        int id = mp[xx];
        //debug("%lld -> %d\n",xx,mp[xx]);
        E[id].pb(pii(a,b));
        
    }
    
    ll ans = 0;
    
    for(int i=1;i<cur;i++){
        uf++;
        int uu = n;
        for(int j=0;j<E[i].size();j++){
            pii u = E[i][j];
            int A = u.first, B = u.second;
            A = find(A);
            B = find(B);
            if(A != B) uu--;
            merge(A,B);
        }
        ll qtd = p2(n) - p2(uu) + mod;
        debug("i %d uu %d\n",i,uu);
        qtd %= mod;
        ans += qtd;
        ans %= mod;

    }
    
    ll res = ( p2(n) * p2(k)) % mod;
    res -= ans;
    res += mod;
    res %= mod;
    printf("%lld\n",res);
}