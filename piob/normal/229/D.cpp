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

int n;
int P[5010];
int H[5010];
int S[5010];
int R[5010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n) scanf("%d", &H[i]);
    S[0] = H[0];
    R[0] = 0;
    P[0] = H[0];
    FWD(i,1,n){
        P[i] = P[i-1] + H[i];
        S[i] = P[i];
        R[i] = i;
        FWD(j,0,i){
            if(P[i] - P[j] >= S[j] && P[i] - P[j] < S[i]){
                S[i] = P[i] - P[j];
                R[i] = R[j] + i - j - 1;
            }
        }
    }
    printf("%d\n", R[n-1]);
    return 0;
}