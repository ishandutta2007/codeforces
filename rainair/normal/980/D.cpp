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

const int MAXN = 5000+5;
const int MAXM = 1e6 + 6;

int prime[MAXM],cnt;
bool p[MAXM];

inline void prework(){
    p[1] = true;
    FOR(i,2,MAXM-1){
        if(!p[i]){
            prime[++cnt] = i;
        }
        for(int j = 1;j <= cnt && i*prime[j] <= MAXM;++j){
            p[i*prime[j]] = true;
            if(!(i%prime[j])) break;
        }
    }
}

int n,a[MAXN],pre[MAXN],ans[MAXN];
std::map<int,int> S;

int main(){
    prework();
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n){
        for(int j = 1;j <= cnt && (prime[j]*prime[j]) <= std::abs(a[i]);++j){
            while(a[i] && !(a[i]%(prime[j]*prime[j]))) a[i] /= prime[j]*prime[j];
            if(a[i] == 0 || a[i] == 1 || a[i] == -1) break;
        }
    }
    FOR(i,1,n){
        pre[i] = S[a[i]];
        S[a[i]] = i;
    }
    FOR(i,1,n){
        int cnt = 0;
        FOR(j,i,n){
            if(a[j] && pre[j] < i) cnt++;
            ans[std::max(1,cnt)]++;
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);puts("");
    return 0;
}