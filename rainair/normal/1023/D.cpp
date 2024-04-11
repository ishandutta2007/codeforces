#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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

const int MAXN = 5e5 + 5;

int n,q,a[MAXN],max=INT_MIN,min=INT_MAX;
int L[MAXN],R[MAXN];
std::set<int> S;

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i),max = std::max(max,a[i]),min = std::min(min,a[i]);
    ROF(i,n,1) if(!R[a[i]]) R[a[i]] = i;
    FOR(i,1,n) if(!L[a[i]]) L[a[i]] = i;
    FOR(i,1,n){
        if(!a[i]){
            if(max < q) a[i] = q,max = q;
            else if(!S.empty()) a[i] = *--S.end();
            else a[i] = 1;
        }
        else{
            if(L[a[i]] == i && L[a[i]] < R[a[i]]) S.insert(a[i]);
            if(R[a[i]] == i && L[a[i]] < R[a[i]]) S.erase(a[i]);
            if(!S.empty()) if(a[i] < (*--S.end())){
                puts("NO");
                return 0;
            }
        }
    }
    if(max < q){
        puts("NO");return 0;
    }
    puts("YES");
    FOR(i,1,n) printf("%d ",a[i]);puts("");
    return 0;
}