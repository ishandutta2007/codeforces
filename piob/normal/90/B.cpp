#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
char T[110][110];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n) scanf("%s", &T[i]);
    FWD(i,0,n)
        FWD(j,0,m){
            int c = 0;
            FWD(k,0,m) if(T[i][j] == T[i][k]) ++c;
            FWD(k,0,n) if(T[i][j] == T[k][j]) ++c;
            if(c == 2) printf("%c", T[i][j]);
        }
    printf("\n");
    return 0;
}