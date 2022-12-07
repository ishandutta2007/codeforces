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
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), (a).end())
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int n, q, t, a, r;
int sum;
int M[1010][1010];
char R[1000010];

int main(){
    scanf("%d", &n);
    FWD(i,0,n)
        FWD(j,0,n)
            scanf("%d", &M[i][j]);
    FWD(i,0,n)
        sum = (sum + M[i][i]) % 2;
    scanf("%d", &q);
    FWD(i,0,q){
        scanf("%d", &t);        
        if(t == 3){
            R[r++] = '0' + sum;
        }else{
            scanf("%d", &a);
            sum = 1-sum;
        }
    }
    printf("%s\n", R);
    return 0;
}