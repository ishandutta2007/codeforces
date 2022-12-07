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

int n, m;

int main(){
    scanf("%d %d", &n, &m);
    int c0, c1, i0;
    c0 = i0 = 100;
    c1 = 0;
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        c0 = min(c0, a);
        c1 = max(c1, a);
    }
    FWD(i,0,m){
        int a;
        scanf("%d", &a);
        i0 = min(i0, a);
    }
    int t = max(2*c0, c1);
    printf("%d\n", i0<=t?-1:t);
    return 0;
}