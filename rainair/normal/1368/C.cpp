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

const int MAXN = 500 + 5;
std::vector<P> ans;

int main(){
    int n;scanf("%d",&n);
    FOR(i,0,n){
        ans.pb(MP(i,i));ans.pb(MP(i+1,i));ans.pb(MP(i,i+1));
    }
    ans.pb(MP(n+1,n+1));
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}