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

int n;

inline bool work(int l,int r){
    if(l >= r) return 1;
    int mid = (l + r) >> 1;
    if((r-l+1)&1) return ((mid&1) == (r&1))&work(l,mid-1)&work(mid+1,r);
    else{
        if((r&1) == (mid&1)) return work(l,mid-1)&work(mid+1,r);
        else return work(l,mid)&work(mid+2,r);
    }
}

int main(){
    scanf("%d",&n);
    printf("%d\n",work(1,n));
    return 0;
}