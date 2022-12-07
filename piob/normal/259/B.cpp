#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b, c;
int M[3][3];

int main(){
    FWD(i,0,3)
        FWD(j,0,3)
            scanf("%d", &M[i][j]);
    FWD(j,0,3) a += M[0][j], b += M[1][j], c += M[2][j];
    int x = (b+c-a)/2;
    int y = (a+c-b)/2;
    int z = (a+b-c)/2;
    FWD(j,0,3){
        if(M[0][j] == 0) M[0][j] = x;
        if(M[1][j] == 0) M[1][j] = y;
        if(M[2][j] == 0) M[2][j] = z;
    }
    FWD(i,0,3){
        FWD(j,0,3) printf("%d ", M[i][j]);
        printf("\n");
    }
    return 0;
}