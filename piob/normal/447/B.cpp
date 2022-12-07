#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k, r;
int c[257];
char S[1030];

int main(){
    scanf("%s", S);
    scanf("%d", &k);
    FWD(i,'a','z'+1) scanf("%d", &c[i]);
    n = strlen(S);
    FWD(i,0,n) r += (i+1)*c[S[i]];
    FWD(i,n,n+k) r += (i+1)*((*max_element(c+'a', c+'z'+1)));
    printf("%d\n", r);
    return 0;
}