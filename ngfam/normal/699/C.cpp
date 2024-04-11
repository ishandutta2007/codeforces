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
const int N = 1e3 + 1, mod = 1e9 + 7;

int n, m, a[N], dp[N][3];

void MAIN(){
    cin >> n;
    REP(i, n) cin >> a[i], dp[i][1] = dp[i][0] = dp[i][2] = n;

    dp[1][0] = 1;
    if(a[1] == 1 || a[1] == 3) dp[1][1] = 0;
    if(a[1] == 2 || a[1] == 3) dp[1][2] = 0;
    REPP(i, 2, n){
        if(a[i] == 0)
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        if(a[i] == 1){
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if(a[i] == 2){
            dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        if(a[i] == 3){
             dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}