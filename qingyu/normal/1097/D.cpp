#include<iostream>
#include<string.h>
#include<vector>
#include<utility>
#define MOD 1000000007L
using namespace std;

typedef long long ll;
ll N,K;
ll mul(ll a, ll b){ return (a*b)%MOD; }
ll add(ll a, ll b){ return (a+b)%MOD; }
ll pow(ll a, ll b){
    ll res = 1;
    while(b){
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
ll dp[70];
ll inv(ll a){ 
    if (dp[a] != -1) return dp[a];
    dp[a] = pow(a, MOD-2);
    return dp[a];
}

vector<ll> factor(){
    ll i = 2;
    ll tmp = N;
    vector<ll> ret;
    while(i*i<=N){
        if (tmp%i==0){
            ret.push_back(i);
            tmp /= i;
        }else{
            i++;
        }
    }
    if (tmp!=1) ret.push_back(tmp);
    return ret;
}

vector<ll> primes;
vector<int> cnt;
ll x = 0;
vector<ll> eva(ll occ){
    vector<ll> p(occ+1), pp(occ+1);
    for (int i=0;i<p.size();i++)
        p[i] = inv(occ+1);
    for (int i=1;i<K;i++){
        for (int j=0;j<pp.size();j++)
            pp[j] = 0;
        for (int j=0;j<=occ;j++){
            for (int l=0;l<=j;l++){
                x++;
                pp[l] = add(pp[l], mul(p[j], inv(j+1)));
            }
        }
        for (int j=0;j<pp.size();j++)
            p[j] = pp[j];
    }
    return p;
}
void log(vector<ll> x){
    for (int i=0;i<x.size();i++)
        cout << x[i] << " ";
    cout << endl;
}
void log(vector<int> x){
    for (int i=0;i<x.size();i++)
        cout << x[i] << " ";
    cout << endl;
}
int main(void){
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> buff = factor();
    primes.push_back(buff[0]);
    cnt.push_back(1);

    for (int i=1;i<buff.size();i++){
        if (buff[i] == primes[primes.size()-1]) cnt[cnt.size()-1]++;
        else{
            primes.push_back(buff[i]);
            cnt.push_back(1);
        }
    }
    ll ans = 1;
    for (int i=0;i<primes.size();i++){  
        vector<ll> p = eva(cnt[i]);
        ll tmp = 0;
        ll pow = 1;
        for (int j=0;j<p.size();j++){
            tmp = add(tmp, mul(p[j], pow));
            pow = mul(pow, primes[i]);
        }
        ans = mul(ans, tmp);
    }
    cout << ans << endl;
}