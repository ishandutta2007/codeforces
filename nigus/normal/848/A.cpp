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
ll n,m,T,k,q,p;

vector<ll> TRI;
unordered_map<ll,ll> M;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    TRI.push_back(0);
    for(ll c1 = 0; c1 < 505; c1++){
        TRI.push_back(TRI[c1]+c1+1);
        if(TRI[c1+1]+c1+2 > 100000)break;
    }

    for(ll c1 = 0; c1 < sz(TRI); c1++){
        M[TRI[c1]] = c1;
    }

    cin >> k;
    vector<ll> F;

    a = 0;
    b = 0;
    c = 0;
    q = 0;
    while(k >= 0){
        for(ll c1 = 0; c1 < sz(TRI); c1++){
            if(TRI[c1] > k)break;
            c = c1;
        }
        k -= TRI[c];
        F.push_back(c+1);
        q++;
        if(k == 0)break;
    }
    string alfa = "abcdefghijklmnopqrstuvwxyz";
    for(ll c1 = 0; c1 < sz(F); c1++){
        for(ll c2 = 0; c2 < F[c1]; c2++){
            cout << alfa[c1];
        }
    }

    return 0;
}