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

bool added[100008] = {0};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d,e;

    cin >> n;
    ll inside = 0;
    ll ans = -2;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;

        if(a < 100008){

            while(inside < a){
                if(added[inside] == 0){
                    ans = c1;
                    break;
                }
                inside++;
            }
            if(ans != -2)break;
            added[a] = 1;
        }
        else{
            ans = c1;
            break;
        }
    }
    cout << ans+1 << "\n";


    return 0;
}