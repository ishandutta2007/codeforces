#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k;
int S[110];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,k){
        int a;
        scanf("%d", &a);
        FWD(j,a,n+1)
            if(S[j]) break; else S[j] = a;
    }
    FWD(i,1,n+1) printf("%d ", S[i]);
    printf("\n");
    return 0;
}