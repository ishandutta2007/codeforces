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

int n, k;
int T[2010];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,n) scanf("%d", &T[i]);
    sort(T, T+n);
    int c = 2;
    while(c < n && T[c] + k <= 5){
        c += 3;
    }
    printf("%d\n", c / 3);
    return 0;
}