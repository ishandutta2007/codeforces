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
char C[100010];

int main(){
    scanf("%s", C);
    n = strlen(C);
    FWD(i,0,n)
        if(C[i] == '0'){
            C[i] = 0;
            printf("%s%s\n", C, C+i+1);
            return 0;
        }
    C[n-1] = 0;
    printf("%s\n", C);
    return 0;
}