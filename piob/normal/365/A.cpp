#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k, a, r;
bool c[10];

int main(){
    scanf("%d %d", &n, &k);
    FWD(i,0,n){
        scanf("%d", &a);
        FWD(i,0,k+1) c[i] = 0;
        while(a){
            c[a%10] = 1;
            a /= 10;
        }
        if(*min_element(c,c+k+1)) ++r;
    }
    printf("%d\n", r);
    return 0;
}