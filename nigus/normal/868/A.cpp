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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    vector<string> ss;
    string s;
    string s2;
    cin >> s >> n;
    string ans = "NO";
    for(ll c1 = 0; c1 < n; c1++){
        cin >> s2;
        ss.push_back(s2);
        for(ll c2 = 0; c2 <= c1; c2++){
            //cout << s2[0] << " " << ss[c2][0] << "  -  " << s[0] << " " << s[1] << "\n";
            if(ss[c2][0] == s[1] && s2[1] == s[0])ans = "YES";
            if(ss[c2][1] == s[0] && s2[0] == s[1])ans = "YES";
            if(s2 == s)ans = "YES";
        }
    }
    cout << ans << "\n";
    return 0;
}