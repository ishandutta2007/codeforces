#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
char M[310][310];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%s", M[i]);
    char a = M[0][0];
    char b = M[0][1];
    if(a == b){
        printf("NO\n");
        return 0;
    }
    FWD(i,0,n){
        if(M[i][i] != a || M[i][n-1-i] != a){
            printf("NO\n");
            return 0;
        }
    }
    FWD(i,0,n)
        FWD(j,0,n)
            if(i != j && i != n-1-j && M[i][j] != b){
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}