#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

const int MAXN = 100010;

int n;
int T[200010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &T[i]);
    int mi = *min_element(T, T+n);
    int ma = *max_element(T, T+n);
    if(mi == ma){printf("0 %I64d\n", (LL)n*(n-1)/2); return 0;}
    printf("%d %I64d\n", ma-mi, (LL)count(T, T+n, mi)*count(T, T+n, ma));
    return 0;
}