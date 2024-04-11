#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, d, m, r;
int A[110];

int main(){
    scanf("%d %d", &n, &d);
    FWD(i,0,n){
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    sort(A, A+n);
    FWD(i,0,min(n,m)) r += A[i];
    r -= max(0, (m-n)*d);
    printf("%d\n", r);
    return 0;
}