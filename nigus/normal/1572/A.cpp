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



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("fhc.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(c4,0,T){
        cin >> n;
        vector<vi> out(n, vi());
        vi indeg(n, 0);
        rep(c1,0,n){
            cin >> c;
            rep(c2,0,c){
                cin >> a;
                a--;
                indeg[c1]++;
                out[a].push_back(c1);
            }
        }

        set<int> S,SS;
        int done = 0;

        vector<bool> seen(n, 0);


        int ans = 0;


        rep(c1,0,n){
            if(indeg[c1] == 0 && seen[c1] == 0){
                SS.insert(c1);
            }
        }

        while(1){
            S = SS;
            SS.clear();
            if(sz(S) == 0){
                ans = -1;
                break;
            }

            while(!S.empty()){
                a = *S.begin();
                S.erase(a);
                done++;
                seen[a] = 1;
                trav(y, out[a]){
                    indeg[y]--;
                    if(indeg[y] == 0 && y > a && seen[y] == 0){
                        S.insert(y);
                    }
                    else{
                        if(indeg[y] == 0 && y <= a && seen[y] == 0){
                            SS.insert(y);
                        }
                    }
                }
            }
            ans++;

            if(done == n)break;

        }

        cout << ans << "\n";

    }

    return 0;
}