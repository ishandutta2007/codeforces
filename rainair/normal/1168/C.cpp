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

const int MAXN = 3e5 + 5;
const int MAXM = 18;
int n,q;
int a[MAXN];
int nxt[MAXN][MAXM+1],las[MAXM+1];

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,0,MAXM) las[i] = nxt[n+1][i] = n+1;
    ROF(i,n,1){
        FOR(j,0,MAXM){
            if((a[i]>>j)&1) nxt[i][j] = i;
            else{
                nxt[i][j] = n+1;
                FOR(k,0,MAXM){
                    if((a[i]>>k)&1) nxt[i][j] = std::min(nxt[i][j],nxt[las[k]][j]);
                }
            }
        }
        FOR(j,0,MAXM){
            if((a[i]>>j)&1) las[j] = i;
        }
    }
    FOR(i,1,q){
        int x,y;scanf("%d%d",&x,&y);
        bool flag = 0;
        FOR(i,0,MAXM){
            if((a[y]>>i)&1) flag |= (nxt[x][i]<=y);
        }
        puts(flag ? "Shi" : "Fou");
    }
    return 0;
}