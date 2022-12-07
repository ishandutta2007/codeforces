#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, r, p;
char S[5010];

int main(){
    scanf("%s", S);
    n = strlen(S);
    p = -1;
    FWD(i,3,n){
        if(S[i-3] == 'b' && S[i-2] == 'e' && S[i-1] == 'a' && S[i] == 'r')
            p = i-3;
        r += p+1;
    }
    printf("%d\n", r);
    return 0;
}