#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ui n,m,k,T,q;

ui a,b,c,d;
ui const len = 10000003;
vector<ui> primes;
bitset<len> B;


void zero(){
    B = 0;
}

ui f(ui i){
    return i*(i*(i*a+b)+c)+d;
}

ui start(ui p, ui i){
    if(i%p == 0)return i;
    return (i-i%p+p);
}

bool isprime(ui p){
    int lim = min(sz(primes),10);

    for(int c1 = 0; c1 < lim; c1++){
        if(p == primes[c1])return 1;
        if(p%primes[c1] == 0)return 0;
    }

    for(int c1 = 0; c1 < sz(primes) && primes[c1]*primes[c1] <= p; c1++){
        if(p%primes[c1] == 0)return 0;
    }
    return 1;

}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    cin >> n >> a >> b >> c >> d;
    k = 0;
    ui ans = 0;

    for(int c1 = 2; c1 <= n; c1++){

        if(c1%len == 0 && c1 != 0){
            zero();
            k++;

            for(int c2 = 0; c2 < sz(primes); c2++){
                for(int c3 = start(primes[c2],c1)-k*len; c3 < len; c3 += primes[c2]){
                    B[c3] = 1;
                }
            }
           // primes.clear();
        }

        if(B[c1-k*len] == 0){

          //  if(isprime(c1)){

            ll t = c1;
            while(t <= n){
                ans += (n/t) * f(c1);
                t *= c1;
            }

            if(c1 < 20000)primes.push_back(c1);

            for(int c2 = c1; c2 < len+k*len; c2 += c1){
                B[c2-k*len] = 1;
            }

        }
    }


    cout << ans << "\n";

    return 0;
}