#include <bits/stdc++.h>
#define sz(X) ((int)(X).size() - 1)
#define all(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 1; I <= (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
#define FOR(I, A, B) for(int I = (A); I >= (B) ; --I)
#define mp make_pair
#define pb push_back
#define ms(A, X) memset((A), (X), sizeof(A))
#define LEN(X) (int)strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
#define str string
#define lt2(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define lb lower_bound
#define ub upper_bound
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("test.inp","r",stdin);
      //  freopen("test.out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const int N = 1e5 + 1, mod = 1e9 + 7;

int f(char c){
    if(c < 'a') return c - 'A';
    return c - 'a' + 26;
}

str a; int n, dp[N][53], lastpos[53], result = mod;
vector < int > cur;

void MAIN(){
    cin >> n >> a;
    a = " " + a;

    REP(i, n){
        int x = f(a[i]);
        if(!lastpos[x]){
            lastpos[x] = 1;
            cur.pb(x);
        }
    }

    //ms(lastpos, 1);

    REP(i, n){
         REPP(k, 0, 51) dp[i][k] = dp[i - 1][k];
         int x = f(a[i]);
         dp[i][x]++;
         lastpos[x] = i;
         int maximize = mod;
         REPP(k, 0, sz(cur)){
             int y = cur[k];
             if(dp[i][y] < 1) {
                maximize = -1;
                break;
             }
             //if(i == 6) cout << lastpos[y] << endl;
             maximize = min(maximize, lastpos[y]);
         }
        // cout << maximize << endl;
         if(maximize != -1) result = min(result, i - maximize + 1);
         lastpos[x] = i;
    }
    cout << result;
}