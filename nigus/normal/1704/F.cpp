#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const ll MAXN = 500006;

int NIM[MAXN] = {0};

void brute(int lim){
    NIM[0] = 0;
    NIM[1] = 0;
    NIM[2] = 1;
    rep(c1,3,lim+1){
        set<int> hej;
        rep(c2,0,c1-1){
            int a = c2;
            int b = c1-a-2;
            int xo = (NIM[a]^NIM[b]);
            hej.insert(xo);
        }
        rep(c2,0,c1+1){
            if(hej.find(c2) == hej.end()){
                NIM[c1] = c2;
                break;
            }
        }
    }
}

int nim(int x){
    if(x < 150)return NIM[x];
    int x2 = x%34+34*5;
    return NIM[x2];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d;

    brute(1000);

    cin >> T;
    rep(c4,0,T){
        cin >> n;
        ll EXTRA[2] = {0};
        string s;
        cin >> s;
        vi L;
        vi parity;
        int last = 0;
        rep(c1,0,n){
            if(c1 > 0 && s[c1] != s[c1-1] && (c1 == n-1 || s[c1] == s[c1+1])){

                if((c1-last+1)%2 == 1){
                    EXTRA[(s[last] != 'R')]++;
                }

                L.push_back(c1-last+1);
                parity.push_back((s[last] != 'R'));
            }
            if(c1 > 0 && s[c1] == s[c1-1]){
                last = c1;
            }
            if(c1 > 0 && c1 < n-1 && s[c1] == s[c1-1] && s[c1] == s[c1+1]){
                EXTRA[(s[c1] != 'R')]++;
            }
        }


        if(s[0] == s[1]){
            EXTRA[(s[0] != 'R')]++;
        }
        if(s[n-2] == s[n-1]){
            EXTRA[(s[n-1] != 'R')]++;
        }

        int xo = 0;
        trav(y, L){
            xo ^= nim(y);
        }

        if(xo != 0){
            EXTRA[0]++;
        }

       // cerr << EXTRA[0] << " " << EXTRA[1] << " g\n";


        if(EXTRA[0] > EXTRA[1]){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
        
    }

    return 0;
}