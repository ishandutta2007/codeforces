#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int k;
char M[5][7];
int C[256];

int main(){
    scanf("%d", &k);
    FWD(i,0,5){
        scanf("%s", &M[i]);
        FWD(j,0,5)
            C[M[i][j]]++;
    }
    FWD(i,'1','9'+1)
        if(C[i] > 2*k){
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}