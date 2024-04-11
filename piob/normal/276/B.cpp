#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
char S[1010];
int C[256];

int main(){
    scanf("%s", S);
    n = strlen(S);
    FWD(i,0,n) ++C[S[i]];
    n = 0;
    FWD(c,'a','z'+1)
        if(C[c]&1)
            ++n;
    if(n==0 || (n&1))
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}