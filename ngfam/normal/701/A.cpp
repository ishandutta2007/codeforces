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
const int N = 1e2 + 1, mod = 1e9 + 7;

int n, a[N], cnt[2 * N], done[2 * N];

void MAIN(){
    cin >> n;
    REP(i, n) cin >> a[i];

    int sum = 0;
    REP(i, n) sum += a[i];
    int each = sum / (n / 2);

    REP(i, n) if(!done[i])
       REPP(j, i + 1, n)
           if(!done[j] && a[i] + a[j] == each){
                cout << i << " " << j << endl;
                done[j] = 1;
                break;
           }
}