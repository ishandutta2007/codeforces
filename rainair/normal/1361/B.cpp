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
int a[MAXN],n,p;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}
std::map<int,int> S;
inline void Solve(){
    scanf("%d%d",&n,&p);
    FOR(i,1,n) scanf("%d",a+i);S.clear();
    if(p == 1){
        puts(n&1?"1":"0");return;
    }
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    std::vector<int> L,R;
    int sml=0,smr=0,cr = 0;
    bool flag = 1;
    FOR(i,1,n){
        if(flag){
            L.pb(a[i]);
            flag = 0;
        }
        else{
            R.pb(a[i]);S[a[i]]++;
            while(!S.empty() && S[R.back()] == p){
                int t = R.back();
                FOR(i,1,p) R.pop_back();
                S.erase(t);
                R.pb(t+1);S[t+1]++;
            }
            while(!L.empty() && !R.empty() && L.back() == R.back()) S[R.back()]--,L.pop_back(),R.pop_back(),flag = 1;
        }
    }
    int ans = 0;
    for(auto x:L) (ans += qpow(p,x)) %= ha;
    for(auto x:R) (ans += ha-qpow(p,x)) %= ha;
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}