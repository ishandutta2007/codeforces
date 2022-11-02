#include <bits/stdc++.h>
#define pii pair<ll,int>
#define maxn 1001000
#define pb push_back
#define ll long long
#define debug 
using namespace std;

ll v[maxn];
ll a[maxn];

char ch;
inline void rd(ll &x){
    x = 0;
    while((ch=getchar()) >= '0')
        x = 10*x+ch-'0';
}

map<ll,int> mp;
map<ll,int> freq;
vector<pii> moeb;
ll ans;        
ll n;

map<ll,int> aaa;

void go(ll x){
    if(x < ans) return;
    if(aaa[x]) return;
    aaa[x] = 1;
    ll u = mp[x];
    ll up = 1+((1e12)/x);
    for(int i=0;i<moeb.size() && moeb[i].first <= up; i++)
        u += freq[x*moeb[i].first] * moeb[i].second;
    if(2*u >= n)
        ans = max(ans,x);
    freq[x] = u;
    //debug("add %lld freq %lld\n",x,freq[x]);
}

int main(){
    rd(n);
    for(int i=0;i<n;i++)
        rd(v[i]);
    srand(4356);
    ans = 0;
    map<ll,int> foi;
    for(int t=0;clock() < 3.5 * CLOCKS_PER_SEC;t++){
        int u = (rand()*rand()+rand())%n;
//        u = 0;
		if(foi[v[u]]){
			
			continue;
		}
		foi[v[u]] = 1;
        mp.clear();
        freq.clear();
        moeb.clear();
        for(int i=0;i<n;i++){
            a[i] = __gcd(v[i],v[u]);
            mp[a[i]]++;
        }
        vector<int> pr;
        ll aux = v[u];
        debug("aux %lld\n",aux);
        for(ll i=2;i*i<=aux;i++)
            if(aux%i == 0){
                while(aux%i == 0)
                    aux /= i;
                pr.pb(i);
            }
        if(aux != 1)
            pr.pb(aux);
        debug("pr %d\n",pr.size());
        for(int i=0;i<(1<<pr.size());i++){
            ll pi = 1;
            int sign = -1;
            int ok = 1;
            ll up = 1+((1e13)/pi);
            for(int k=0;k<pr.size();k++)
                if(i & (1<<k)){
                    sign = -sign;
                    if( pr[k] >= 1 + ((1e13)/pi)) ok = 0;
                    pi *= pr[k];
                }
            if(pi > 1 && ok){
                moeb.pb(pii(pi,sign));
                debug("+ %d %lld\n",sign,pi);
            }
        }
        sort(moeb.begin(),moeb.end());
        ll j;
        for(j=1;j*j<=v[u];j++)
            if(v[u]%j == 0){
                go(v[u]/j);
                if(j*j == v[u]){
                    j--;
                    break;
                }
            }
        for(;j>=1;j--)
            if(v[u]%j == 0){
                go(j);
            }
    }
    printf("%lld\n",ans);
}