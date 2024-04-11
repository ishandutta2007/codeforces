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

int n, sa, sb, k;

int main(){
    scanf("%d", &n);
    k = -1;
    FWD(i,0,n){
        int a, b;
        scanf("%d %d", &a, &b);
        sa += a;
        sb += b;
        if((a&1)!=(b&1)) k = i;
    }
    if((sa+sb)&1)
        printf("-1\n");
    else{
        if((sa&1)&&(k==-1))
            printf("-1\n");
        else{
            printf("%d\n", (sa&1));
        }
    }
    return 0;
}