#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDD pair<long double, long double>
#define x first
#define y second
#define EPS 1e-9
#define INF 1000000009

using namespace std;

int n;
char L;
char S[100010];
vector<char> V;

int main(){
    scanf("%s", S);
    n = strlen(S);
    reverse(S,S+n);
    L = 0;
    FWD(i,0,n){
        if(S[i] >= L){
            V.push_back(S[i]);
            L = S[i];
        }
    }
    reverse(V.begin(), V.end());
    FE(v,V) printf("%c", *v);
    printf("\n");
    return 0;
}