#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

typedef long long LL;

int n, m, d, t, x, y, k;
int A[100010];
int B[100010];
int X[100010];
int Y[100010];
int K[100010];
int D[270000];

void setw(int a, int b, int c){
    a += d;
    b += d;
    while(a < b){
        if(a&1){
            D[a] = c;
            ++a;
        }
        if((b&1)==0){
            D[b] = c;
            --b;
        }
        a /= 2;
        b /= 2;
    }
    if(a == b)
        D[a] = c;
}

int get(int a){
    a += d;
    int r = -1;
    while(a > 0){
        r = max(r, D[a]);
        a /= 2;
    }
    return r;
}

int main(){
    scanf("%d %d", &n, &m);
    d = 1;
    while(d < n) d*=2;
    FWD(i,1,2*d+1) D[i] = -1;
    FWD(i,0,n) scanf("%d", &A[i]);
    FWD(i,0,n) scanf("%d", &B[i]);
    FWD(i,0,m){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d %d", &x, &y, &k);
            --x;
            --y;
            X[i] = x;
            Y[i] = y;
            K[i] = k;
            setw(y,y+k-1,i);
        }else{
            scanf("%d", &x);
            --x;
            y = get(x);
            if(y == -1)
                printf("%d\n", B[x]);
            else{
                printf("%d\n", A[x-Y[y]+X[y]]);
            }
        }
    }
    return 0;
}