#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, s, a, m;

int main(){
    scanf("%d %d", &n, &s);
    FWD(i,0,n){
        scanf("%d", &a);
        s -= a;
        m = max(a, m);
    }
    if(s+m >= 0) printf("YES\n"); else printf("NO\n");
    return 0;
}