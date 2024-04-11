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

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,q,T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    string s;
    cin >> s;

    for(int c1 = 1; c1 <= n; c1++){
        if(n%c1 == 0){
            string s2 = s;
            for(int c2 = 0; c2 < c1; c2++){
                s[c2] = s2[c1-c2-1];
            }
        }
    }

cout << s << "\n";
    return 0;
}