#pragma GCC optimize("O3")
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

const ll MAXN = 400004;

vi A;

vi ANS;

void mov(ll i){
    ANS.push_back(i);
    ll x = (A[i]^A[i+1]^A[i+2]);
    rep(c1,0,3){
        A[i+c1] = x;
    }
}

void even(ll i, ll j){
    if(j == n-1){
        for(int c1 = i-1; c1 < j; c1 += 2){
            mov(c1);
        }
    }
    else{
        for(int c1 = j-1; c1 >= i; c1 -= 2){
            mov(c1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
       // n = 100;
        A.clear();
        ANS.clear();
        b = 0;
        rep(c1,0,n){
            cin >> a;
           // a = rand()%2;
            A.push_back(a);
            b += a;
        }

        if(b%2 == 1 || b == n){
            cout << "NO\n";
            continue;
        }


        ll start = -1;

        rep(c1,0,n){
            if(A[c1] == 0){
                if(start == -1)continue;
                int parity = (c1-start)%2;

                if(parity == 0){
                    even(start, c1-1);
                    start = -1;
                }
                else{
                    if(A[c1+1] == 1){
                        mov(c1-1);
                        even(start, c1-2);
                        start = -1;
                    }
                    else{
                        mov(c1-1);
                    }
                }

            }
            else{
                if(start == -1){
                    start = c1;
                }
            }
        }

        start = -1;
        rep(c1,0,n){
            if(A[c1] == 1){
                start = c1;
                break;
            }
        }
        if(start != -1){
            if(start == 0){
                cout << "NO\n";
                continue;
            }
            else{
                even(start, n-1);
            }
        }

        /*
        rep(c1,0,n){
            if(A[c1] != 0 || sz(ANS) > n){
                cerr << "NOOOOOOO\n";
                return 0;
            }
        }
    */

        cout << "YES\n";
        cout << sz(ANS) << "\n";
        trav(y, ANS){
            cout << y+1 << " ";
        }cout << "\n";




    }

    return 0;
}