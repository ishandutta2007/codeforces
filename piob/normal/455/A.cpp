#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n;
int C[100010];
LL R[100010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        ++C[a];
    }
    R[1] = C[1];
    FWD(i,2,100010){
        R[i] = max(R[i-1], R[i-2] + (LL)i*C[i]);
    }
    cout << R[100009] << endl;
    return 0;
}