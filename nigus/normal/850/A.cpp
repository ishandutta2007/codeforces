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
ll n,m,k,q,w,h,x;

ll lim = 200;

vector<vector<ll> > A(1001,vector<ll>());

ll sp(vector<ll> P, vector<ll> Q){
    ll ans = 0;
    for(ll c1 = 0; c1 < 5; c1++){
        ans += P[c1]*Q[c1];
    }
    return ans;
}

bool acute(vector<ll> P, vector<ll> Q){

    ll a = sp(P,Q);
    if(a == 0)return 0;
    ld den = sqrt(sp(P,P) * sp(Q,Q));
    ld res = acos(ld(a)/den);
    ld pi = acos(-1);
    if(res < pi)return 1;
    return 0;

}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n;

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < 5; c2++){
            cin >> a;
            A[c1].push_back(a);
        }
    }

    vector<ll> Good;

    if(n >= lim){
        cout << "0\n";
    }
    else{

        for(ll c1 = 0; c1 < n; c1++){
            bool good = 1;
            for(ll c2 = 0; c2 < n; c2++){
                for(ll c3 = c2+1; c3 < n; c3++){
                    if(c1 != c2 && c1 != c3){

                        vector<ll> P;
                        vector<ll> Q;
                        for(ll c4 = 0; c4 < 5; c4++){
                            P.push_back(A[c2][c4] - A[c1][c4]);
                            Q.push_back(A[c3][c4] - A[c1][c4]);
                        }
                        if(acute(P,Q))good = 0;

                    }
                }
            }
            if(good){
                Good.push_back(c1);
            }
        }

        cout << sz(Good) << "\n";
        for(ll c1 = 0; c1 < sz(Good); c1++){
            cout << Good[c1]+1 << "\n";
        }

    }


    return 0;
}