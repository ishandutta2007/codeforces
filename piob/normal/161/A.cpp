#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <limits>
#define FWD(a,b,c) for(int a=(b); a<(c); a++)
#define BCK(a,b,c) for(int a=(b); a>(c); a--)
#define FE(a,b) for(typeof(b.end()) a=b.begin(); a!=b.end(); a++)
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) erase(unique(a.begin(), a.end()), a.end())
#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define PDD pair<double, double>
#define x first
#define y second
#define PACKS(a) int a; scanf("%d", &a); a++; while(--a)

//#define DEBUG
#ifdef DEBUG
    #define debug printf
#else
    #define debug
#endif

using namespace std;

int n, m, x, y, a;
vector<int> A, B;
vector<PII> R;

int main(){
    scanf("%d %d %d %d", &n, &m, &x, &y);
    FWD(i,0,n){
        scanf("%d", &a);
        A.push_back(a);
    }
    FWD(i,0,m){
        scanf("%d", &a);
        B.push_back(a);
    }
    //printf("read\n");
    while(!A.empty() && !B.empty()){
        if(A.back() - x <= B.back() && B.back() <= A.back() + y){
            R.push_back(PII(A.size(), B.size()));
            A.pop_back();
            B.pop_back();
        }else{
            if(A.back() - x > B.back())
                A.pop_back();
            else
                B.pop_back();
        }
    }
    printf("%d\n", (int)R.size());
    FE(r,R)
        printf("%d %d\n", r->x, r->y);
    return 0;
}