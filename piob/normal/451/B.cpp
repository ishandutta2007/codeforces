#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, p, k;
int T[100010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        scanf("%d", &T[i]);
    }
    p = -1;
    k = -1;
    FWD(i,0,n-1)
        if(T[i] > T[i+1]){p = i; break;}
    FWD(i,p,n-1)
        if(T[i] < T[i+1]){k = i; break;}
    if(p == -1) p = k = 0;
    if(k == -1) k = n-1;
    reverse(T+p, T+k+1);
    FWD(i,0,n-1)
        if(T[i] > T[i+1]){
            printf("no\n");
            return 0;
        }
    printf("yes %d %d\n", p+1, k+1);
    return 0;
}