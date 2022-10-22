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

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q;


ll FT[26] = {0};
ll FS[26] = {0};
string s,t;
vector<ll> I;

string alfa = "abcdefghijklmnopqrstuvwxyz";

ll ctn(char ch){
    return ll(ch)-ll('a');
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> s >> t;
    n = s.length();
    m = t.length();
    q = 0;

    for(ll c1 = 0; c1 < m; c1++){
        FT[ctn(t[c1])]++;
    }

    for(ll c1 = 0; c1 < n; c1++){
        if(s[c1] != '?'){
            FS[ctn(s[c1])]++;
        }
        else{
            I.push_back(c1);
            q++;
        }
    }

    for(ll c1 = 0; c1 < q; c1++){
        ll mi = big;
        ll i = 0;
        for(ll c2 = 0; c2 < 26; c2++){

            if(FT[c2] != 0){
                ll f = FS[c2]/FT[c2];
                if(f < mi){
                    mi = f;
                    i = c2;
                }
            }
        }

        s[I[c1]] = alfa[i];
        FS[i]++;
    }
    cout << s;
    return 0;
}