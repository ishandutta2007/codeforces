#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m, s;
map<int, int> M;
int A[100010];
int R[100010];

int main(){
    scanf("%d %d", &n, &m);
    FWD(i,0,n){
        scanf("%d", &A[i]);
        ++M[A[i]];
    }
    s = M.size();
    FWD(i,0,n){
        R[i] = s;
        if(--M[A[i]] == 0) --s;
    }
    FWD(i,0,m){
        scanf("%d", &n);
        printf("%d\n", R[n-1]);
    }
    return 0;
}