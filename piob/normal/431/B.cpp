#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int c, r;
int M[5][5];
int P[] = {0,1,2,3,4};

int main(){
    FWD(i,0,5)
        FWD(j,0,5)
            scanf("%d", &M[i][j]);
    do{
        c = 0;
        FWD(i,0,5)
            for(int j=i; j+1<5; j+=2)
                c += M[P[j]][P[j+1]] + M[P[j+1]][P[j]];
        r = max(r, c);
    }while(next_permutation(P, P+5));
    printf("%d\n", r);
    return 0;
}