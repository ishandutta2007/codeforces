#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
char T[110][110];

int main(){
    scanf("%d", &n);
    FWD(i,1,n+1)
        scanf("%s", T[i]+1);
    FWD(i,1,n+1)
        FWD(j,1,n+1)
            if((T[i-1][j]=='o')^(T[i+1][j]=='o')^(T[i][j-1]=='o')^(T[i][j+1]=='o')){
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}