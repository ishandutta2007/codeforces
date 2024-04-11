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
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T,q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c;

   cin >> n;
   string s;
   cin >> s;
   if(n == 1){
        cout << "Yes\n";
        return 0;
   }
   ll F[26] = {0};
   string ans = "No\n";
   for(int c1 = 0; c1 < n; c1++){
        F[s[c1]-'a']++;
        if(F[s[c1]-'a'] == 2){
            ans = "Yes\n";
        }
   }
   cout << ans << "\n";

    return 0;
}