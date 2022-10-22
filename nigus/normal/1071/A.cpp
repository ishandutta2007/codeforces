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

vi ANS1,ANS2;

bool mark[4000000] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> a >> b;

    ll sum = 0;

    for(int c1 = 1; c1 < 100000000; c1++){
        sum += c1;
        if(sum > a+b){
            sum -= c1;
            k = c1-1;
            break;
        }
    }


    for(int c1 = k; c1 >= 1; c1--){
        if(c1 <= a){
            ANS1.push_back(c1);
            a -= c1;
            mark[c1] = 1;
        }
    }
    for(int c1 = 1; c1 <= k; c1++){
        if(!mark[c1])ANS2.push_back(c1);
    }

    cout << sz(ANS1) << "\n";
    for(int c1 = 0; c1 < sz(ANS1); c1++){
        cout << ANS1[c1] << " ";
    }cout << "\n";

    cout << sz(ANS2) << "\n";
    for(int c1 = 0; c1 < sz(ANS2); c1++){
        cout << ANS2[c1] << " ";
    }cout << "\n";

    return 0;
}