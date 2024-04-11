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

const int MAXN = 2e5 + 5;
int a[MAXN],n;

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i);
    bool flag = 1;
    FOR(i,1,n) flag &= (a[i]==i);
    if(flag){
        puts("0");
        return;
    }
    int l = 1;
    while(l <= n && a[l] == l) l++;--l;
    int r = n;
    while(r && a[r]==r) r--;++r;
    FOR(i,l+1,r-1){
        if(a[i] == i){
            puts("2");
            return;
        }
    }
    puts("1");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}