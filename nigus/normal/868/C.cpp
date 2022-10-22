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
int n,m,k,q,w,h,T;

vector<vector<ll> > C(100001, vector<ll>());

ll masks[16] = {0};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d", &n);
    scanf("%d", &k);


    for(ll c1 = 0;  c1 < n;  c1++){

        ll t = 0;
        for(ll c2 = 0; c2 < k; c2++){
            scanf("%d" , &a);
            t += a*(1 << c2);
        }
        masks[t]++;
    }
    string ans = "NO";
    for(ll c1 = 1; c1 < (1 << 16); c1++){
        bool fail = 0;
        ll F[4] = {0};
        a = 0;
        for(ll c2 = 0; c2 < 16; c2++){
            if((c1&(1 << c2)) != 0){
                a++;
                if(masks[c2] == 0){
                    fail = 1;
                    break;
                }
                else{
                    for(ll c3 = 0; c3 < 4; c3++){
                        F[c3] += ((c2&(1 << c3)) != 0);
                    }
                }
            }
        }

        if(fail)continue;

        for(ll c2 = 0; c2 < 4; c2++){
            if(2*F[c2] > a)fail = 1;
        }
        if(!fail)ans = "YES";
    }

    cout << ans << "\n";

    return 0;
}