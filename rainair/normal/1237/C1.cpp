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

const int MAXN = 1e5 + 5;

struct Node{
    int x,y,z,id;

    bool operator < (const Node &t) const {
        if(x != t.x) return x < t.x;
        if(y != t.y) return y < t.y;
        return z < t.z;
    }
}a[MAXN],b[MAXN];
int n;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].id = i;
    std::sort(a+1,a+n+1);
    int m = 0;
    for(int l = 1,r=0;l <= n;l = r+1){
        r = l;
        while(r+1 <= n && a[l].x == a[r+1].x && a[l].y == a[r+1].y) r++;
        int ps = 0;
        for(ps = l;ps+1<=r;ps+=2) printf("%d %d\n",a[ps].id,a[ps+1].id);
        if(ps <= r) b[++m] = a[ps];
    }
    n=0;
    for(int l=1,r=0;l<=m;l=r+1){
        r = l;
        while(r+1 <= m && b[l].x == b[r+1].x) r++;
        int ps=0;
        for(ps = l;ps+1 <= r;ps += 2) printf("%d %d\n",b[ps].id,b[ps+1].id);
        if(ps <= r) a[++n] = b[ps];
    }
    for(int ps = 1;ps<=n;ps+=2) printf("%d %d\n",a[ps].id,a[ps+1].id);
    return 0;
}