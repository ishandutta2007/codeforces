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

const int MAXN = 300001;

set<pll> S;
vector<vi> C(15001, vi());
int now = 0;

int Q = 0;

vector<pii> ANS;

void merg(int a, int b){
    if(a > b)swap(a,b);
    S.erase({sz(C[a]),a});
    S.erase({sz(C[b]),b});
    vi newv;
    int siz = min(sz(C[a]), sz(C[b]));
    rep(_,0,siz){
        int i = C[a].back();
        int j = C[b].back();
      //  cout << i+1 << " " << j+1 << "\n";
        ANS.push_back({i+1, j+1});
        Q++;
        C[a].pop_back();
        C[b].pop_back();
        newv.push_back(i);
        newv.push_back(j);
     }
     now++;
     int ai = b;
     if(sz(C[a]) == 0)ai = a;
     C[ai].clear();
     C[ai] = newv;

     if(sz(C[a]) > 0){
        S.insert({sz(C[a]),a});
     }
     if(sz(C[b]) > 0){
        S.insert({sz(C[b]),b});
     }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    int a,b,c,d,e;

    cin >> n;
    rep(c1,0,n){
        C[c1].push_back(c1);
        S.insert({1,now});
        now++;
    }

    while(sz(S) > 2){

        auto ma = S.end();
        ma--;
        auto mi = S.begin();
        a = (*mi).second;
        b = (*ma).second;

        int prev = -1;
        trav(y, S){
            int i = y.second;
            if(prev != -1 && sz(C[prev]) == sz(C[i])){
                a = prev;
                b = i;
            }
            prev = i;
        }

        merg(a,b);
    }

    cout << sz(ANS) << "\n";
    trav(p, ANS){
        cout << p.first << " " << p.second << "\n";
    }
    //cerr <<"Q: "<< Q;
    return 0;
}