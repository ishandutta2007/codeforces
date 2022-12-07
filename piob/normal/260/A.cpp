#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int a, b, n, r;
vector<int> d;

int main(){
    scanf("%d %d %d", &a, &b, &n);
    r = a;
    FWD(i,0,n){
        int x = -1;
        FWD(y,0,10)
            if((r*10+y)%b==0)
                x = y;
        if(x == -1){
            printf("-1\n");
            return 0;
        }
        r = 0;
        d.push_back(x);
    }
    printf("%d", a);
    for(int x : d)
        printf("%d", x);
    printf("\n");
    return 0;
}