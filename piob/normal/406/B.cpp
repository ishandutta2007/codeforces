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

bool taken[1000010];
int n, c;
vector<int> Y;
vector<int> F;

int main(){
    scanf("%d", &n);
    FWD(i,0,n){
        int a;
        scanf("%d", &a);
        taken[a] = 1;
    }
    FWD(i,1,500001){
        if(taken[i] != taken[1000001-i]){
            if(taken[i])
                Y.push_back(1000001-i);
            else
                Y.push_back(i);
        }else{
            if(taken[i])
                ++c;
            else
                F.push_back(i);
        }
    }
    FWD(i,0,c){
        Y.push_back(F[i]);
        Y.push_back(1000001-F[i]);
    }
    printf("%d\n", (int)Y.size());
    FWD(i,0,(int)Y.size())
        printf("%d ", Y[i]);
    printf("\n");
    return 0;
}