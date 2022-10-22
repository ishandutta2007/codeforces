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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);

ll random2(){
    return (1ll << 31ll)*eng()+eng();
}


ll n,m,k,q,T;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 100001;

int kicks(string &s, int win){
    int res = 0;
    int x1 = 0;
    int x2 = 0;

    rep(c1,0,10){
        bool score = 0;
        if(s[c1] != '?'){
            score = s[c1]-'0';
        }
        else{
            score = (win^(c1%2));
        }
        if(c1%2 == 0){
            x1 += score;
        }
        else{
            x2 += score;
        }
        res++;
        int l1 = (10-c1-1)/2;
        int l2 = (10-c1)/2;
        if(x1+l1 < x2)return res;
        if(x2+l2 < x1)return res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;
    rep(c4,0,T){
        string s;
        cin >> s;
        int ans = min(kicks(s,0), kicks(s,1));
        cout << ans << "\n";
    }

    return 0;
}