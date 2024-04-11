#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
int S[100010];
LL res;

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n) scanf("%d", &S[i]);
    sort(S, S+n);
    FWD(i,0,n){
        res += (LL)S[i] * m;
        m = max(1, m-1);
    }
    cout << res << endl;
    return 0;
}