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

ll M[51][51] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < n; c2++){
            cin >> a;
            M[c1][c2] = a;
        }
    }

    bool yes = 1;

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < n; c2++){

            bool fail = 1;
            if(M[c1][c2] != 1){
                for(ll c3 = 0; c3 < n; c3++){
                    for(ll c4 = 0; c4 < n; c4++){
                        if(M[c1][c2] == M[c1][c3]+M[c4][c2])fail=0;
                    }
                }
                if(fail)yes = 0;
            }
        }
    }

    if(yes){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}