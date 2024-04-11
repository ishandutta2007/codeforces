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

const int MAXN = 2000+5;

int W,n;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int num[MAXN],w[MAXN],v[MAXN]; // num w  v 
int f[MAXN];

int main(){
    scanf("%d%d%d%d",&W,&n,c+1,d+1);
    n++;num[1] = W/c[1];w[1] = c[1];v[1] = d[1];
    FOR(i,2,n){
        scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
        num[i] = a[i]/b[i];w[i] = c[i];v[i] = d[i];
    }
    FOR(i,1,n){
        FOR(j,1,num[i]){
            ROF(k,W,w[i]){
                f[k] = std::max(f[k],f[k-w[i]]+v[i]);
            }
        }
    }
    printf("%d\n",f[W]);
    return 0;
}