#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;

map<int, int> P;

int find(int a){
    if(P.find(a) == P.end()) return P[a] = a;
    return a == P[a] ? a : P[a] = find(P[a]);
}

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        a = find(a);
        printf("%d ", a);
        P[a] = a+1;
    }
    printf("\n");
    return 0;
}