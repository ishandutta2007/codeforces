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

const int MAXN = 5e5 + 5;
const int MAXM = 19;
int a[MAXN];
int pc[MAXN],n,mx[MAXM+1][MAXN];

inline int calc(int l,int r){
    int c = pc[r-l+1];
    return std::max(mx[c][l],mx[c][r-(1<<c)+1]);
}

int main(){
    int _mx=-1e9,_mn=1e9;
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    scanf("%d",&n);int _ = n;
    FOR(i,1,n) scanf("%d",a+i),_mx = std::max(_mx,a[i]),_mn = std::min(_mn,a[i]);
    if(_mn >= (_mx+1)/2){
        FOR(i,1,n) printf("%d ",-1);
        puts("");return 0;
    }
    FOR(j,1,4) FOR(i,1,_) a[++n] = a[i];
    FOR(i,1,n) mx[0][i] = a[i];
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1))<MAXN;++j){
            mx[i][j] = std::max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
        }
    }
    for(int l = 1,r=1;l <= _;l++){
        while(a[r] >= (calc(l,r)+1)/2) r++;
        printf("%d ",r-l);
    }
    puts("");
    return 0;
}