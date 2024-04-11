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
const ll MAXN = 100000;

const ll ss = 52;
ll F[ss] = {0};
string s;

ll upp(ll i, ll j){
if(j == 0)return 1;
ll h = upp(i,j/2);
if(j%2 == 0)return (h*h)%big;
return (((h*h)%big)*i)%big;
}

ll FAC[2*MAXN] = {0};
ll INV[2*MAXN] = {0};

ll DP[ss][MAXN] = {0};
ll DPC[ss][MAXN] = {0};

vl vec;
ll counter = 0;

ll ANS[ss][ss] = {0};
ll ANSC[ss][ss] = {0};

ll SS[MAXN+1] = {0};

void add(ll f){
    for(ll c1 = n/2; c1 >= f; c1--){
        SS[c1] += SS[c1-f];
        if(SS[c1]>=big)SS[c1]-=big;
    }
}

void sub(ll f){
    for(ll c1 = f; c1 <= n/2; c1++){
        SS[c1] -= SS[c1-f];
        if(SS[c1]<0)SS[c1]+=big;
    }
}

ll dp(ll i, ll j){
    if(j < 0)return 0;
    if(i == sz(vec))return (j == 0);
    if(DPC[i][j] == counter)return DP[i][j];
    ll ans = 0;
    ans = dp(i+1,j);
    ans += dp(i+1,j-vec[i]);
    if(ans >= big)ans %= big;

    DPC[i][j] = counter;
    DP[i][j] = ans;
    return ans;
}

ll stuff(){

    ll ans = (FAC[n/2]*FAC[n/2])%big;
    for(int c1 = 0; c1 < sz(vec); c1++){
        //cerr << vec[c1] << "  gfd\n";
        ans *= INV[vec[c1]];

        ans %= big;
    }
    return ans;
}

ll ctn(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return 26+ch-'A';
    }
    return ch-'a';
}

string alfa = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;


    ll t = 1;
    for(int c1 = 0; c1 < MAXN+1; c1++){
        FAC[c1] = t;
       // INV[c1] = upp(t,big-2);
        t *= c1+1;
        t %= big;
    }

    INV[MAXN] = upp(FAC[MAXN],big-2);
    for(int c1 = MAXN-1; c1 >= 0; c1--){
        INV[c1] = (INV[c1+1]*(c1+1))%big;
    }
//cerr << FAC[ss] << "\n";

    cin >> s;
    n = s.length();
    for(int c1 = 0; c1 < n; c1++){
        F[ctn(s[c1])]++;
    }

    SS[0] = 1;
    for(int c1 = 0; c1 < ss; c1++){
                if(F[c1] != 0){
                    vec.push_back(F[c1]);
                    add(F[c1]);
                }
            }

        ll STUFF = stuff();

    cin >> q;
    for(int c1 = 0; c1 < q; c1++){
        cin >> a >> b;
        a--;
        b--;
        ll x = ctn(s[a]);
        ll y = ctn(s[b]);
        if(x>y)swap(x,y);
        if(ANSC[x][y]){
            cout << ANS[x][y] << "\n";
            continue;
        }

        if(x != y){
            sub(F[x]);
            sub(F[y]);
            add(F[x]+F[y]);
        }

        ll res = SS[n/2];
      //  cerr << res << " " << STUFF << "\n";
        res *= STUFF;
        res %= big;

        ANSC[x][y] = 1;
        ANS[x][y] = res;
        if(x == y){
            for(int c1 = 0; c1 < ss; c1++){
                ANSC[c1][c1] = 1;
                ANS[c1][c1] = res;
            }
        }
        if(x != y){
            add(F[x]);
            add(F[y]);
            sub(F[x]+F[y]);
        }
        cout << res << "\n";
    }
    return 0;
}