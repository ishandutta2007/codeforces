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
const int N = 1e6 + 1, mod = 1e9 + 7;

int n, a[N], result = mod; str x;

void MAIN(){
    cin >> n >> x;
    x = " " + x;

    REP(i, n) cin >> a[i];
    REP(i, n - 1)
        if(x[i] == 'R' && x[i + 1] == 'L')
            if((a[i] + a[i + 1]) % 2 == 0)
                 result = min(result, (a[i + 1] - a[i]) / 2);
    cout << (result < mod ? result : -1);
}