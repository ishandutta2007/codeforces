#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <cstring>
#include <stack>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PACKS(a) int a;scanf("%d",&a);++a;while(--a)
#define PII pair<int, int>
#define x first
#define y second
#define INF 1000000
#define ALPHA_SIZE 30
#define MAX_N 1000

using namespace std;

int n, m, r, s, os;
char A[5010];
char B[5010];
int T[5010];

int main(){
    scanf("%s %s", A, B);
    n = strlen(A);
    m = strlen(B);
    r = 0;
    FWD(i,0,n){
        s = 1;
        FWD(j,0,m){
            os = s;
            s = (s + T[j]) % 1000000007;
            if(B[j] == A[i]){
                T[j] = os % 1000000007;
                r = (r + T[j]) % 1000000007;
            }else
                T[j] = 0;
        }
    }
    printf("%d\n", r);
    return 0;
}