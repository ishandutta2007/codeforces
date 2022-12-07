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

int n, a, b, c;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &c);
        ++(c==5?a:b);
    }
    if(!b)
        printf("-1\n");
    else{
        if(a < 9){
            if(b)
                printf("0\n");
            else
                printf("-1\n");
        }else{
            a -= a % 9;
            FWD(i,0,a)
                printf("5");
            FWD(i,0,b)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}