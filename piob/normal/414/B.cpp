#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int R[2010][2010];

const int mod = 1000000007;

int n, k;

int main(){
    R[0][1] = 1;
    scanf("%d %d", &n, &k);
    FWD(i,1,k+1){
        FWD(w,1,n+1)
            FWD(m,1,n+1){
                if(w*m > n)
                    break;
                R[i][w*m] = (R[i][w*m] + R[i-1][w]) % mod;
            }
    }
    int res = 0;
    FWD(w,1,n+1) res = (res + R[k][w]) % mod;
    printf("%d\n", res);
    return 0;
}