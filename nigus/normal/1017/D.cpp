#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;


const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

int ANS[5000][101] = {0};
bool ANSC[10000] = {0};

vi W;

int F[10000] = {0};

void solve(int i){
    for(int c1 = 0; c1 < (1 << n); c1++){
        if(F[c1] == 0)continue;
        int sum = 0;
        for(int c2 = 0; c2 < n; c2++){
            int bit1 = ((i & (1 << c2)) != 0);
            int bit2 = ((c1 & (1 << c2)) != 0);
            if(bit1 == bit2){
                sum += W[c2];
            }
        }
        if(sum <= 100){
            ANS[i][sum]+=F[c1];
        }
    }
    for(int c1 = 1; c1 <= 100; c1++){
        ANS[i][c1] += ANS[i][c1-1];
    }
    ANSC[i] = 1;
    return;
}

int has(string s){
    int ans = 0;
    for(int c1 = n-1; c1 >= 0; c1--){
        ans *= 2;
        ans += s[c1]-'0';
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    cin >> n >> m >> q;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        W.push_back(a);
    }
    for(int c1 = 0; c1 < m; c1++){
        string s;
        cin >> s;
        F[has(s)]++;
    }

    for(int c1 = 0; c1 < q; c1++){
        string s;
        cin >> s >> k;
        a = has(s);
        if(!ANSC[a])solve(a);
        cout << ANS[a][k] << "\n";
    }

    return 0;
}