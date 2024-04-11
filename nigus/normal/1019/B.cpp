#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

ll ask(ll i){
    cout << "? " << i+1 << "\n";
    fflush(stdout);
    ll a;
    cin >> a;
    return a;
}

void answer(ll i){
    cout << "! " << i+1 << "\n";
    fflush(stdout);
    return;
}



int main(){
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n;
    ll n2 = n/2;
    if(n2%2 == 1){
        answer(-2);
        return 0;
    }

    ll l = 0;
    ll r = n2-1;

    ll diffl = ask(n2)-ask(0);
    ll diffr = ask(n-1)-ask(n2-1);

    if(diffl == 0){
        answer(0);
        return 0;
    }

    if(diffr == 0){
        answer(n-1);
        return 0;
    }

    while(l < r-1){
        ll mid = (l+r)/2;
        ll diffmid = ask(mid+n2)-ask(mid);
        if(diffmid == 0){
            answer(mid);
            return 0;
        }
        if(diffmid*diffl >= 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }

    diffl = ask(l+n2)-ask(l);
    if(diffl == 0){
        answer(l);
        return 0;
    }

    diffr = ask(r+n2)-ask(r);
    if(diffr == 0){
        answer(r);
        return 0;
    }

    assert(0);

    return 0;
}