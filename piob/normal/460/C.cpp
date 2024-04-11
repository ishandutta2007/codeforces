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

int n, m, w;
int A[100010];
int B[100010];

bool check(int h){
    int d = 0;
    int c = 0;
    FWD(i,0,n) B[i] = 0;
    FWD(i,0,n){
        d += B[i];
        if(A[i] + d < h){
            int r = h-A[i]-d;
            c += r;
            d += r;
            if(c > m) break;
            if(i+w<n) B[i+w] -= r;
        }
    }
    return c <= m;
}

int main(){
    scanf("%d %d %d", &n, &m, &w);
    FWD(i,0,n) scanf("%d", &A[i]);
    int p = 0;
    int k = (1e9) + (1e5) + 3;
    while(k-p>1){
        if(check((p+k)/2))
            p = (p+k)/2;
        else
            k = (p+k)/2;
    }
    printf("%d\n", p);
    return 0;
}