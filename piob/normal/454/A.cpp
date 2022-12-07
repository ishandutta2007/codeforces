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
typedef double K;
typedef vector<int> VI;

const int MAXN = 100010;

int main(){
    int n;
    scanf("%d", &n);
    FWD(i,0,n/2){
        FWD(j,0,n/2-i) printf("*");
        FWD(j,0,2*i+1) printf("D");
        FWD(j,0,n/2-i) printf("*");
        printf("\n");
    }
    FWD(i,0,n) printf("D"); printf("\n");
    BCK(i,n/2-1,-1){
        FWD(j,0,n/2-i) printf("*");
        FWD(j,0,2*i+1) printf("D");
        FWD(j,0,n/2-i) printf("*");
        printf("\n");
    }
    return 0;
}