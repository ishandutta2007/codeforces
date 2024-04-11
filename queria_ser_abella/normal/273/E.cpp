#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mod 1000000007
#define debug 
using namespace std;

int m1(int a){
    return 1+(a-1)/3;
}

int m2(int a){
    return a-(a-1)/3;
}

int mex(int a,int b){
    int r = 0;
    if(r == a || r == b) r++;
    if(r == a || r == b) r++;
    return r;
}

ll sum(ll a){
    return (a*a+a)/2;
}

ll exp(int a,int b){
    if(b == 0)
        return 1;
    ll k = exp(a,b/2);
    k = (k*k)%mod;
    if(b&1)
        k = (k*a)%mod;
    return k;
}

ll inv(ll a){
    return exp(a%mod,mod-2);
}

ll fat[maxn];

ll C(int n,int a,int b){
    ll r = fat[n];
    r *= inv(fat[a]);
    r %= mod;
    r *= inv(fat[b]);
    r %= mod;
    r *= inv(fat[n-a-b]);
    return r%mod;
}

int main(){
    vector<pii> nim;
    nim.pb(pii(1,0));
    int n,p;
    scanf("%d%d",&n,&p);
    fat[0] = 1;
    for(int i=1;i<=n;i++)
        fat[i] = (fat[i-1]*i) % mod;
    for(int i=4;i<=p;){
        int l = m1(i), r = m2(i);
        int a = 0, b = 0;
        while(a+1 < (int)nim.size() && nim[a+1].first <= l)
            a++;
        while(b+1 < (int)nim.size() && nim[b+1].first <= r)
            b++;
        int t = mex(nim[a].second,nim[b].second);
        if(nim[nim.size()-1].second != t)
            nim.pb(pii(i,t));
        int low = i+1, hi = p+1;
        while(low != hi){
            int mid = (low+hi)/2;
            l = m1(mid), r = m2(mid);
            if(l < nim[a+1].first && r < nim[b+1].first)
                low = mid+1;
            else
                hi = mid;
        }
        debug("%d~%d -> %d\n",i,low-1,t);
        i = low;
    }
    
    int ans = 0;
    ll qtd[3] = {0,0,0};
    
    for(int i=0;i<(int)nim.size();i++){
        int l = nim[i].first, r;
        if(i == (int)nim.size()-1) r = p;
        else r = nim[i+1].first-1;
        if(l == 1) l = 2;
        int t = nim[i].second;
        int A = p-r+1, B = p-l+1;
        qtd[t] += sum(B) - sum(A-1);
        qtd[t] %= mod;
    }
    
    debug("%lld %lld %lld\n",qtd[0],qtd[1],qtd[2]);
    
    ll tot = exp(sum(p-1)%mod,n);
    
    for(int i=0;i<=n;i+=2)
        for(int j=0;i+j<=n;j+=2){
            ll a = exp(qtd[1],i) * exp(qtd[2],j);
            a %= mod;
            a *= exp(qtd[0],n-i-j);
            a %= mod;
            a *= C(n,i,j);
            ans = (ans+a)%mod;
        }
    
    printf("%lld\n",(tot-ans+mod)%mod);
}