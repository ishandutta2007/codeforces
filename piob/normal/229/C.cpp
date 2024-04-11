#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define pb push_back
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int n, m, a, b;
long long r, k;
long long D[1000010];

int main(){
    scanf("%d %d", &n, &m);
    r = 0;
    FWD(i,0,m){
        scanf("%d %d", &a, &b);
        ++D[a];
        ++D[b];
    }
    k = n;
    FWD(i,1,n+1){
        r += D[i] * (k-1LL-D[i]);
    }
    cout <<  (k * (k-1LL) * (k-2LL) / 3LL - r)/2LL << endl;
    return 0;
}