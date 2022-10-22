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

ll n,m,T,k,d;
const ll big = 1000000007;

vl A;

vector<vl> C(100001,vl());

ll F[100001] = {0};
ll ANS[100001] = {0};

int main() {
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;
    cin >> n;
    b = 1;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        a = n-a;
        C[a].push_back(c1);
    }
    bool fail = 0;
    b = 0;
    for(int c1 = 1; c1 <= n; c1++){
        if(sz(C[c1])%c1 == 0){
            for(int c2 = 0; c2 < sz(C[c1]); c2++){
                if(c2%c1 == 0)b++;
                ANS[C[c1][c2]]=b;
                if(b > n)fail = 1;
            }
        }
        else{
            fail = 1;
        }
    }
    if(fail){
        cout << "Impossible\n";
    }
    else{
        cout << "Possible\n";
        for(int c1 = 0; c1 < n; c1++){
            cout << ANS[c1] << " ";
        }
    }
    return 0;
}