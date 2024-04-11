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
int n;char A[MAXN],B[MAXN];

inline void Solve(){
    scanf("%d",&n);
    scanf("%s",A+1);scanf("%s",B+1);
    FOR(i,1,n){
        if(A[i] > B[i]){
            puts("-1");
            return;
        }
    }
    int ans = 0;
    FOR(i,0,19){
        int mn = 1e9;
        FOR(j,1,n) if(A[j]-'a' == i && A[j] != B[j]) mn = std::min(mn,B[j]-'a');
        if(mn != 1e9) ans++;
        FOR(j,1,n) if(A[j]-'a' == i && A[j] != B[j]) A[j] = mn+'a';
//        DEBUG(i);DEBUG(mn);
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}