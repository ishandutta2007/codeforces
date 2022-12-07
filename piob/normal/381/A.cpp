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
int T[1010];
int R[2];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        scanf("%d", &T[i]);
    int p = 0;
    int k = n-1;
    int r = 0;
    while(p<=k){
        R[r] += T[p]>=T[k]?T[p++]:T[k--];
        r = 1 - r;
    }
    printf("%d %d\n", R[0], R[1]);
    return 0;
}