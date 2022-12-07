#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, r;
char N[100010];

int main(){
    scanf("%s", N);
    n = strlen(N);
    FWD(i,0,n){
        r = (10*r + N[i]-'0') % 4;
    }
    printf("%d\n", r==0?4:0);
    return 0;
}