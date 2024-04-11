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
int n,m,k,q,w,h,x;

ll DP[100001][3][11] = {0};
ll DP2[100001][11] = {0};

ll DP3[100001][3][11] = {0};

vector<vector<ll> > C(100001, vector<ll>());
//vector<vector<ll> > A(100001, vector<ll>());

ll A[100001][11] = {0};

ll lk,gk;

vector<ll> B;

vector<vector<vector<ll> > > AAA;
bool finns[400005] = {0};

ll limn = 0;
ll limk = 0;

ll mod(ll i){
if(i < big)return i;
return i%big;
}

ll dp2(ll i, ll k2){
    if(k2 >= limk)return 0;
    if(i == limn)return (k2 == limk-1);

    //if(i >= limn || i < 0 || k2 >= limk || k2 < 0)cout << "hjk";

    if(DP2[i][k2] != -1)return DP2[i][k2];
    ll ans = 0;
    for(ll c1 = 0; c1 < limk-k2; c1++){
        ans += mod(A[i][c1]*dp2(i+1,k2+c1));
        ans = mod(ans);
    }
    DP2[i][k2] = ans;
    return ans;
}

ll dp(ll i, ll last, ll xleft, ll par){

    //if(i >= n || i < 0 || last >= 3 || last < 0 || xleft > x || xleft < 0)cout << i << " " << last << " " << xleft << " " << "\n";

    if(DP[i][last][xleft] != -1)return DP[i][last][xleft];

    ll ans = 0;

    for(ll c1 = 0; c1 < 3; c1++){
        if((last == 1 && c1 != 0) || (last == 2 && c1 == 1) || (xleft == 0 && c1 == 1))continue;

        if(DP3[i][c1][xleft-(c1==1)] != -1){ans += DP3[i][c1][xleft-(c1==1)];ans = mod(ans); continue;}
        ll inc = 0;


        if(!finns[3*i+c1]){
            for(ll c2 = 0; c2 < sz(C[i]); c2++){
                ll a = C[i][c2];
                if(a != par){
                    vector<ll> temp;
                    for(ll c3 = 0; c3 <= x; c3++){
                        temp.push_back(dp(a,c1,c3,i));
                    }
                    AAA[3*i+c1].push_back(temp);
                }
            }
            finns[3*i+c1] = 1;
        }
        if(sz(AAA[3*i+c1]) == 0){
            inc = B[c1] * ((xleft-(c1 == 1) == 0));
        }
        else{
            for(ll c2 = 0; c2 < sz(AAA[3*i+c1]); c2++){
                for(ll c3 = 0; c3 < sz(AAA[3*i+c1][c2]); c3++){
                    A[c2][c3] = AAA[3*i+c1][c2][c3];
                    DP2[c2][c3] = -1;
                }
            }
            limn = sz(AAA[3*i+c1]);
            limk = xleft-(c1==1)+1;

           // if(i == 0)cout << "c1: " << c1 <<  "      xleft: " << xleft << "\n";
/*
            if(i == 0){
                for(ll c2 = 0; c2 < limn; c2++){
                    for(ll c3 = 0; c3 < limk; c3++){
                        cout << A[c2][c3] << " ";
                    }cout << "\n";
                }cout << "\n\n";
            }
*/

            inc =  B[c1]*dp2(0,0);

       //     if(i == 0)cout << "ans: " << ans << "\n";

        }
        ans += inc;
        ans = mod(ans);
        DP3[i][c1][xleft-(c1==1)] = mod(inc);
    }


   // cout << i+1 << " last: " << last << "  xleft: " << xleft << "     ans: " << ans << "\n";

    DP[i][last][xleft] = ans;
    return ans;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;

    scanf("%d", &n);
    scanf("%d", &m);
    for(ll c1 = 0; c1 < n-1; c1++){
        scanf("%d", &a);
        scanf("%d", &b);
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = 0; c2 < 3; c2++){
            vector<vector<ll> > temp;
            AAA.push_back(temp);
            for(ll c3 = 0; c3 < 11; c3++){
                DP[c1][c2][c3] = -1;
                DP3[c1][c2][c3] = -1;
            }
        }
    }
    scanf("%d", &a);
    scanf("%d", &b);
    k = ll(a);
    x = ll(b);
    lk = k-1;
    gk = m-k;
    B.push_back(lk);
    B.push_back(1);
    B.push_back(gk);
    ll ans = 0;

    for(ll c1 = 0; c1 < x+1; c1++){
        ans += dp(0,0,c1,-1);
    }
    cout << ans%big << "\n";

    return 0;
}