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
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

int f[2][MAXN],n,k,now;
int l,r,q[MAXN],head,tail;

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) f[now][i] = 1e9;f[0][0] = 0;
    while(k--){
        now ^= 1;scanf("%d%d",&l,&r);head = 1;tail = 0;
        FOR(i,0,n) f[now][i] = f[now^1][i];
        FOR(j,0,std::min(n,r)){
            while(head <= tail && f[now^1][j] <= f[now^1][q[tail]]) tail--;
            while(head <= tail && j-q[head]+1 > r-l+1) ++head;
            q[++tail] = j;
            f[now][j] = std::min(f[now][j],f[now^1][q[head]]+2);
        }
        head = 1;tail = 0;
        ROF(j,r,0){
            while(head <= tail && f[now^1][r-j] <= f[now^1][q[tail]]) tail--;
            while(head <= tail && r-j-q[head]+1 > r-l+1) ++head;
            q[++tail] = r-j;
            f[now][j] = std::min(f[now][j],f[now^1][q[head]]+1);
        }
    }
    if(f[now][n] >= 1e9){
        puts("Hungry");return 0;
    }
    puts("Full");printf("%d\n",f[now][n]);
    return 0;
}