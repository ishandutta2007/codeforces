#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;
int a[MAXN][MAXN];

int main(){
    int n;scanf("%d",&n);
    if(n <= 2){puts("-1");return 0;}
    if(n == 3){
        printf("9 4 7\n5 6 8\n1 3 2\n");
        return 0;
    }
    int tot = 0;
    ROF(i,n,3){
        if(i&1) FOR(j,1,n) a[i][j] = ++tot;
        else ROF(j,n,1) a[i][j] = ++tot;
    }
    ROF(i,n,4) a[2][i] = ++tot;
    FOR(i,4,n) a[1][i] = ++tot;
    int N = n*n;
    a[1][1] = N;a[1][2] = N-5;a[1][3] = N-2;
    a[2][1] = N-4;a[2][2] = N-3;a[2][3] = N-1;
    FOR(i,1,n) FOR(j,1,n) printf("%d%c",a[i][j]," \n"[j==n]);
    return 0;
}