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

inline P query(int l,int r){
    printf("? %d %d\n",l,r);std::fflush(stdout);
    int x,f;scanf("%d%d",&x,&f);
    return MP(x,f);
}

const int MAXN = 5e5 + 5;
int a[MAXN];

inline void work(int l,int r){
    if(l > r) return;
    P t = query(l,r);
    int L = r-t.se+1,R = l+t.se-1;
    if(L <= R){
        FOR(i,L,R) a[i] = t.fi;
        work(l,L-1);work(R+1,r);
    }
    else{
        int mid = (l + r) >> 1;
        work(l,mid);work(mid+1,r);
    }
}

int main(){
    int n;scanf("%d",&n);
    work(1,n);
    printf("! ");FOR(i,1,n) printf("%d ",a[i]);puts("");std::fflush(stdout);
    return 0;
}