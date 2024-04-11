#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m, p;
char A[33];
char B[33];

int main(){
    scanf("%s%s", A, B);
    n = strlen(A);
    m = strlen(B);
    if((n+m-1)&1){
        printf("Impossible\n");
        return 0;
    }
    FWD(i,0,n) if(A[i] == '|') p = i;
    int x = p;
    int y = n-1-p;
    if(x + m < y || y + m < x){
        printf("Impossible\n");
        return 0;
    }
    int c = (y+m-x)/2;
    FWD(i,0,c) printf("%c", B[i]);
    printf("%s", A);
    FWD(i,c,m) printf("%c", B[i]);
    printf("\n");
    return 0;
}