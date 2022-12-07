#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, a;
int c[8];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        ++c[a];
    }
    int s3 = min(c[1], min(c[3], c[6]));
    c[1] -= s3;
    c[3] -= s3;
    c[6] -= s3;
    int s4 = min(c[1], min(c[2], c[4]));
    c[1] -= s4;
    c[2] -= s4;
    c[4] -= s4;
    int s6 = min(c[1], min(c[2], c[6]));
    c[1] -= s6;
    c[2] -= s6;
    c[6] -= s6;
    FWD(i,1,8)
        if(c[i]){
            printf("-1\n");
            return 0;
        }
    FWD(i,0,s3) printf("1 3 6\n");
    FWD(i,0,s4) printf("1 2 4\n");
    FWD(i,0,s6) printf("1 2 6\n");
    return 0;
}