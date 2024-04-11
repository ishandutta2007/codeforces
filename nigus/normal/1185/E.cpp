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

const ll MAXN = 2001;

pii F[26];
pii L[26];
char M[MAXN][MAXN];
char M2[MAXN][MAXN];

bool test(){
    rep(c1,0,n){
        rep(c2,0,m){
            if(M2[c1][c2] != M[c1][c2])return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> T;
    rep(c4,0,T){
        cin >> n >> m;
        rep(c1,0,26){
            F[c1] = {-1,-1};
        }

        rep(c1,0,n){
            string s;
            cin >> s;
            rep(c2,0,m){
                M[c1][c2] = s[c2];
                if(s[c2] != '.' && F[s[c2]-'a'].first == -1){
                    F[s[c2]-'a'] = {c1,c2};
                }
                if(s[c2] != '.'){
                    L[s[c2]-'a'] = {c1,c2};
                }
                M2[c1][c2] = '.';
            }
        }
        k = 0;
        string alfa = "abcdefghijklmnopqrstuvwxyz";
        bool fail = 0;
        rep(c1,0,26){
            if(F[c1].first != -1){
                k=c1+1;
                ll x = F[c1].first;
                ll y = F[c1].second;

                if(x != L[c1].first && y != L[c1].second){
                    fail = 1;
                    break;
                }

                M2[x][y] = alfa[c1];
                while(x != L[c1].first || y != L[c1].second){
                    if(x != L[c1].first){
                        x++;
                    }
                    else{
                        y++;
                    }
                    M2[x][y] = alfa[c1];
                }
            }
        }
        if(test() && !fail){
            cout << "YES\n" << k << "\n";
            rep(c1,0,k){
                if(F[c1].first != -1){
                    cout << F[c1].first+1 << " " << F[c1].second+1 << " " << L[c1].first+1 << " " << L[c1].second+1 << "\n";
                }
                else{
                    cout << F[k-1].first+1 << " " << F[k-1].second+1 << " " << L[k-1].first+1 << " " << L[k-1].second+1 << "\n";
                }
            }
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}