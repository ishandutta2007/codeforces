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

ll M[101][101] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m >> k;
    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < m; c2++){
            cin >> a;
            M[c1][c2] = a;
        }
    }

    ll a1 = 0;
    ll a2 = 0;

    for(ll c1 = 0; c1 < m; c1++){
        ll b1 = 0;
        ll b2 = 0;
        ll o = 0;
        for(ll c2 = 0; c2 < n; c2++){
            if(M[c2][c1] == 1){
                ll b3 = 0;
                for(ll c3 = 0; c3 < k; c3++){
                    ll c4 = c2+c3;
                    if(c4 >= n)break;
                    b3 += M[c4][c1];
                }

                if(b3 > b1){
                    b1 = b3;
                    b2 = o;
                }

                o++;
            }
        }
        a1 += b1;
        a2 += b2;
    }

    cout << a1 << " " << a2 << "\n";


    return 0;
}