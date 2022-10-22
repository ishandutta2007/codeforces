
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

ll N[4] = {0};
ll N2[4] = {0};

bool test(vi &A){
    rep(c1,0,4){
        N2[c1] = 0;
    }
    rep(c1,0,sz(A)-1){
        if(abs(A[c1]-A[c1+1]) != 1)return 0;
    }
    trav(y,A){
        //cerr << y << " ";
        N2[y]++;
    }//cerr << "\n";
    rep(c1,0,4){
        if(N2[c1] != N[c1])return 0;
    }
    return 1;
}

vi ANS;

vi gen(int start, int p1, int p2){
    rep(c1,0,4){
        N2[c1] = N[c1];
    }
    ll n1 = 0;
    ll n2 = 1;
    if(p1 == 0)n1 = 2;
    if(p2 == 1)n2 = 3;

    vi res;
    res.push_back(start);
    N2[start]--;
    rep(c1,1,n){
        if(res[c1-1] == 0){
            res.push_back(1);
            N2[1]--;
        }
        if(res[c1-1] == 1){
            if(N2[p1] > 0){
                res.push_back(p1);
                N2[p1]--;
            }
            else{
                res.push_back(n1);
                N2[n1]--;
            }
        }

        if(res[c1-1] == 3){
            res.push_back(2);
            N2[2]--;
        }
        if(res[c1-1] == 2){
            if(N2[p2] > 0){
                res.push_back(p2);
                N2[p2]--;
            }
            else{
                res.push_back(n2);
                N2[n2]--;
            }
        }

    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;
    n = 0;
    rep(c1,0,4){
        cin >> N[c1];
        n += N[c1];
    }

    for(int start = 0; start < 4; start++){
        for(int p1 = 0; p1 <= 2; p1 += 2){
            for(int p2 = 1; p2 <= 3; p2 += 2){
                vi temp = gen(start,p1,p2);
                if(test(temp)){
                    ANS = temp;
                    break;
                }
            }
        }

    }

    if(sz(ANS) > 0){
        cout << "YES\n";
        trav(y,ANS){
            cout << y << " ";
        }cout << "\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}