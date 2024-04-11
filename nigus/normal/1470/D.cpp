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

vector<vi> C(MAXN, vi());

bool mark[MAXN] = {0};
bool inq[MAXN] = {0};
queue<int> Q;
vi ANS;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> T;

    rep(_,0,T){
        cin >> n >> m;
        ANS.clear();
        rep(c1,0,n){
            C[c1].clear();
            mark[c1] = 0;
            inq[c1] = 0;
        }
        rep(c1,0,m){
            cin >> a >> b;
            a--;b--;
            C[a].push_back(b);
            C[b].push_back(a);
        }
        Q.push(0);
        c = 0;
        while(!Q.empty()){
            a = Q.front();
            Q.pop();
            if(!mark[a]){
                mark[a] = 1;
                c++;
                ANS.push_back(a);
                trav(y, C[a]){
                    if(!mark[y]){
                        mark[y] = 1;
                        c++;
                        trav(z, C[y]){
                            if(!mark[z])Q.push(z);
                        }
                    }
                }
            }
        }
        if(c != n){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << sz(ANS) << "\n";
            trav(y, ANS){
                cout << y+1 << " ";
            }cout << "\n";
        }
    }


    return 0;
}