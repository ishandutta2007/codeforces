#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, r;
int P[100010];
bool d2;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &P[i]);
        if(P[i] == i) ++r;
        if(P[i] < i && P[P[i]] == i) d2 = 1;
    }
    if(r == n) printf("%d\n", n);
    else if(d2) printf("%d\n", r+2);
    else printf("%d\n", r+1);
    return 0;
}