#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int c[3];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        ++c[a-1];
    }
    printf("%d\n", n-*max_element(c, c+3));
    return 0;
}