#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int D[100010];
int S[100010];

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1){
        scanf("%d", &D[i]);
        S[i] = S[i-1] + D[i];
    }
    int r = 1000000000;
    for(int d = 1; d < n && d * d < r; ++d){
        for(int i = 1; i + d <= n; ++i){
            r = min((LL)r, d*d + (LL)(S[i+d]-S[i]) * (S[i+d]-S[i]));
        }
    }
    printf("%d\n", r);
    return 0;
}