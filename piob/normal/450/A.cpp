#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m, p;
int A[110];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n){
        scanf("%d", &A[i]);
        A[i] = (A[i] + m - 1) / m;
        if(A[i] >= A[p]) p = i;
    }
    printf("%d\n", p+1);
    return 0;
}