#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

const ll inf = (ll)4e18;

bool Q;

struct Line{
    ll a;
    ll b;
    mutable ll p;
    bool operator< (const Line &T) const {
        if(Q) return p < T.p;
        else return a < T.a;
    }
};


struct Hull : multiset<Line> {

    ll div(ll x, ll y){
        return (x / y) - ((x ^ y) < 0 && x % y != 0);
    }

    bool check(iterator x, iterator y){
        if(y == end()){
            x->p = inf;
            return false;
        }
        if(x->a == y->a){
            if(x->b > y->b) x->p = inf;
            else x->p = -inf;
        }
        else{
            x->p = div(x->b - y->b, y->a - x->a);
        }
        return x->p >= y->p;
    }

    void add(ll ai, ll bi){
        Q=false;
        auto it = insert({ai, bi, 0});
        auto nx = it;
         ++ nx;
        while(check(it,nx))
            nx=erase(nx);
        nx = it;
        if(nx != begin()){
            -- nx;
            if(check(nx,it)){
                it=erase(it);
                check(nx,it);
            }
        }
        while(1){
            if(nx==begin()) break;
            it=nx;
            --nx;
            if(nx->p >= it->p){
                it=erase(it);
                check(nx,it);
            }
            else{
                break;
            }
        }
    }
    ll query(ll x){
        Q=true;
        auto it = lower_bound({0,0,x});
        return x * it->a + it->b;
    }
};


ll f[N];
ll s[N];
ll pf[N];

Hull lines;

int main(){
    fastIO;
    int n;
    cin >> n;
    ll answ = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> s[i];
        f[i] = (s[i] * 1ll * i);
        answ += f[i];
        f[i] += f[i - 1];
        pf[i] += pf[i - 1] + s[i];
    }
    for(ll i = n ;i >= 1; i -- ){
        if(i != n){
            answ = max(answ, f[n] + f[i-1] - f[i] + pf[i] + lines.query(s[i]));
        }
        lines.add(i, -pf[i]);
    }
    lines.clear();
    for(ll i = 1 ; i <= n; i ++ ){
        if(i != 1){
            answ = max(answ, f[n] - f[i] + f[i-1] + pf[i-1] + lines.query(s[i]));
        }
        lines.add(i, -pf[i-1]);
    }
    cout << answ << "\n";
    return 0;
}