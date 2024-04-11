#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, a;
int c[210];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &a);
        ++c[a];
    }
    if((c[100]&1) || ((c[200]&1) && c[100] < 2))
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}