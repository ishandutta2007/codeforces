#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
priority_queue<int> Q;
int T[1010];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,m){
        scanf("%d", &T[i]);
        Q.push(T[i]);
    }
    int r = 0;
    FWD(i,0,n){
        int a = Q.top();
        Q.pop();
        r += a;
        if(a-1) Q.push(a-1);
    }
    printf("%d ", r);
    r = 0;
    sort(T, T+m);
    FWD(i,0,m){
        while(n && T[i]){
            r += T[i];
            --n;
            --T[i];
        }
    }
    printf("%d\n", r);
    return 0;
}