#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

const ll mod = 1e9+7;

ll f[200005];

ll rev(ll x){
    ll y = mod-2;
    ll rez = 1;
    while(y){
        if(y%2) rez = (rez*x)%mod;
        x = (x*x)%mod;
        y>>=1;
    }
    return rez;
}

ll c(ll n,ll k){
    if(n<k) return 0;
    ll t = rev(f[n-k])*rev(f[k]);
    t%=mod;
    return (f[n]*t)%mod;
}

void ini(){
    f[0] = 1;
    f[1] = 1;
    for(int j = 2;j<200005;j++){
        f[j] = f[j-1]*j;
        f[j]%= mod;
    }
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ini();
    string s;
    cin >> s;
    int n = s.size();
    ll cnt = 0;
    ll cnt1 = 0;
    for(int j = 0;j<n;j++)
        if(s[j] == ')')
            cnt1++;

    ll rez = 0;
    ll x;
    ll y;
    for(int i = 0;i<n;i++){
        if(s[i] == '('){
            cnt++;
            x = cnt;
            y = cnt1;
            rez = (rez+c(x+y-1,x))%mod;
        }
        else{
            cnt1--;
        }
    }
    cout << rez;
    return 0;
}