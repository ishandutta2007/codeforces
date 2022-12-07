#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, a, b, c;
int S[4010];

int main(){
    scanf("%d %d %d %d", &n, &a, &b, &c);
    FWD(i,1,n+1){
        S[i] = -1e9;
        if(i >= a) S[i] = max(S[i], S[i-a]+1);
        if(i >= b) S[i] = max(S[i], S[i-b]+1);
        if(i >= c) S[i] = max(S[i], S[i-c]+1);
    }
    printf("%d\n", S[n]);
    return 0;
}