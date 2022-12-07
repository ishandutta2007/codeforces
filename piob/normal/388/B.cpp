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

//inline LL gcd(LL a, LL b){ while(a&&b) a>b?a%=b:b%=a; return a+b; }

int k, n;
vector<int> last;
int M[2010][2010];

int main(){
    scanf("%d", &k);
    int w = 0;
    n = 2;
    while(k){
        if(k%4){
            //printf("%d %d\n", w, k%4);
            last.clear();
            FWD(i,0,k%4){
                ++n;
                //printf("%d - %d\n", 1, n);
                M[1][n] = M[n][1] = 1;
                last.pb(n);
            }
            FWD(i,0,w){
                FWD(r,0,4){
                    ++n;
                    for(int u : last){
                        //printf("%d - %d\n", u, n);
                        M[u][n] = M[n][u] = 1;
                    }
                }
                last.clear();
                last.pb(n-3);
                last.pb(n-2);
                last.pb(n-1);
                last.pb(n);
            }
            FWD(i,w,20){
                ++n;
                for(int u : last){
                    //printf("%d - %d\n", u, n);
                    M[u][n] = M[n][u] = 1;
                }
                last.clear();
                last.pb(n);
            }
            for(int u : last){
                M[u][2] = M[2][u] = 1;
                //printf("%d - %d\n", u, 2);
            }
        }
        k /= 4;
        ++w;
    }
    printf("%d\n", n);
    FWD(i,1,n+1){
        FWD(j,1,n+1)
            printf("%c", M[i][j]?'Y':'N');
        printf("\n");
    }
    return 0;
}