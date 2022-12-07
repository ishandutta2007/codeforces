#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, i, a;

int main(){
    while(scanf("%d", &a) == 1){
        n += i*a;
        ++i;
    }
    printf("%d\n", n);
    return 0;
}