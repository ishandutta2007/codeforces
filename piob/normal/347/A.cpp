#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int T[110];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &T[i]);
    sort(T, T+n);
    swap(T[0], T[n-1]);
    FWD(i,0,n) printf("%d ", T[i]);
    printf("\n");
    return 0;
}