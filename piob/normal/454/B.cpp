#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int T[100010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &T[i]);
    int v = *min_element(T, T+n);
    int p = 0;
    while(p < n && T[p] == v) ++p;
    if(p == n)
        printf("0\n");
    else{
        p = min_element(T+p, T+n) - T;
        int c = 0;
        if(T[p] == v){
            c = n-p;
            rotate(T, T+p, T+n);
        }
        FWD(i,0,n-1) if(T[i] > T[i+1]){ printf("-1\n"); return 0; }
        printf("%d\n", c);
    }
    return 0;
}