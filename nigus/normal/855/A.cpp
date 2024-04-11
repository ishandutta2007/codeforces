#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    vector<string> A;
    for(ll c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;

        string ans = "NO\n";
        for(ll c2 = 0; c2 < c1; c2++){
            if(A[c2] == s)ans = "YES\n";
        }
        A.push_back(s);
        cout << ans;

    }

    return 0;
}