#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, p, s, x, y;
int S[110];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &S[i]);
        s += S[i];
    }
    scanf("%d %d", &x, &y);
    FWD(i,0,n){
        p += S[i];
        if(x <= p && p <= y && x <= s-p && s-p <= y){
            printf("%d\n", i+2);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}