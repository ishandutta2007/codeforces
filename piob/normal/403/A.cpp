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

//int dx[] = {0,0,-1,1}; //,1,1,-1,-1}; //,0};
//int dy[] = {-1,1,0,0}; //,1,-1,1,-1}; //,0};

int n, p;
bool u[30][30];

bool used(int a, int b){
    return u[a][b];
}

void setu(int a, int b){
    u[a][b] = u[b][a] = 1;
}

int main(){
    int z; scanf("%d", &z);
    while(z--){
        scanf("%d %d", &n, &p);
        FWD(i,0,n) FWD(j,0,n) u[i][j] = 0;
        FWD(i,0,n){
            setu(i,(i+1)%n);
            setu(i,(i+2)%n);
            printf("%d %d\n%d %d\n", i+1, (i+1)%n+1, i+1, (i+2)%n+1);
        }
        FWD(i,0,n)
            FWD(j,i+1,n)
                if(p && !used(i,j)){
                    --p;
                    setu(i,j);
                    printf("%d %d\n", i+1, j+1);
                }
    }
    return 0;
}