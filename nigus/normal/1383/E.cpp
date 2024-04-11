#pragma GCC optimize("O3")   //
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

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 200001;

string s;
vl A,DP;
vl thing;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> s;
    n = sz(s);
    ll pref = 0;

    while(s[pref] == '0'){
        pref++;
        if(pref == n)break;
    }
    if(pref == n){
        cout << pref << "\n";
        return 0;
    }

    bool prev = 1;
    a = 0;
    rep(c1,pref,n){
        if(s[c1]-'0' != prev){
            A.push_back(a);
            a = 1;
        }
        else{
            a++;
        }
        prev = s[c1]-'0';
    }
    A.push_back(a);
    if(sz(A)%2 == 1)A.push_back(0);

    m = sz(A);
    rep(c1,0,m){
        DP.push_back(0);
        thing.push_back(0);
    }

    reverse(all(A));

    ll sum = 0;
    vl monoq;

    rep(c1,0,m){
        if(c1%2 == 0){
            if(c1 == 0){
                DP[c1] = A[c1]+1;
            }
            else{
                while(sz(monoq) > 0 && A[monoq.back()] <= A[c1]){
                    sum -= thing[monoq.back()];
                    monoq.pop_back();
                    sum += big;
                    sum %= big;
                }

                ll prev = 1;
                if(c1 > 0)prev = DP[c1-1];

                thing[c1] = ((A[c1]) * DP[c1-1])%big;
                if(sz(monoq) > 0){
                    sum -= thing[monoq.back()];
                    sum += big;
                    sum %= big;
                    int j = monoq.back();
                    thing[j] = ((A[j] - A[c1])*DP[j-1])%big;
                    sum += thing[j];
                    sum %= big;
                }
                monoq.push_back(c1);
                sum += thing[c1];
                sum %= big;
                DP[c1] = sum;

                DP[c1]+=A[0]+1;
                DP[c1] %= big;
            }

        }
        else{
            if(c1 == 1){
                DP[c1] = (A[c1] * DP[c1-1])%big;
            }
            else{
                DP[c1] = A[c1] * (DP[c1-1]) + DP[c1-2];
                DP[c1] %= big;
            }
        }
    }

    cout << ((pref+1)*DP[m-1])%big << "\n";


    return 0;
}