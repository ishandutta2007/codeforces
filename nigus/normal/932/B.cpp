#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
int n,m,k,T,q;


int DP[1000001] = {0};
int CS[1000001][10] = {0};

ll prod(ll i){
    ll ans = 1;
    ll i2 = i;
    while(i2 > 0){
        if(i2%10 != 0)ans *= (i2%10);
        i2 /= 10;
    }
    return ans;
}

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d;



    for(int c1 = 0; c1 < 1000001; c1++){
        if(c1 < 10){
            DP[c1] = c1;
        }
        else{
            DP[c1] = DP[prod(c1)];
        }
        a = DP[c1];
        for(int c2 = 0; c2 < 10; c2++){
            CS[c1+1][c2] = CS[c1][c2];
        }
        CS[c1+1][a]++;
    }
    scanf("%d" , &q);
    for(int c1 = 0; c1 < q; c1++){
        scanf("%d" , &a);
        scanf("%d" , &b);
        scanf("%d" , &c);
        int ans = CS[b+1][c]-CS[a][c];
        printf("%d\n" , ans);
    }


    return 0;
}