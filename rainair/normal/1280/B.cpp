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

const int MAXN = 60+5;
int a[MAXN][MAXN];
int n,m;
char str[MAXN];
int l[MAXN],r[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&m);
    CLR(l,0);CLR(r,0);
    int sm = 0;
    FOR(i,1,n){
        scanf("%s",str+1);
        FOR(j,1,m) a[i][j] = (str[j] == 'A'),sm += a[i][j],l[i] += a[i][j],r[j] += a[i][j];
    }
    if(sm == n*m){
        puts("0");return;
    }
    if(sm == 0){
        puts("MORTAL");return;
    }
    if(l[1] == m || l[n] == m || r[1] == n || r[m] == n){
        puts("1");return;
    }
    if(a[1][1] || a[1][m] || a[n][1] || a[n][m]){
        puts("2");return;
    }
    if(*std::max_element(l+1,l+n+1) == m || *std::max_element(r+1,r+m+1) == n){
        puts("2");return;
    }
    if(l[1] || l[n] || r[1] || r[m]){
        puts("3");return;
    }
    puts("4");return;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}