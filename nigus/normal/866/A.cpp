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

int const pmax = 8;
int DP[2000001][pmax] = {0};
bool DPB[2000001][pmax] = {0};

int I[1000001] = {0};
int B[1000001] = {0};

int dp(ll i, ll t){
    if(i == 0)return 1;
   // cout << i << " " << t << "\n";
  // if(i < 0 || t < 0 || i > 1000000 || t > 15)cout << i;
    if(DPB[i][t] != 0)return DP[i][t];

    int ans = 0;
    for(ll c1 = t; c1 >= 0; c1--){
        if(i-(1<<c1) >= 0){
            ans += dp(i-(1<<c1),c1);
            if(ans > 10000000)ans = 10000000;
        }
    }
    if(ans > 10000000 || ans < 0)ans = 10000000;
    DPB[i][t] = 1;
    DP[i][t] = ans;
   // if(DP[i][t] < 0)cout << "!! " << DP[i][t]
    return ans;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;


    ll TWO[23] = {0};
    b = 1;
    for(ll c1 = 0; c1 < 23; c1++){
        TWO[c1] = b;
        b*= 2;
    }

    for(int c1 = 0; c1 < 2000001; c1++){
        for(ll c2 = 0; c2 < pmax; c2++){
            if(c1 == 0){
                DP[c1][c2] = 1;
            }
            else{
                a = 0;
                for(int c3 = 0; c3 <= c2; c3++){
                    if(c1 >= TWO[c3]){
                        a += DP[c1-TWO[c3]][c3];
                       // if(a < 0)cout << c1-TWO[c3] << " " << c3 << "\n";
                    }
                }
                if(a > 100000000)a = 100000000;
                DP[c1][c2] = a;
            }
        }
    }

    for(ll c1 = 1; c1 < 2000001; c1++){
        for(ll c2 = 0; c2 < pmax; c2++){
            //a = dp(c1,c2);
            a = DP[c1][c2];
            if(a < 1000001 && c1 <= 1000000){
                //if(a < 0)cout << c1 << "  " << c2;
                I[a] = c1;
                B[a] = c2;
            }
        }
    }

    cin >> n;

    cout << I[n] << " " << B[n]+1 << "\n";
    for(ll c1 = 0;  c1 < B[n]+1; c1++){
        cout << TWO[c1] << " ";
    }


    return 0;
}