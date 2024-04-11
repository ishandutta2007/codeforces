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
ll n,m,k,q,h,T;

ll last[200001] = {0};
ll ANS[200001] = {0};
vector<ll> A;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    ll ans = 0;
    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
    }

    ans = 1;
    last[0] = 0;

    for(ll c1 = 0; c1 < n; c1++){
        a = A[c1];
        b = ANS[a];
        if(last[b] == a){
            last[b] = c1+1;
            ANS[c1+1] = b;
        }
        else{
            ANS[c1+1] = ans;
            last[ans] = c1+1;
            ans++;
        }

    }
    /*
    for(ll c1 = 0; c1 < n+1; c1++){
        cout << ANS[c1]+1 << " ";
    }
    cout << "\n";
    */
    cout << ans << "\n";

    return 0;
}