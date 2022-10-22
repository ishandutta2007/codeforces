#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,T;

bool mark[1000001] = {0};

const ll lim = 1001;


ll DP[lim] = {0};
bool DPC[lim] = {0};

ll dp(ll i){
    if(i == 0)return 0;
    if(DPC[i])return DP[i];
    ll ans = -1;
    for(ll c1 = 4; c1 <= i; c1++){
        if(mark[c1]){
            ans = max(ans, 1+dp(i-c1));
        }
    }
    if(ans == 0)ans = -1;
    DP[i] = ans;
    DPC[i] = 1;
    return ans;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    for(ll c1 = 2; c1 < 1000001; c1++){
        if(!mark[c1]){
            for(ll c2 = c1*c1; c2 < 1000001; c2 += c1){
                mark[c2] = 1;
            }
        }
    }

    cin >> n;

    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        if(a < lim){
            cout << dp(a) << "\n";
        }
        else{

            ll t = (a-lim)/4 + 4;
            b = a-4*t;
            cout << t+dp(b) << "\n";

        }
    }


    return 0;
}