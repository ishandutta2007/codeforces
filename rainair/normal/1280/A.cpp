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

const int MAXN = 1e6 + 5;
const int ha = 1e9 + 7;
int n,x;
char str[MAXN];

inline void Solve(){
    scanf("%d",&x);FOR(i,0,x) str[i] = 0;
    scanf("%s",str+1);n = strlen(str+1);
    int ans = n;
    FOR(i,1,x){
        int tn = n;
        FOR(j,1,str[i]-'1'){
            int ll = i+1;
            while(n <= x && ll <= tn) str[++n] = str[ll],ll++;
        }
        (ans += 1ll*(str[i]-'1')*(ans+ha-i)%ha) %= ha;
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}