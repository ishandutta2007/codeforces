#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,T,k,q,p;

ll PEK[300001] = {0};
vector<ll> SL;
ll main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;
    scanf("%d" , &n);
    ll overs = 0;
    SL.push_back(500);
    ll ans = 0;
    ll currs = 0;
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d" , &a);
        if(a == 2){
            ans += overs;
            overs = 0;
        }
        if(a == 4){
            overs = 0;
        }
        if(a == 6){
            overs++;
        }
        if(a == 3){
            scanf("%d" , &b);
            SL.push_back(b);
            if(currs > b){
                ans++;
                PEK[sz(SL) - 1] = 1;
            }
        }
        if(a == 5){
            SL.push_back(500);
        }
        if(a == 1){
            scanf("%d" , &b);
            ll i = sz(SL) - 1;

            while(1){
                if(i < 0)break;
              //  cout << c1 << " " << i << "  gg\n";
                if(SL[i] < 0){
                    if(-SL[i] < b){
                        i = PEK[i];
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(SL[i] < b){
                        if(PEK[i] == 0){
                            ans++;
                            PEK[i] = 1;
                        }
                        i--;
                    }
                    else{
                        break;
                    }
                }
            }
            SL.push_back(-b);
            PEK[sz(SL) - 1] = i;
            currs = b;
        }
    }

    cout << ans << "\n";

    return 0;
}