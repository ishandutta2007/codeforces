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

int n, k;

int main(){
    scanf("%d %d", &n, &k);
    if(n == 1){
        if(k == 0)
            printf("1\n");
        else
            printf("-1\n");
        return 0;
    }
    if(n/2 > k){
        printf("-1\n");
    }else{
        FWD(i,0,n-2-(n&1))
            printf("%d ", 2*k+1+i);
        printf("%d %d", k-n/2+1, (k-n/2+1)*2);
        if(n&1)
            printf(" %d\n", 4*k+5);
        else
            printf("\n");
    }
    return 0;
}