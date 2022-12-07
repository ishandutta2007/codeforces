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

int n, t, c, d;

int main(){
    scanf("%d %d", &n, &d);
    FWD(i,0,n){
        if(i){
            c += 2;
            t += 10;
        }
        int a;
        scanf("%d", &a);
        t += a;
    }
    while(t + 5 <= d){
        t += 5;
        ++c;
    }
    if(t > d)
        printf("-1\n");
    else
        printf("%d\n", c);
    return 0;
}