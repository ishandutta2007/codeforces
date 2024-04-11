#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

int n;
PII T[100010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d %d", &T[i].x, &T[i].y);
    sort(T, T+n);
    FWD(i,0,n-1)
        if(T[i].x < T[i+1].x && T[i].y > T[i+1].y){
            printf("Happy Alex\n");
            return 0;
        }
    printf("Poor Alex\n");
    return 0;
}