#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll big2 = 998244353;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> D(0, 2000000001);

ll random(ll r){
    return D(eng)%r;
}

string s;
ll moves = 0;

char geta(ll i, ll j, ll a){
    if(i%a < j%a)return 'y';
    return 'x';
}

bool ask(ll i, ll j){
    cout << "? " << i << " " << j << "\n";
    moves++;
    fflush(stdout);
    char ch;
    cin >> ch;

    //ch = geta(i,j,n);

    return (ch == 'y');
}

void answer(ll i){
    cout << "! " << i << "\n";
    fflush(stdout);
    return;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    c = 0;
    while(1){
        cin >> s;
/*
        s = "hjk";
        n = 1000000000-c;
        c++;*/
        //cin >> n;

        if(s == "end" || s == "mistake"){
            break;
        }
        moves = 0;

        if(!ask(0,1)){
            answer(1);
            continue;
        }

        ll l = 1;
        ll r = 2;
        while(ask(l,r)){
            l *= 2;
            r *= 2;
        }

        while(l < r-1){
            ll mid = (l+r)/2;

            bool b1 = ask(l,mid);
            if(b1){
                l = mid;
            }
            else{
                r = mid;
            }

        }
        answer(r);
        //assert(moves <= 60);
        //cerr << "#HJK: " << moves << "\n";
    }


    return 0;
}