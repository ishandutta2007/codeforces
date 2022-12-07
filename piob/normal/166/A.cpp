#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k;
PII R[53];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,n){
        scanf("%d %d", &R[i].x, &R[i].y);
        R[i].x *= -1;
    }
    sort(R, R+n);
    int c = 0;
    FWD(i,0,n)
        if(R[i] == R[k-1])
            ++c;
    printf("%d\n", c);
    return 0;
}