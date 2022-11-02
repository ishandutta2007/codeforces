#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000 + 5;

double a[MAXN],s[MAXN];
double g2 = std::sqrt(2.0);

int main(){
    int N;double M;
    scanf("%d%lf",&N,&M);
    a[0] = 0;
    a[1] = 2.0*M;
    a[2] = a[1] + M*g2;
    a[3] = a[1] + 2.0*M*g2;
    FOR(i,4,N){
        a[i] = a[i-1] + 2.0*M;
    }
    FOR(i,1,N) s[i] = s[i-1] + a[i];
    double ans = 0;
    FOR(i,1,N) ans += (s[i] + s[N-i+1] - a[1])/N;
    printf("%.10f",ans/(double)N);
    return 0;
}